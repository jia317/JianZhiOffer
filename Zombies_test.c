#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
  pid_t pid = fork();
  if(pid < 0)
  {
    perror("fork");
    return 1;
  }
  else if(pid > 0)
  {
    printf("parent[%d] is sleeping..\n", getpid());
    sleep(30);
  }
  else{
    printf("child[%d] is begin Zombie...\n", getpid());
    sleep(5);
    exit(EXIT_SUCCESS);
  }
  return 0;
}
