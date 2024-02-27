#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void printBinary(int n);

int main() {
  unsigned x = 127;
  int p = 4;
  int n = 3;
  unsigned t = invert(x, p, n);
  printBinary(x);
  printBinary(t);
  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  return (x ^ (((1 << n) - 1) << (p+1-n)));
}

void printBinary(int n) {
  int s = sizeof(n)*8;
  for(int i = s-1; i >= 0; i--) {
    int b = (n >> i) & 1;
    printf("%d", b);
  }
  printf("\n");
}
