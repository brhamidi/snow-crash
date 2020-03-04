#include <stdlib.h>
#include <stdio.h>

void	decrypt(int password)
{
	if (password == 18)
	{
		system("/bin/sh");
	}
	else
		puts("\nInvalid Password");
}

void	test(int password, int offset)
{
	password = offset - password;
	if (password < 21)
		decrypt(password);
}

int main()
{
	int offset = 322424845;
	int password;

	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &password);
	test(password, offset);
}
