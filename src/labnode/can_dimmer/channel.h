#ifndef _CHANNEL_H
#define _CHANNEL_H

extern void channel_init(void);
extern uint16_t get_channel_status(void);
extern uint8_t get_channel_active(uint8_t channel);
extern void enable_channel(uint8_t channel, uint8_t enable);

#endif // _CHANNEL_H

