#include<stdio.h>


int main()
{
  //就遍历一下环境变量
  extern char ** environ;
  int i = 0;
  while(environ[i])
  {
    printf("%s\n",environ[i]);
    ++i;
  }

  return 0;
}
