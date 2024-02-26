#include <stdio.h>

int main() {
  int c, wl = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t'){
      putchar('\n');
    } else {
      putchar('#');
    }
  }

  return 0;
}
