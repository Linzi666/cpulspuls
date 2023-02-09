#include<stdio.h>
#include<unistd.h>

int g_val = 100;

int main()
{
  int pid = fork(); //创建子进程
  if(pid == 0)
  {
    //child
    int count = 5;
    while(count)
    {
      printf("i am child , g_val = %d, &g_val = %p\n",g_val,&g_val);

      if(count == 3)
      {
        //修改数据
        printf("******开始修改数据*******\n");
        printf("i am child , g_val = %d, &g_val = %p\n",g_val,&g_val);
        g_val = 200;
        printf("******修改数据done*******\n");
      }
      count--;
      sleep(1);
    } 
    
  }
  else if(pid > 0)
  {
    //parent
    while(1)
    {
      printf("i am father , g_val = %d, &g_val = %p\n",g_val,&g_val);
      sleep(1);
    }
  }
  else 
  {
    //erro
    perror("fork:");
  }
  return 0;
}
