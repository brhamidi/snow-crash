
void m()
{
  int time = time();
  printf("%s - %d/n", flag, time);
}

char *flag;

int main(int ac, char **av)
{
  int fd;
  char *arg1 = malloc(20);
  char *str = malloc(4);
  flag = malloc(200);
  malloc(0);
  strcpy(arg1, av[1]);
  strcpy(str, av[2]);
  fd = fopen("/home/user/level8/.flag");
  fgets(flag, 200, fd);
  puts("~~");
  return (0);
}
