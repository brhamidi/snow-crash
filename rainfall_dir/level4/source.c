#include <stdio.h>
#include <stdlib.h>

int m;

void	n()
{
	char str[513];

	fgets(str, 512, stdin);
	printf(str); // exploit printf to change the value of m
	if (m == 64)
		system("cat /home/user/level5/.pass");
}

int main()
{
	n();
}
