/* File: overflow.c */
/* Compile with : */
/* gcc -o bignum overflow.c */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a, b, c;

  a = sizeof(int) *8;
  printf("Datatype int has %d bits\n",a);
  printf("Range: -2147483648 to 2147483647\n\n");
  printf("Addition with datatype int:\n");
  b = 2147483647;
  c = 2; /* c=1 will do */
  printf("b=%d\nc=%d\n",b,c);
  printf("b+c=%d\n\n",b+c);
  exit(0);
}
