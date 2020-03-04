#include <stdio.h>
#include <stdlib.h>

int m;

void	v()
{
	char str[513];

	fgets(str, 512, stdin);
	printf(str); // exploit printf to change the value of m
	if (m == 64)
	{
		fwrite("Wait what?!\n", 1, 12, stdout);
		system("/bin/sh");
	}
}

int main()
{
	v();
}
