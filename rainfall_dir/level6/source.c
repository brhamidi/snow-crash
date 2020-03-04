#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void n()
{
	system("/bin/cat /home/user/level7/.pass");
}

void m()
{
	puts("Nope");
}

int main(int ac, char **av)
{
  char *str;
  void (**function_ptr)(void);
  
  str = malloc(0x40);
  function_ptr = malloc(4);
  *function_ptr = m;
  strcpy(str, av[1]); //overflow buffer str and ecrase function_ptr address
  (*function_ptr)();
}
