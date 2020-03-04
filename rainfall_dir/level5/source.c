#include <stdio.h>
#include <stdlib.h>

void o()
{
	system("/bin/sh");
}

void n()
{
	char str[512];

	fgets(str, 512, stdin);
	printf(str); // exploit printf
	exit(1);
}

int main()
{
	return (0);
}
