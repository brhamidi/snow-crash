#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *auth = 0;
	char *service = 0;
	char str[129];

	str[128] = 0;
	printf("%p, %p \n",auth,service);
	while (fgets(str, 128, stdin))
	{
		if (!strncmp(str, "auth ", 5)) // use auth first
		{
			if (strlen(str) < 30)
			{
				auth = strndup(&str[5], 11); // 0-12
			}
			else
				auth = calloc(11, 1);
		}
		else if (!strncmp(str, "service ", 8)) // and then service 
		{
			service = strdup(&str[8]); // 16 - xx, must be long enough to match the login condition
		}
		else if (!strncmp(str, "reset\n", 6))
		{
			free(auth);
			auth = 0;
			free(service);
			service = 0;
		}
		else if (!strncmp(str, "login\n", 6))
		{
			if (auth && auth[32]) // to be able to start shell thanks to service's address following auth's one
				system("/bin/sh");
			else
				fwrite("Password:\n",1,10,stdout);
		}
		printf("%p, %p \n",auth,service);
	}
}
