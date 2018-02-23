#ifndef _DIMMER_H
#define _DIMMER_H

extern uint8_t dim_vals_8bit[2];

extern void dimmer_init(void);
extern void set_dimmer(uint8_t channel, uint8_t bright);
extern uint8_t get_dimmer_max(uint8_t channel);

#endif // _DIMMER_H

