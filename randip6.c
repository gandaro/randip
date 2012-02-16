# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <assert.h>
# include <stdint.h>

int main(void)
{
	int rfd, i = 0;
	uint16_t ip_s[4];

	rfd = open("/dev/urandom",O_RDONLY);

	assert(rfd >= 0);
	
	read(rfd,ip_s,8);
	
	for ( ; i < 4; ++i )
	{
		printf(":%x",ip_s[i]); // We don't fill the field with 0s because it's unnecessary
	}
	
	close(rfd);

	return 0;
}
