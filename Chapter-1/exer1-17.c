#include <stdio.h>
#define MAXLENGTH 1000

int getLine(char s[], int maxlength);

int main () {
  int len;
  char line[MAXLENGTH];

  while ((len = getLine(line, MAXLENGTH)) > 0)
    if (len > 80) {
      printf("%s\n", line);
    }

  return 0;
}

int getLine(char s[], int lim) {
  int i, c;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n'){
    s[i] = c;
    i++;
  }

  s[i] = '\0';
  
  return i;
}
