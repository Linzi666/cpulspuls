#include"comm.h"



int main()
{
    
  int fd = open(MY_FIFO,O_WRONLY) ; 
  if(fd < 0)
  {
    perror("open");
    return 1;
  }

  while(1)
  {
    char input[64] = {0};
    read(0,input,sizeof(input)-1); 
    write(fd,input,strlen(input));
  }

  close(fd);

}
