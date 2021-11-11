
#ifndef _BUFFER
#define  BUFFER_EXTLBL 					extern
#else
#define  BUFFER_EXTLBL 
#endif



BUFFER_EXTLBL void buffer_Init (void);
BUFFER_EXTLBL int buffer_push (uint8_t);


BUFFER_EXTLBL uint8_t 	buffer [256];
BUFFER_EXTLBL int 		buffer_len;
BUFFER_EXTLBL int 		buffer_ind;


