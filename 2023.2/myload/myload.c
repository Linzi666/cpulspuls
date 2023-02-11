#include<stdio.h>
#include<unistd.h>


int main()
{
  unsigned int pid = fork();
  if(pid == 0)
  {
    //child
    printf("i am child\n");
   // execlp("ls","ls","-a","-1",NULL);//程序替换
    char *env[] = 
    {
      "A = AAAAAAAAAAAAAAAAA",
      "B = BBBBBBBBBBBBBBBBB",
      "C = CCCCCCCCCCCCCCCCC",
        NULL 
    };

    char *avg[] = 
    {
      "myexe",NULL 
    };

    //execv("/usr/bin/ls",avg);
    //execvp("ls",avg);
    execve("/myexe",avg,env);
   // execle("./myexe","myexe",NULL,env);
    printf("hhhhhhhhhhhhhh\n");
    printf("hhhhhhhhhhhhhh\n");
    printf("hhhhhhhhhhhhhh\n");
    printf("hhhhhhhhhhhhhh\n");
    printf("hhhhhhhhhhhhhh\n");
    printf("hhhhhhhhhhhhhh\n");
  }
  sleep(1);
  printf("i am father\n");

  return 0;
}
