/**
 ** Copyright (c) 10.06.2013, Eugene Mamin
 ** All rights reserved.
 ** Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are met:
 **
 ** 1. Redistributions of source code must retain the above copyright notice, this
 ** list of conditions and the following disclaimer.
 ** 2. Redistributions in binary form must reproduce the above copyright notice,
 ** this list of conditions and the following disclaimer in the documentation
 ** and/or other materials provided with the distribution.
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 ** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 ** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 ** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ** The views and conclusions contained in the software and documentation are those
 ** of the authors and should not be interpreted as representing official policies,
 ** either expressed or implied, of the FreeBSD Project
 **/

#ifndef COMMON_DEFS_H_
#define COMMON_DEFS_H_

// Network buffer message length
#define NET_BUF_LEN 	60
// UART terminator symbol
#define UART_TERM_SYMB	'|'

// Size offset in RF Packet structure
#define PKT_SIZE_OFFSET      0
// Addr offset in RF Packet structure
#define PKT_ADDR_OFFSET      1
// Data offset in RF Packet structure
#define PKT_DATA_OFFSET      2

// Data RF address
#define DATA_RF_ADDR    0x01

#endif /* COMMON_DEFS_H_ */
