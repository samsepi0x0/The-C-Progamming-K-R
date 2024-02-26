#include <stdio.h>

int main() {
  char s[100] = "ABCDE";
  int i = 0;

  while (s[i] != '\0')
    ++i;
  
  printf("Length:\t%d\n", i);
  return 0;
}


