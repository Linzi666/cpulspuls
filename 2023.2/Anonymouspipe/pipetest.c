#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  int pp[2];
  if(pipe(pp)!= 0)
  {
    //管道开通失败
    perror("pipe:");
    return 1;
  }
  
  //管道开通成功
  if(fork()==0)
  {
    //child write
    close(pp[0]); //0是读，关闭子进程的读
    char message [] = "hello pipe";
    int count = 0;
    while(1)
   {
      // write(pp[1],message,strlen(message));
       write(pp[1],"a",1);
      // sleep(1);
      printf("count : %d\n",count++);

    }
  }
  //parent read
  close(pp[1]); //关闭写
  while(1)
  {
     sleep(10);
    //持续读取   
    char buffer[1024*4] = {0};  //缓冲区
    ssize_t s = read(pp[0],buffer,sizeof(buffer)-1);
    buffer[s] = 0;
   // printf("child say to father :%s\n",buffer);
    printf("parent take a\n");
  }

  return 0;
}
