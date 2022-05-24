#include <assert.h>
#include <stdlib.h>

#include "png.h"

int main(void)
{

#define FILE_SIG_LEN 8
/*	uint8_t file_sig[FILE_SIG_LEN] =
	{
		0x89,
		0x50, 0x4E, 0x47,	// "PNG"
		0x0D, 0x0A,
		0x1A,
		0x0A
	};
*/
	png_chunk_t *chunk = get_chunk(0xFF881122, "IHDR", NULL, 0);

	// tests the size is parsed into big-endian 4 bytes correctly
	assert(chunk->len_a == 0xFF);
	assert(chunk->len_b == 0x88);
	assert(chunk->len_c == 0x11);
	assert(chunk->len_d == 0x22);

	// tests type parsing
	assert(chunk->type_a == 'I');
	assert(chunk->type_b == 'H');
	assert(chunk->type_c == 'D');
	assert(chunk->type_d == 'R');

	free(chunk);
	exit(0);
}
