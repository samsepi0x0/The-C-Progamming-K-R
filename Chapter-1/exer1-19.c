#include <stdio.h>
#define MAXLENGTH 1000

int getLine(char s[], int lim);
void reverseLine(char s[], int lim);

int main() {
  int len;
  char line[MAXLENGTH];

  while ((len = getLine(line, MAXLENGTH)) > 0) {
    reverseLine(line, len);
    printf("%s", line);
  }

  return 0;
}

int getLine(char s[], int lim) {
  int i, c;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void reverseLine(char line[], int len) {
  for(int i = 0; i < len/2; i++) {
    char c = line[i];
    line[i] = line[len-2-i];
    line[len-2-i] = c;
  }
}
