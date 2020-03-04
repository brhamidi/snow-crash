#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	FILE *fd;
	char flag[67];
	char rest[66];
	int     i;

	rest[0] = 0;
	fd = fopen("/home/user/end/.pass", "r");
	if (!fd || ac != 2)
		return (0);
	fread(flag, 66, 1, fd);
	fread(rest, 65, 1, fd);
	i = atoi(av[1]);
	flag[i] = 0;	// atoi("") return 0 so flag will become an empty string
	if (!strcmp(flag, av[1]))	//as now flag is an empty string and we compare it with the first arg that is an empty string too
		execl("/bin/sh", "sh", NULL);
	else
		puts(rest);
	return (0);
}
