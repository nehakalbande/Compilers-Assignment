#include <stdio.h>

int main()
{
  int new_line;

  new_line = 0;
  int c;
   FILE *fp;

   fp = fopen("input.c", "r");
  while ( (c = fgetc(fp)) != EOF)
  {
    if ( c == '\n' ){
      ++new_line;
    }
  }  
  printf("newline=%d\n",new_line);
  fclose(fp);
}
