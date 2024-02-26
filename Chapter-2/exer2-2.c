#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main() {
  int len;
  int max;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    printf("%s", line);
  }
  return 0;
}

int getLine(char s[], int lim) {
  int c, i, j;
  for(i = 0, j = 0; ; i++) {
    if (i > lim - 1)
      break;
    if ((c = getchar()) == EOF)
      break;
    if (i < lim - 1){
      s[j] = c;
      j++;
    }
  }
  if (c == '\n') {
    s[j] = c;

    ++j;
  }
  s[j] = '\0';
  return i;
}
