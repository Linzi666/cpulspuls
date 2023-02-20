#include"comm.h"


int main()
{
  ssize_t fd = open(MY_FIFO,O_WRONLY);
  if(fd < 0)
  {
    perror("open");
    return 1;
  }

  //进行写入操作
  while(1)
  {
    //先读取键盘输入
    char buffer[64] = {0};
    read(0,buffer,sizeof(buffer));
    //写入
    write(fd,buffer,strlen(buffer));

  }

  close(fd);
  

  return 0;
}
