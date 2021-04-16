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
    // 非阻塞等待
    // 此时，如果子进程未执行完毕，父进程的waitpid直接返回并报错
    // 非阻塞一般会搭配循环使用
    while((waitpid(-1, &st, WNOHANG)) == 0);
    printf("exit_code: %d\n", (st >> 8) & 0xff); 

    // 异常退出后边两行代码的值才不会为0
    printf("sig_code: %d\n", st & 0x7f); 
    printf("coredump_code: %d\n", (st >> 7) & 0x1);
    
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
