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
    int count = 5;
    //1int* lp = NULL  
    //*lp = 10; 
    while(count > 0)
    {
      printf("i am child pid:%d, ppid:%d\n", getpid(), getppid());
      count--;
      printf("%d\n", count);
      sleep(1);
    }
    exit(10);
  }
  else{
    printf("BEGIN...i am father pid:%d, ppid:%d\n", getpid(), getppid());

    int st;
    wait(&st); // st中保存了子进程异常退出发送的信号
    printf("sig_code: %d\n", st & 0x7f); 
    printf("coredump_code: %d\n", (st>>7) & 0x1); 
    
    // 如果是wait函数是阻塞等待，那么一定要等到
    while(1)                                                                      
    {
      printf("i am father pid:%d, ppid:%d\n", getpid(), getppid());                           
      sleep(1);                                                                   
    }
  }
  return 0;
}
