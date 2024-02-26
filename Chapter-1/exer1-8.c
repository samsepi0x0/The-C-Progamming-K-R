/*Count blanks, tabs and new lines*/

#include <stdio.h>

int main() {
  int c, nl, tc, bc;
  nl = tc = bc = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      bc++;
    if (c == '\t')
      tc++;
    if (c == '\n')
      nl++;
  }
  printf("Blanks: %d\tTabs: %d\tNewLines: %d\n", bc, tc, nl);
  return 0;
}
