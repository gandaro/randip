# include <stdio.h>
# include <assert.h>
# include <stdint.h>

# define BLOCKS 4

int main(void)
{
	FILE *random = fopen("/dev/urandom","r");
	uint16_t ip_s[BLOCKS];

	assert(random != NULL);
	assert(fread(ip_s,2,BLOCKS,random) == BLOCKS); // read 4 * 2 random bytes

	fclose(random);

	for (int i = 0; i < BLOCKS; ++i)
		printf(":%04x",ip_s[i]);
}
