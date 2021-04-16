#include <stdio.h>
#include <unistd.h>

int main()
{
  // 函数名中带e的需要自己组织环境变量
  char* const envp[] = {"PATH = /bin:/usr/bin", "TERM = console", NULL};
  // execl系列函数，参数用列表
  execl("/bin/ps", "ps", "-ef", NULL);

  execlp("ps", "ps", "-ef", NULL);

  execle("/bin/ps", "ps", "-ef", NULL, envp);

  // execv系列函数中，参数用数组保存，传递时直接传数组
  char* const argv[] = {"ps", "-ef", NULL};

  execv("/bin/ps", argv);

  execvp("ps", argv);

  execve("bin/ps", argv, envp);

  return 0;
}
