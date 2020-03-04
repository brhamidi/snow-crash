#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (atoi(av[1]) == 423) // condition to pass
    {
        gid_t gid = getegid();
        uid_t uid = geteuid();
        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);
        execv("/bin/sh", 0);
    }
    else
        fwrite("No !\n", 1, 5, stderr);
    return (0);
}
