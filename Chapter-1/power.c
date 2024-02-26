#include <stdio.h>

int power(int x, int y);

int main() {
  int i;

  for(int i = 0; i < 10; i++) {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }
  return 0;
}

int power(int x, int y) {
  int i, p;
  p = 1;
  for(i = 0; i < y; i++) {
    p = p * x;
  }
  return p;
}
