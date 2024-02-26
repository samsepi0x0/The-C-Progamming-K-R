/*replace each string of one or more blanks by a single blank*/

#include <stdio.h>

int main() {
  int c, bc;
  bc = 0;
  
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (bc == 0) {
        bc = 1;
        putchar(c);
      }
    } else {
      bc = 0;
      putchar(c);
    }
  }

  return 0;
}
