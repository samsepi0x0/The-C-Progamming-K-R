/* Count digits, whitespaces and other characters */
#include <stdio.h>

int main() {
  int c, whitespace, other;
  whitespace = other = 0;
  
  int ndigit[10];
  for(int i = 0; i < 10; i++)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ndigit[c - '0']++;
    else if (c == ' ' || c == '\t' || c == '\n')
        whitespace++;
    else 
      other++;
  }
  for(int i = 0; i < 10; i++)
    printf("%d -> %d\n", i, ndigit[i]);
  printf("Whitespaces: %d\nOthers: %d\n", whitespace, other);

  return 0;
}
