#ifndef _MCP2551REGS_H
#define _MCP2551REGS_H

// Registers
enum {
	RXF0SIDH	= 0x00,
	RXF0SIDL	= 0x01,
	RXF0EID8	= 0x02,
	RXF0EID0	= 0x03,
	RXF1SIDH	= 0x04,
	RXF1SIDL	= 0x05,
	RXF1EID8	= 0x06,
	RXF1EID0	= 0x07,
	RXF2SIDH	= 0x08,
	RXF2SIDL	= 0x09,
	RXF2EID8	= 0x0a,
	RXF2EID0	= 0x0b,
	BFPCTRL		= 0x0c,
	TXRTSCTRL	= 0x0d,
	CANSTAT		= 0x0e,
	CANCTRL		= 0x0f,
	RXF3SIDH	= 0x10,
	RXF3SIDL	= 0x11,
	RXF3EID8	= 0x12,
	RXF3EID0	= 0x13,
	RXF4SIDH	= 0x14,
	RXF4SIDL	= 0x15,
	RXF4EID8	= 0x16,
	RXF4EID0	= 0x17,
	RXF5SIDH	= 0x18,
	RXF5SIDL	= 0x19,
	RXF5EID8	= 0x1a,
	RXF5EID0	= 0x1b,
	TEC			= 0x1c,	// TRANSMIT ERROR COUNTER
	REC			= 0x1d,	// RECEIVER ERROR COUNTER
	RXM0SIDH	= 0x20,
	RXM0SIDL	= 0x21,
	RXM0EID8	= 0x22,
	RXM0EID0	= 0x23,
	RXM1SIDH	= 0x24,
	RXM1SIDL	= 0x25,
	RXM1EID8	= 0x26,
	RXM1EID0	= 0x27,
	CNF3		= 0x28,
	CNF2		= 0x29,
	CNF1		= 0x2a,
	CANINTE		= 0x2b,		// INTERRUPT ENABLE
	CANINTF		= 0x2c,		// INTERRUPT FLAG
	EFLG		= 0x2d,		// ERROR FLAG
	TXB0CTRL	= 0x30,
	TXB0SIDH	= 0x31,
	TXB0SIDL	= 0x32,
	TXB0EID8	= 0x33,
	TXB0EID0	= 0x34,
	TXB0DLC		= 0x35,
	TXB0D0		= 0x36,
	RXB0CTRL	= 0x60,
	RXB0SIDH	= 0x61,
	RXB0SIDL	= 0x62,
	RXB0EID8L	= 0x63,
	RXB0EID0L	= 0x64,
	RXB0DLCL	= 0x65,
	RXB0D0L		= 0x66
} mcp2515_regs_t;


// RXnBF PIN CONTROL AND STATUS
enum {
	B0BFM	= 0x00,
	B1BFM	= 0x01,
	B0BFE	= 0x02,
	B1BFE	= 0x03,
	B0BFS	= 0x04,
	B1BFS	= 0x05
} mcp2515_BFPCTRL_t;

enum {
	B0RTSM	= 0x00,
	B1RTSM	= 0x01,
	B2RTSM	= 0x02,
	B0RTS	= 0x03,
	B1RTS	= 0x04,
	B2RTS	= 0x05
} mcp2515_TXRTSCTRL_t;

//CANSTAT
enum {

	ICOD0	= 0x01,
	ICOD1	= 0x02,
	ICOD2	= 0x03,

	OPMOD0	= 0x05,
	OPMOD1	= 0x06,
	OPMOD2	= 0x07
} mcp2515_CANSTAT_t;

// CAN CONTROL REGISTER
enum {
	CLKPRE0	= 0x00,
	CLKPRE1	= 0x01,
	CLKEN	= 0x02,
	OSM		= 0x03,
	ABAT	= 0x04,
	REQOP0	= 0x05,
	REQOP1	= 0x06,
	REQOP2	= 0x07
} mcp2515_CANCTRL_t;


// CONFIGURATION 1
// ###############
enum {
	PHSEG20	= 0x00,
	PHSEG21	= 0x01,
	PHSEG22	= 0x02,



	WAKFIL	= 0x06,
	SOF		= 0x07
} mcp2515_CNF3_t;

