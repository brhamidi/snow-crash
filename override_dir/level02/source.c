#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fd = fopen("/home/users/level03/.pass", "r");
	char flag[42];
	char username[100];
	char password[100];

	fread(flag, 1, 41, fd);
	flag[41] = 0;

	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");

	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = 0;

	printf("--[ Password: ");

	fgets(password, 100, stdin);
	password[strcspn(password, "\n")] = 0;

	puts("*****************************************");

	if (!strcmp(password, flag))
	{
		printf("Greetings, %s!\n", username);
		system("/bin/sh");
		return 0;
	}
	printf(username); // exploit this printf to print password instead.
	puts(" does not have access!");
	return (0);
}
