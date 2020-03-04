#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>

void	pp(char *str)
{
	char buffer[4096];

	puts(" -");
	read(0, buffer, 4096);
	*(strchr(buffer, 10)) = 0;
	strncpy(str, buffer, 20);
}

void	p(char *str)
{
	char s1[20];
	char s2[20];

	pp(s1);
	pp(s2);
	strcpy(str, s1); // as the s2 follow s1 and s1 does not got \0 the copy will be longer than supposed
	strcat(str, " ");
	strcat(str, s2);
}

int main()
{
	char	str[54];

	p(str);
	puts(str);
	return (0);
}