enum {
	PRSEG0	= 0x00,
	PRSEG1	= 0x01,
	PRSEG2	= 0x02,
	PHSEG10	= 0x03,
	PHSEG11	= 0x04,
	PHSEG12	= 0x05,
	SAM		= 0x06,
	BTLMODE	= 0x07
} mcp2515_CNF2_t;

enum {
	BRP0	= 0x00,
	BRP1	= 0x01,
	BRP2	= 0x02,
	BRP3	= 0x03,
	BRP4	= 0x04,
	BRP5	= 0x05,
	SJW0	= 0x06,
	SJW1	= 0x07
} mcp2515_CNF1_t;
// ###############


// INTERRUPT ENABLE
enum {
	RX0IE	= 0x00,
	RX1IE	= 0x01,
	TX0IE	= 0x02,
	TX1IE	= 0x03,
	TX2IE	= 0x04,
	ERRIE	= 0x05,
	WAKIE	= 0x06,
	MERRE	= 0x07
} mcp2515_CANINTE_t;

// INTERRUPT FLAG
enum {
	RX0IF	= 0x00,
	RX1IF	= 0x01,
	TX0IF	= 0x02,
	TX1IF	= 0x03,
	TX2IF	= 0x04,
	ERRIF	= 0x05,
	WAKIF	= 0x06,
	MERRF	= 0x07
} mcp2515_CANINTF_t;

// READ STATUS
enum {
	CANINTF_RX0IF	= 0x00,
	CANINTFL_RX1IF	= 0x01,
	TXB0CNTRL_TXREQ	= 0x02,
	CANINTF_TX0IF	= 0x03,
	TXB1CNTRL_TXREQ	= 0x04,
	CANINTF_TX1IF	= 0x05,
	TXB2CNTRL_TXREQ	= 0x06,
	CANINTF_TX2IF	= 0x07
} mcp2515_READ_STATUS_FLAGS_t;

// EFLG
enum {
	EWARN	= 0x00,
	RXWAR	= 0x01,
	TXWAR	= 0x02,
	RXEP	= 0x03,
	TXEP	= 0x04,
	TXBO	= 0x05,
	RX0OVR	= 0x06,
	RX1OVR	= 0x07
} mcp2515_EFLG_t;

// TRANSMIT BUFFER n CONTROL REGISTER
enum {
	TXP0	= 0x00,
	TXP1	= 0x01,

	TXREQ	= 0x03,
	TXERR	= 0x04,
	MLOA	= 0x05,
	ABTF	= 0x06

} mcp2515_TXBnCTRL_t;

// RECEIVE BUFFER 0 CONTROL
enum {
	FILHIT0	= 0x00,
	BUKT1	= 0x01,
	BUKT	= 0x02,
	RXRTR	= 0x03,

	RXM0	= 0x05,
	RXM1	= 0x06

} mcp2515_RXB0CTRL_t;

// RECEIVE BUFFER 1 CONTROL
enum {
	// FILHIT0 same as RXB0
	FILHIT1	= 0x01,
	FILHIT2	= 0x02,
	// RXRTR same as RXB0

	// RXM0 same as RXB0
	// RXM1 same as RXB0

} mcp2515_RXB1CTRL_t;

// Extended Identifier Enable bit
#define EXIDE 3


enum {
	TXB0	= 0x00,
	TXB1	= 0x01,
	TXB2	= 0x02
} mcp2515_RTSCMD_t;

// Command Bytes
enum {
	RESET			= 0xC0,
	READ			= 0x03,
	READ_RX_BUFFER	= 0x90,
	WRITE			= 0x02,
	LOAD_TX_BUFFER	= 0x40,
	RTS				= 0x80,
	READ_STATUS		= 0xA0,
	RX_STATUS		= 0xB0,
	BIT_MODIFY		= 0x05
} mcp2515_cmd_t;

// Controller Modes
typedef enum {
	NORMAL		= 0x00,
	MODE_SLEEP	= 0x01,
	LOOPBACK	= 0x02,
	LISTENONLY	= 0x03,
	CONFIG		= 0x04
} mcp2515_mode_t;

#endif //_MCP2551REGS_H