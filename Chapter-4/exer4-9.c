#include <stdio.h>
#include <string.h>

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
  if (bufp >= BUFFSIZE)
    printf("ungetch: too many characters.\n");
  else if (c != EOF) 
    buf[bufp++] = c;
  else 
    printf("ungetch: cant push value.\n");
}

int main(void) {
  int c;

  ungetch(EOF);

  while ((c = getch()) != EOF){
    putchar(c);
  }
  return 0;
}
