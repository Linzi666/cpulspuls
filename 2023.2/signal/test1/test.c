#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>


int main(int argc,char* argv[])
{
  if(argc != 3)
  {
    perror("input error");
    return 1;
  }

  int signal = atoi(argv[2]);
  int a = atoi(argv[1]);

  kill(a,signal);

  

  return 0;
}














//void handler(int signo) { 
//  printf("process erreo , receive signal ： %d\n",signo);
//  exit(1);
//}
//
//
//int main()
//{
// // signal(8,handler);
//  
//  for(int i = 1; i <= 31 ; i++)
//  {
//    signal(i,handler);
//  }
//
//  while(1)
//  {
//    int i = 5;
//    i /=0;
//  // int* p =(int*) 100;
//  // *p = 5;
//  }
//  return 0;
//}
