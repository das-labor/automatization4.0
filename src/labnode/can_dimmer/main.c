#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "config.h"
#include "channel.h"
#include "dimmer.h"
#include "can/can.h"
#include "can_handler.h"
#include "can/spi.h"
#include "can/lap.h"
#include "pcf8574/pcf8574.h"

static void init(void)
{
	DDRB |= _BV(PB0); // LED out

	spi_init(); // initialize spi port
	can_read_addr();
	can_init(); // initialize can communication

	wdt_enable(WDTO_250MS);

	channel_init();
	dimmer_init();

	//init pcf8574
	pcf8574_init();
	pcf8574_setoutput(0, 0);

	//enable all channels, set maximum brightness
	set_dimmer(0, 127);
	set_dimmer(1, 127);
	can_send_status();

	sei(); // enable global interrupts
}

int main(void)
{
	init(); //system initialization

	//the main loop continuously handles can messages
	while (1)
	{
		can_handler();
		wdt_reset();
	}
}

