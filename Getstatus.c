#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// 异常终止时，coredump标志位的获取及终止信号的获取
int main()
{
  pid_t pid = fork();
  if(pid < 0)
  {
    perror("fork");
    return 0;
  }
  else if(pid == 0)
  {
    // 空指针赋值，会产生段错误，异常终止信号为11
    int* p = NULL;
    *p = 7;

    // 下边代码用来判断异常终止时，代码是未执行完的
    while(1)
    {
      printf("child pid = %d\n", getpid());
      sleep(1);
    }
  }
  else{
    int status;
    waitpid(-1, &status, 0);

    printf("coredump_code : %d\n", (status >> 7) & 0x1);
    printf("sig_code : %d\n", status & 0x7f);
  }

  return 0;
}
