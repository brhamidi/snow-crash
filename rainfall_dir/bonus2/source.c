#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int language = 0;

void	greetuser(char *name)
{
	char greet[60];

	if (language == 0)
		strcpy(greet, "Hello ");
	else if (language == 1)
		strcpy(greet, "Hyvää päivää ");
	else if (language == 2)
		strcpy(greet, "Goedemiddag! ");
	strcat(greet, name); // name is longer than expect if first argument is more than 40
	puts(greet);
	//when returning it will call shellcode instead of return into main function
}

int		main(int ac, char **av)
{
	char name[40];
	char str[36];		//str follow name in memory
	char *lang;

	if (ac < 2)
		return (0);
	strncpy(name, av[1], 40);	//if there is no \0 in the 40 first bits it wont be null terminated
	strncpy(str, av[2], 32);	//as name is non null terminated add str to the end of name
	lang = getenv("LANG");
	if (lang)
	{
		if (!memcmp(lang, "fi", 2))
			language = 1;
		else if (!memcmp(lang, "nl", 2))
			language = 2;
	}
	greetuser(name);
	return (0);
}
