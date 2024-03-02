#include <stdio.h>

void foo(void) {
  volatile int x;
  static int y;
  printf("X\t%d\n", &x);
  printf("Y\t%d\n", &y);
}

void bar(void) {
  static int a;
  printf("A\t%d\n", &a);
}

int main() {
  foo();
  bar();
  foo();
  return 0;
}
