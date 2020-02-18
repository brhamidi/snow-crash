#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
        FILE *fd;
        char flag[67];
        char rest[66];
        int     i;

        if (ac != 2)
                return (0);
        rest[0] = 0;
        fd = fopen("/home/user/end/.pass", "r");
        fread(flag, 66, 1, fd);
        fread(rest, 65, 1, fd);
        i = atoi(av[1]);
        flag[i] = 0;
        if (!strcmp(flag, av[1]))
                execl("/bin/sh", "sh", NULL);
        else
                puts(rest);
        return (0);
}
