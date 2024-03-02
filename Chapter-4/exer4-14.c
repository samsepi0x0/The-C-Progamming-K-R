#include <stdio.h>

#define swap(t, a, b) {\
  x = x + y;           \
  y = x - y;           \
  x = x - y;}          \

int main() {
  int x = 10;
  int y = 100;

  printf("X: %d\tY: %d\n", x, y);
  swap(int, x, y)
  printf("X: %d\tY: %d\n", x, y);

  return 0;
}
