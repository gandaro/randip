# include <stdio.h>
# include <assert.h>
# include <stdint.h>

int main(void)
{
	FILE *random = fopen("/dev/urandom","r");
	uint16_t ip_s[4];

	assert(random != NULL);
	assert(fread(ip_s,2,4,random) == 4); // read 4 * 2 random bytes

	fclose(random);

	for (int i = 0; i < 4; ++i)
		printf(":%x",ip_s[i]);
}
