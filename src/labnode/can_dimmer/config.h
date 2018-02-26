#ifndef _CONFIG_H
#define _CONFIG_H

// SPI
#define MCP_CS_BIT    PB4
#define MCP_CS_PORT   PORTB

#define SPI_REG_PIN_MCP_INT PINB
#define SPI_PIN_MCP_INT     PB2

#define CAN_INTERRUPT
#define CAN_INT_NOBLOCK

#define ENABLE_CAN_INT()  GICR |= _BV(INT2)
#define DISABLE_CAN_INT() GICR &= ~_BV(INT2)
#define SETUP_CAN_INT()   MCUCSR &= ~_BV(ISC2)
#define MCP_INT_VEC       INT2_vect

#define CAN_TX_BUFFER_SIZE 4
#define CAN_RX_BUFFER_SIZE 4

#define F_MCP F_CPU

#define NUM_DIMMER_CHANNELS 2
#define NUM_SWITCH_CHANNELS 8

#define NUM_TOTAL_CHANNELS (NUM_DIMMER_CHANNELS + NUM_SWITCH_CHANNELS)

#define OPTIMISED_LAP

#endif // ifndef CONFIG_H

