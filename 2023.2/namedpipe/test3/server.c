#include"comm.h"


int main()
{
  umask(0) ;//掩码设置 
  if(mkfifo(MY_FIFO,0666)< 0)
  {
    perror("mkfifo");
    return 1;
  }
  
  int fd = open(MY_FIFO,O_RDONLY) ; //服务器只读
  if(fd < 0)
  {
    perror("open:");
    return 1;
  }

  while(1)
  {
    char buffer[1024] = {0};
    read(fd,buffer,sizeof(buffer)-1);
    printf("client:%s\n",buffer);
  }


  return 0;
}
