#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

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
    int count = 10;
    while(1)
    {
      if(count < 1)
      {
        break;
      }
      printf("I am child: pid = %d, ppid = %d\n", getpid(), getppid());
      count--;
      sleep(1);
    }
    exit(10);
  }
  else{
    printf("BEGIN...i am father: pid = %d, ppid = %d\n", getpid(), getppid());

    int st;
    // 阻塞等待
    // 此时，父进程将会阻塞在waitpid函数，直到子进程中count减到0，退出循环，然后执行exit(10)
    // 父进程等待成功后，拿到st，因为子进程是正常退出，所以st中使用高8位，可以获取退出码10
    waitpid(-1, &st, 0);
    printf("exit_code: %d\n", (st >> 8) & 0xff); // 10
    printf("sig_code: %d\n", st & 0x7f); // 0
    printf("coredump_code: %d\n", (st >> 7) & 0x1); // 0
    
    // 下面这段代码只是为了验证是否阻塞
    // 如果阻塞，那么这段代码要到子进程退出，父进程等待成功才会打印
    // 如果非阻塞，那么这段代码
    while(1)
    {
      printf("I am father:pid = %d, ppid = %d\n", getpid(), getppid());
      sleep(1);
    }
  }

  return 0;
}
