#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char str[40];
	int i = atoi(av[1]);

	if (i < 10)
	{
		memcpy(str, av[2], i * 4); // overflow str buffer because of i * 4
		if (i == 0x574f4c46) //(0x574f4c46 is equal to "FLOW")
			execl("/bin/sh", "sh", NULL);
	}
	return (0);
}
