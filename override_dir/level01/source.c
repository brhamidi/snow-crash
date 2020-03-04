#include <stdio.h>

char a_user_name[256];

int verify_user_name(char *name)
{
	char *admin = "dat_will";
	int	i = 0;

	while (admin[i])
	{
		if (admin[i] != name[i])
			return (1);
		i++;
	}
	return (0);
}

int verify_user_pass(char *pass)
{
	char *passwd = "admin";
	int	i = 0;

	while (passwd[i])
	{
		if (passwd[i] != pass[i])
			return (1);
		i++;
	}
	return (0);
}

int main()
{
	char passwd[64];

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin); // dat_will + shelcode
	if (!verify_user_name(a_user_name))
	{
		puts("Enter Password: ");
		fgets(passwd, 100, stdin); //buffer overflow on passwd to ecrase return address
		int i = verify_user_pass(passwd);
		if ((i == 0) || (i != 0))
		{
			puts("nope, incorrect password...\n");
			return (1);
		}
		else
			return (0); // jump to shellcode
	}
	else
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	return (0); }
