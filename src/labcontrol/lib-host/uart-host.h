#ifndef UART_HOST_H
#define UART_HOST_H

/**
 * UART Library
 *
 * #define UART_BAUD_RATE 19200
 *
 */

#include "config.h"

#include <sys/select.h>

extern void uart_init(char *sport, char *baudrate);
extern void uart_close(void);

extern void uart_putc(char c);
extern void uart_putstr(char *str);

extern char uart_getc(void);
extern char uart_getc_nb(char *c);		// returns 1 on success

/* UART-Host specific */
extern int uart_fd;
#endif
