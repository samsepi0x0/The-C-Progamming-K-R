#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);
void printBinary(int n);

int main() {
  unsigned x = 127;
  unsigned t = setbits(x, 4, 3, 10);
  printBinary(x);
  printBinary(10);
  printBinary(t);
  return 0;
}

unsigned setbits(unsigned x, int p, int n, int y) {
  return (x & ((y << (p+1-n)) | ~(~(~0 << n) << (p+1-n))));
}

void printBinary(int n) {
  int s = sizeof(n)*8;
  for(int i = s-1; i >= 0; i--) {
    int b = (n >> i) & 1;
    printf("%d", b);
  }
  printf("\n");
}
