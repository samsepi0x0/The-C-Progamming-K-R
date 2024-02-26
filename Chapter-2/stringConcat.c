#include <stdio.h>

/* Strings over multiple lines, does not work if s is a finite array. */

int main() {
  char *s = "Hello, " 
      "world";
  printf("%s\n", s);
  return 0;
}
