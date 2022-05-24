#ifndef PNG_H
#define PNG_H

#include <stdint.h>

typedef uint32_t chunk_len;
typedef uint32_t chunk_type;
typedef uint32_t crc;

typedef struct
{
       chunk_len len_a 		: 8,
	         len_b 		: 8,
	         len_c 		: 8,
		 len_d 		: 8;

       chunk_type type_a 	: 8,
		  type_b	: 8,
		  type_c	: 8,
		  type_d	: 8;

       crc crc_a		: 8,
	   crc_b		: 8,
	   crc_c		: 8,
	   crc_d		: 8;

       uint8_t *data;
} png_chunk_t;

png_chunk_t *get_chunk(uint32_t chunk_len, const char *type, const uint8_t *data, uint32_t crc);

#endif
