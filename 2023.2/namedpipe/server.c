#include"comm.h"

int main()
{
  umask(0); //设置掩码
  if(mkfifo(MY_FIFO,0666) < 0) //mkfifo的两个参数是文件路径和文件权限
  {
    //如果没有找到文件则返回 -1 
    perror("mkfifo");
    return 1;
  }

  //接下来进行文件操作即可
  int fd = open(MY_FIFO,O_RDONLY);
  if(fd < 0)
  {
    //打开失败
    perror("open");
    return 2;
  }

  //业务逻辑
  while(1)
  {
    // 读取并刷新
    char buffer[64] = {0};

    ssize_t s =  read(fd,buffer,sizeof(buffer)-1);
    //刷新到显示器
    printf("client : %s ",buffer);
    if(s ==  0) //客户端挂了
    {
      break;
    }
  }


  close(fd);

  return 0;
}
