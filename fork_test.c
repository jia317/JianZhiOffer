#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  int ret = fork();
  if(ret < 0)
  {
    perror("fork");
    return -1;
  }
  else if(ret == 0)
  {
    printf("ret: %d\n", ret);
    printf("i am child: %d\n", getpid());
    printf("i am child: %d\n", getppid());
  }
  else{
    printf("ret: %d\n", ret);
    printf("i am father: %d\n", getpid());
  }
  return 0;
}
