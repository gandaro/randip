# include <stdio.h>
# include <assert.h>
# include <stdint.h>

int main(void)
{
	FILE *random = fopen("/dev/urandom","r");
	uint16_t ip_s[4];

	assert(random != NULL);

	for (int i = 0; i < 4; ++i)
	{
		fread(ip_s+i,2,1,random); // read 2 bytes from urandom
		printf(":%x",ip_s[i]);
	}

	fclose(random);
}
