#include <stdio.h>

int main() {
  int x = 1, y= 2, z[10];

  int *p;

  p = &x;
  y = *p;
  printf("%d %d\n", x, y);
  *p = 0;
  printf("%d %d\n", x, y);
  return 0;
}
