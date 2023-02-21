#include"comm.h" 

int main()
{
  int fd[2];
  if(pipe(fd)!= 0) //开通失败
  {
    perror("pipe");
    return 1;
  }

  //子进程写
  if(fork()==0)
  {
    //写 ，关闭读
    close(fd[0]);
    while(1)
    {
       char str[] = "hello world";
       write(fd[1],str,strlen(str));
       sleep(1);
    }
  }

  //父进程读
  close(fd[1]); //关闭写
  while(1)
  {
    char ret[64] = {0};
    ssize_t s  = read(fd[0],ret,sizeof(ret)-1);
    ret[s] = 0;
    printf("child say to father: %s\n",ret);
  }

  return 0;
}
