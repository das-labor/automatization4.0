#include <avr/io.h>

#include "config.h"
#include "channel.h"
#include "dimmer.h"

volatile uint8_t channels_active[NUM_TOTAL_CHANNELS];

void channel_init()
{
	for (uint8_t x = 0; x < NUM_TOTAL_CHANNELS; x++)
	{
		channels_active[x] = 0;
	}
}

void enable_channel(uint8_t channel, uint8_t enable)
{
	if (channel < NUM_TOTAL_CHANNELS)
	{
		channels_active[channel] = enable;
		if (channel < NUM_DIMMER_CHANNELS)
		{
			if (enable) {
				if (get_dimmer_max(channel))
				{
					switch (channel) {
						case 0: PORTA |= _BV(PA6); break;
						case 1: PORTA |= _BV(PA7); break;
					}
				}
			}
			else
				switch (channel) {
					case 0: PORTA &= ~_BV(PA6); break;
					case 1: PORTA &= ~_BV(PA7); break;
				}
		}
		else
		{
			// TODO: I2C SWITCH
		}
	}
}

uint8_t get_channel_active(uint8_t channel)
{
	if (channel >= NUM_TOTAL_CHANNELS)
		return 0;

	return channels_active[channel];
}

uint16_t get_channel_status() {
	uint16_t retVal = 0;
	for (uint8_t i = 0; i < NUM_TOTAL_CHANNELS; i++)
	{
		retVal |= (channels_active[i] << i);
	}
	return retVal;
}