#include <stdlib.h>
#include <string.h>
#include "can-encap.h"

void can_message_raw_from_rs232can_msg(can_message_raw *cmsg, rs232can_msg *rmsg)
{
	memcpy(cmsg, rmsg->data, sizeof(can_message_raw));
}


void rs232can_msg_from_can_message_raw(rs232can_msg *rmsg, can_message_raw *cmsg)
{
	rmsg->cmd = RS232CAN_PKT;
	rmsg->len = sizeof(can_message_raw) + cmsg->dlc - 8;
	memcpy(rmsg->data, cmsg, rmsg->len);
}
