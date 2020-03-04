#include <stdio.h>
#include <stdlib.h>

void	run() // jump into this function
{
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	system("/bin/sh");
}

int main()
{
	char str[48];
	gets(str);
	return (0);
}
