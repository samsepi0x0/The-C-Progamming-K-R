#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void printBinary(int n);

int main() {
  unsigned x = 0x6DEF;
  int n = 25;
  unsigned t = rightrot(x, n);
  printBinary(x);
  printBinary(t);
  return 0;
}

unsigned rightrot(unsigned x, int n) {
  unsigned bits = sizeof(n)*8;
  if (n == 0 || n == bits)
      return x;
  return (x >> n) | ((x & ~(~0 << n)) << (sizeof(x)*8 - n));
}

void printBinary(int n) {
  int s = sizeof(n)*8;
  for(int i = s-1; i >= 0; i--) {
    int b = (n >> i) & 1;
    printf("%d", b);
  }
  printf("\n");
}
