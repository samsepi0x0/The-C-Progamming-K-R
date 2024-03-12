#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXLEN 1000

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main(void) {
  int number = 0;
  getint(&number);
  printf("%d\n", number);
  return 0;
}

int bufp = 0;
int buf[BUFSIZE];

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many arguments.");
  else
    buf[bufp++] = c;
}

int getint(int *pn) {
  int c, sign;
  while (isspace(c = getch()));
  
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  
  if (c == '+' || c == '-') {
    if (!isdigit(c = getch())) {
      ungetch(c);
      ungetch(sign == 1 ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }

  *pn = *pn * sign;
  if (c != EOF) {
    ungetch(c);
  }
  
  return c;
}
