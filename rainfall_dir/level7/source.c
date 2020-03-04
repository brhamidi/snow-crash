#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char *flag;

void m()
{
  time_t t = time(0);
  printf("%s - %ld/n", flag, t);
}

int main(int ac, char **av)
{
	char **tstr1;
	char *str;
	char **tstr2;
	FILE *fd;

	tstr1 = malloc(8); // 0 - 7
	str = malloc(8); // 8 - 15
	tstr1[1] = str;
	tstr2 = malloc(8); // 16 - 23
	str = malloc(8); // 24 - 31
	tstr2[1] = str;
	strcpy(tstr1[1], av[1]); // 0 - 19 'a' 20 - 23 address of puts@PLT
	strcpy(tstr2[1], av[2]); // tstr2[1] is now 20 - 23 instead of 24 - 31, it will ecrase address of puts@PLT and replace it with address of m
	fd = fopen("/home/user/level8/.pass","r");
	fgets(flag,68,fd);
	puts("~~"); // it now m();
	return 0;
}
