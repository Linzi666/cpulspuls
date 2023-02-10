#include<stdio.h>


//my_strlen

size_t my_strlen( char* str)
{
  char* cur = str;
  while(*cur++);
  
  return cur - str -1 ;
}


char* my_strcpy(char* dest,char* src)
{
  char * cur = dest;
  while(*cur++ = *src++);
  
  return dest;
}



//my_strcat
char* my_strcat(char* dest,char* src)
{
 
  char* cur = dest;
  while(*cur++);
  cur--;
  while(*cur++ = *src++);

  return dest;
}

int my_strcmp(const char* str1,const char* str2 )
{
  while(*str1 == *str2)
  {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

//my_strstr
char* my_strstr(char* dest,const char* src)
{
  int i = 0;
  int j = 0;
  int k = 0;
  while(dest[i])
  {
    if(dest[i] == src[k])
    {
      j = i;
      while(src[k] && src[k] == dest[j])
      {
        k++;
        j++;
      }
      if(src[k]== '\0')
        return dest+i;

      k = 0;
    }
    i++;
  }

  return NULL;
}

int main()
{
 // char str[] = "hello";
 // printf("%d\n",my_strlen(str));

 // char str1[20] = "hello ";
 // char str2[] = "world";
 // printf("%s\n",my_strcpy(str1,str2));

//  char str1[20] = "abc";
 //bin char str2[] = "abdaaaaaaaaa";
 // printf("%s\n",my_strcpy(str1,str2));
  char str1[] = "abcdabceabca";
  char str2[] = "abca";
  printf("%s\n",my_strstr(str1,str2));


  return 0;
}
