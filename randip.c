#define _POSIX_SOURCE

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int seed = time(NULL);

    for (int i = 0; i < 4; i++)
        printf(":%x", rand_r(&seed) % (0xffff+1));
}
