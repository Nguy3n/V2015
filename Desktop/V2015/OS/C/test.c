#include <stdio.h>
#include <unistd.h>

int main() {
  int p;
  p = fork();
  printf("%d \n", p);
}
