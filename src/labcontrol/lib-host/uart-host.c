#include "config.h"

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "debug.h"

int uart_fd;

// keeps uart port config
static struct termios old_options;

static unsigned int baud_to_value(speed_t baud)
{
	switch (baud) {
		case B0:  return 0;
		case B50: return 50;
		case B75: return 75;
		case B110: return 110;
		case B134: return 134;
		case B150: return 150;
		case B200: return 200;
		case B300: return 300;
		case B600: return 600;
		case B1200: return 1200;
		case B1800: return 1800;
		case B2400: return 2400;
		case B4800: return 4800;
		case B9600: return 9600;
		case B19200: return 19200;
		case B38400: return 38400;
		case B57600: return 57600;
		case B115200: return 115200;
		case B230400: return 230400;
		case B460800: return 460800;
		case B500000: return 500000;
		case B576000: return 576000;
		case B921600: return 921600;
		case B1000000: return 1000000;
		case B1152000: return 1152000;
		case B1500000: return 1500000;
		case B2000000: return 2000000;
		case B2500000: return 2500000;
		case B3000000: return 3000000;
		case B3500000: return 3500000;
		case B4000000: return 4000000;
		default: break;
	}

	return 0;
}

static speed_t value_to_baud(unsigned int value)
{
	switch (value) {
		case 0:		return B0;		/* hang up */
		case 50:	return B50;
		case 75:	return B75;
		case 110:	return B110;
		case 134:	return B134;
		case 150:	return B150;
		case 200:	return B200;
		case 300:	return B300;
		case 600:	return B600;
		case 1200:	return B1200;
		case 1800:	return B1800;
		case 2400:	return B2400;
		case 4800:	return B4800;
		case 9600:	return B9600;
		case 19200:	return B19200;
		case 38400:	return B38400;
		case 57600:	return B57600;
		case 115200:	return B115200;
		case 230400:	return B230400;
		case 460800:	return B460800;
		case 500000:	return B500000;
		case 576000:	return B576000;
		case 921600:	return B921600;
		case 1000000:	return B1000000;
		case 1152000:	return B1152000;
		case 1500000:	return B1500000;
		case 2000000:	return B2000000;
		case 2500000:	return B2500000;
		case 3000000:	return B3000000;
		case 3500000:	return B3500000;
		case 4000000:	return B4000000;
		default:	break;
	}

	return 0;
}

void uart_init(char *sport, char *baudrate)
{
	struct termios options;
	speed_t baud;

	if (baudrate) {
		baud = value_to_baud(atoi(baudrate));
		printf("bautrate: %s\n", baudrate);
	}
	else
		baud = DEFAULT_UART_BAUD_RATE;
	if (!baud) {
		debug_perror(0, "invalid baudrate: %i", baud_to_value(baud));
		exit(EXIT_FAILURE);
	}
	
	int rc;

	/**
	 * O_NOCTTY -- ttyS is not our controlling terminal:
	 *   kernel, do not do fancy stuff! We're not getty, stupid!
	 *
	 * O_NDELAY -- don't block for DTR, we're not talking to a modem
	 */
	uart_fd = open(sport, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
	if (uart_fd < 0) {
		debug_perror(0, "Error opening serial port %s", sport);
		exit(EXIT_FAILURE);
	}

	// get serial options
	tcgetattr(uart_fd, &old_options);
	// clear struct
	bzero(&options, sizeof(options));

	// both needed because cfsetspeed is not available on Windows.
	cfsetispeed(&options, baud);
	cfsetospeed(&options, baud);

	options.c_cflag |= (CS8 | CLOCAL | CREAD);
	options.c_iflag |= IGNBRK;
	options.c_lflag = 0;
	options.c_cc[VTIME] = 0; // inter-character timer unused
	options.c_cc[VMIN]  = 0; // blocking read until 0 chars received
	cfmakeraw(&options);
	tcflush(uart_fd, TCIFLUSH);
	rc = tcsetattr(uart_fd, TCSANOW, &options);

	if (rc == -1) {
		debug_perror(0, "Error setting serial options");
		close(uart_fd);
		exit(EXIT_FAILURE);
	}
	else
		debug(1, "Serial CAN communication established at %lu Baud", baud_to_value(cfgetospeed(&options)));
}

void uart_close(void)
{
	close(uart_fd);
	tcsetattr(uart_fd, TCSANOW, &old_options);
}

void uart_putc(char c)
{
	ssize_t ret = write(uart_fd, &c, 1);
	if (ret != 1)
	{
		debug(0, "uart_putc faild: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void uart_putstr(char *str)
{
	while (*str) {
		uart_putc(*str++);
	}
}

unsigned char uart_getc_nb(char *c)
{
	int ret;

	ret = read(uart_fd, c, 1);

	if (ret <= 0) {
		debug(10, "uart char: %d\n", c);
		return 0;
	}
	return 1;
}

char uart_getc(void)
{
	char c;
	int ret;
	fd_set rset;

	FD_ZERO(&rset);
	FD_SET(uart_fd, &rset);

	ret = select(uart_fd + 1, &rset, (fd_set *) NULL, (fd_set *) NULL, NULL);
	debug_assert(ret >= 0, "uart-host.c: select failed");

	uart_getc_nb(&c);

	return c;
}
