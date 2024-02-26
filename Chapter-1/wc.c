/*Word count utility*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, wc;
  wc = 0;
  int state = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      wc++;
    }
  }
  printf("%d\n", wc);
  return 0;
}
