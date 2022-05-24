#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "png.h"

png_chunk_t *get_chunk(uint32_t chunk_len, const char *type, const uint8_t *data, uint32_t crc)
{
	png_chunk_t *new_chunk = malloc(sizeof(*new_chunk));
	assert(new_chunk != NULL);

	// parse chunk length into big-endian 4 bytes
	new_chunk->len_a = (chunk_len & 0xFF000000) >> 24;
	new_chunk->len_b = (chunk_len & 0xFF0000) >> 16;
	new_chunk->len_c = (chunk_len & 0xFF00) >> 8;
	new_chunk->len_d = (chunk_len & 0xFF);

	// parse chunk type's 4 characters
	assert(type != NULL);
	const size_t len = strlen(type);
	assert(len == 4);

	new_chunk->type_a = *type;
	new_chunk->type_b = *(type + 1);
	new_chunk->type_c = *(type + 2);
	new_chunk->type_d = *(type + 3);

	return new_chunk;
}
