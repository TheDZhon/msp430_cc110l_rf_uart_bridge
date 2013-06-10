/**
 ** RXTX device. Provides UART <-> RF Bridge.
 **
 ** CF: 868 MHz, MSK, 250kbps
 ** UART: 9600bps, 8bit
 **
 ** LEGAL NOTICE:
 **
 ** This file is licensed under BSD. It is originally copyright Texas Instruments,
 ** but has been adapted by Lars Kristian Roland
 **
 ** Latest changes by Eugene Mamin, <TheDZhon@gmail.com> (c) 2013
 **
 ** TODO:
 ** 1) Add CRC check
 ** 2) Add ACK packets
 **/

#include "../ti/include.h"
#include "../hal/uart.h"

#include "utils.h"
#include "common_defs.h"

// TX Buffer for outgoing data
char txBuffer[NET_BUF_LEN];
// RX buffer for ingoing data
char rxBuffer[NET_BUF_LEN];

// Last position in TX buffer
unsigned last_tx_pos = PKT_DATA_OFFSET;

// Sync startup cc110l booster with Launchpad.
inline void wait_cc110l () { __delay_cycles(5000); }

int main ()
{
	WDTCTL = WDTPW + WDTHOLD;
	wait_cc110l ();

	txBuffer [PKT_ADDR_OFFSET] = DATA_RF_ADDR;

	uartInit ();
	RF_init();

	__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled
}

/**
 ** TI USCI (UART) RX interruptions handler.
 **/
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR_HOOK (void) {
	// Capture data from UART FIFO
	txBuffer [last_tx_pos] = UCA0RXBUF;

	// Check for data end
	if (txBuffer[last_tx_pos] != UART_TERM_SYMB) {
		++last_tx_pos;
		return;
	}

	// Fill packet length
	txBuffer [PKT_SIZE_OFFSET] = last_tx_pos - PKT_ADDR_OFFSET; // One extra byte for addr
	// Send packet over RF
	RFSendPacket (txBuffer, txBuffer [PKT_SIZE_OFFSET] + 1); // One extra byte for size

#ifdef RF_TX_DEBUG
	// Terminate packet string
	txBuffer [last_tx_pos + 1] = '\0';
	// Write into UART
	puts (txBuffer + PKT_DATA_OFFSET);
#endif

	// Reset position
	last_tx_pos = PKT_DATA_OFFSET;
}

/**
 ** The ISR assumes the interrupt came from GDO0. GDO0 fires indicating that
 **/
#pragma vector=PORT2_VECTOR
__interrupt void Port2_ISR (void)
{
	// We are interested in interruptions only from GDO0
	if(TI_CC_GDO0_PxIFG & TI_CC_GDO0_PIN)
	{
		char status[2];
		char len=NET_BUF_LEN;

		if (RFReceivePacket(rxBuffer, &len, status))
		{
			rxBuffer [len] = '\0';
			puts (rxBuffer + PKT_DATA_OFFSET - 1);
		}
	}

	TI_CC_GDO0_PxIFG &= ~TI_CC_GDO0_PIN;      // After pkt RX, this flag is set.
}
