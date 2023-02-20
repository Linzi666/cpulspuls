#include"comm.h" 


int main()
{
  
  umask(0); //权限掩码
  if(mkfifo(MY_FIFO,0664)!= 0 )//管道文件创建失败
  {
    perror("mkfifo");
    return 1;
  }

  ssize_t fd = open(MY_FIFO,O_RDONLY); //打开文件，权限只读
  while(1)
  {
    //服务端读取
    char buffer[64] = {0};
    ssize_t s = read(fd,buffer,sizeof(buffer)-1);
    //回显信息
    printf("client : %s",buffer);
    if(s == 0)
      break;
  }
  close(fd);

  return 0;
}
