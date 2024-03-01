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
  else 
    buf[bufp++] = c;
}

void ungets(char *s) {
  int i = strlen(s);
  int c;

  while (i > 0)
    ungetch(s[--i]);
}

int main(void) {
  char s[] = "Lorem Ipsum Dolor Set amet.";
  int c;

  ungets(s);

  while ((c = getch()) != EOF){
    putchar(c);
  }
  return 0;
}
