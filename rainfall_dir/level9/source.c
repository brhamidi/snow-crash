#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void setAnnotation(char *dst,char *src)
{
	size_t l;

	l = strlen(src);
	memcpy(dst, src, l);
	return;
}

void v(void)
{
	return ;
}

int main(int ac, char **av)
{
	char *str = malloc(100); // 0-99
	void (**f_ptr)(void) = malloc(sizeof(void*)); // 100-107
	
	if (ac < 2)
		exit(0);
	*f_ptr = &v;
	setAnnotation(str, av[1]); // place the shellcode on the heap and the address of it with the buffer overflow
	(**f_ptr)(); // call shellcode instead of v()
}
