#include <stdio.h>

int main() {
  int x = 0xA;
  int b = 0;
  for(b = 0; x != 0; x &= (x-1))
    b++;
  printf("%d\n", b);
  return 0;
}
