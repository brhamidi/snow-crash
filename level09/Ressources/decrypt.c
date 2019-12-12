#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
        int fd = open("/home/user/level09/token", O_RDONLY);

        int i = 0;
        char c;
        while(read(fd, &c, 1) > 0)
        {
                printf("%c", c - i);
                i++;
        }
        printf("\n");
}
