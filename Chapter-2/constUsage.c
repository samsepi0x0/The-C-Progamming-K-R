#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
/* to array is copying items from "from" array, if the declaration is switched to const, the array becomes read only and throws error:
 * assignment of read-only location ‘*(to + (sizetype)i)’ */
void copy(char to[], const char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0)
    printf("%s", longest);
  return 0;
}

int getLine(char s[], int lim) {
  int c, i, j;
  for(i = 0, j = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
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

void copy(char to[], const char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
