#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
  int fd[2];
  if(pipe(fd)!=0) //管道开通失败
  {
    perror("pipe");
    return 1;
  }

  if(fork()==0)
  {
    //child write 
    close(fd[0]); //关闭读端
    char str[] = "hello pipe";
    while(1)
    {
    write(fd[1],str,strlen(str)) ;//写入数据
    sleep(1);  
     }
  }

  close(fd[1]);
  //parent read 
  while(1)
  {
    char buffer[64];
    read(fd[0],buffer,sizeof(buffer)-1);
    printf("child say to father : %s\n",buffer);
  }


  return 0;
}
