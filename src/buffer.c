#include <stdint.h>

#define  _BUFFER
#include "buffer.h"



void buffer_Init (void)
{
	buffer_ind = 0;
	buffer_len = 0;
}



int buffer_push (uint8_t data)
{
	int ind = -1;


	buffer [buffer_len] = data;

	buffer_len ++;
	if 		(buffer_len == 128)
	{
		ind = buffer_ind;

		buffer_ind = buffer_len;
	}
	else if (buffer_len == 256)
	{
		ind = buffer_ind;

		buffer_len = 0;
		buffer_ind = buffer_len;
	}


	return ind;
}
