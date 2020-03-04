#include <stdlib.h>
#include <stdio.h>

void p()
{
	char str[40]; // buffer overflow this var
	gets(str);
	if ((unsigned int)(str + 44) == 2952790016)
	{
		printf("Nope!\n");
		exit(0);
	}
	puts(str);
}

int main()
{
	p();
}
