# include <stdio.h>
# include <assert.h>
# include <stdint.h>

# define BLOCKS 4

int main(void)
{
	FILE *random = fopen("/dev/urandom","r");
	uint16_t ip_s[BLOCKS];

	assert(random != NULL);
	// read 4 * 2 random bytes
	assert(fread(ip_s,2,BLOCKS,random) == BLOCKS);

	fclose(random);

	for (uint8_t i = 0; i < BLOCKS; ++i)
		printf(":%x",ip_s[i]);
}
