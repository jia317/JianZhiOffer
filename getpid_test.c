#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>

int main()
{
  printf("%d\n", getpid());
  printf("%d\n", getppid());

  return 0;
}
