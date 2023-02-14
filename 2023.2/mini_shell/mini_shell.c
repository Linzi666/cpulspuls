#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#define MAX_SIZE 128
#define CMD_NUM 64

int main()
{
   char command[MAX_SIZE];

  //死循环
  while(1)
  {
    //1.输入提示
    printf("[my_mini_shell] #");
    fflush(stdout);
    
    //2.提取输入字符
    fgets(command,MAX_SIZE,stdin);
    //把最后一个回车置空
    command[strlen(command)-1] = 0;
  //  printf("%s\n",command);
    
    //3分割字符 
    char *argv[CMD_NUM] = {0}; 
    const char* sep = " ";
    argv[0] = strtok(command,sep);
    int i = 1;
    while(argv[i++] = strtok(NULL,sep));
    
    if(fork()==0)
    {
      //child
      if(strcmp(argv[0],"cd")== 0)
        if(argv[1] != NULL) 
        {
          chdir(argv[1]); //内建命令
          continue;
        }

      execvp(argv[0],argv);
      exit(1);//异常终止
    }
    
    int status = 0;
    waitpid(-1,&status,0);

   // for(i = 0 ; argv[i] ; i++)
   // {
   //   printf("%s\n",argv[i]);
   // }
  
  }



  return 0;
}
