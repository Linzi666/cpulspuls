#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define NUM 100

int main()
{
  char probar[NUM+1];
  memset(probar,0,NUM+1);
  int i = 0 ;
  srand(time(0));
  while(i<=NUM)
  {
        int r = rand() % 10 + 1;
        for(int  j = 0 ; j <=r ;j++)
        {
        printf("[%-100s] [%%%d] \r",probar,i);
          probar[i] = '=';
          ++i;
          if(i>=NUM)
          {
             break;
          }
        }
        fflush(stdout);
        sleep(1);
  }
  printf("\n");
  return 0;

}
