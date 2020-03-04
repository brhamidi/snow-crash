#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	i;

	puts("***********************************");
	puts("*           -Level00 -            *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &i);
	if (i == 5276)
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
	}
	else
		puts("Invalid Password!");
	return (0);
}
