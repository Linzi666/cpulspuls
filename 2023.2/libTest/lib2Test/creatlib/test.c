#include<stdio.h>
#include"add.h"
#include"sub.h"

int main()
{
  int x = 10;
  int y = 20;
  int r1 = add(x,y);
  int r2 = sub(x,y);
  printf("%d + %d = %d\n",x,y,r1);
  printf("%d - %d = %d\n",x,y,r2);

  return 0;
}
