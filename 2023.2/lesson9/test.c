#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

//int main(int args,char* argv[],char* env[])
  int main()
{
  char* env = getenv("NEWENV");
  if(env)
  {
    printf("evn : %s\n",env);
  }
  else 
  {
    printf("NEWENV not exict\n");
  }


 // int i = 0;
 // extern char** environ;
 // while(environ[i])
 // {
 //   printf("%s\n",environ[i]);
 //   i++;
 // }


 // while(1)
 // {
 // printf("hello world\n");
 // sleep(1);
 // }
  return 0;
}
