#include"comm.h"


int main()
{
  int fd = open(MY_FIFO,O_WRONLY) ;//打开文件，读写权限
  if(fd < 0) 
  {
    //打开失败
    perror("open");
    return 1;
  }
  //写 
  while(1)
  {
   char buff[64] = {0};
   //从键盘读取 
   read(0,buff,sizeof(buff)-1);
   write(fd,buff,strlen(buff));//写
  }

  return 0;
}
