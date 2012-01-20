# include <stdio.h>
# include <stdlib.h>
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
	
	for ( ; i < 4; ++i )
	{
		read(rfd,ip_s+i,2);
		printf(":%x",ip_s[i]);
	}
	
	close(rfd);

	return 0;
}
