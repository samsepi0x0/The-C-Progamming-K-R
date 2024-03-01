#include <stdio.h>
#define MAXLEN 1000

int getLine(char s[], int lim);
int strindex(char s[], char pattern[]);

char pattern[] = "orem";

int main() {
  char line[MAXLEN];
  int found;

  found = 0;

  while (getLine(line, MAXLEN) > 0) {
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  }
  return found;
}

int getLine(char s[], int lim) {
  int c, i;
  i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int strindex(char s[], char pattern[]) {
  int i, j, k;

  for(i = 0; s[i] != '\0'; i++) {
    for(j = i, k = 0; pattern[k] != '\0' && s[j] == pattern[k]; j++, k++);
      if (k > 0 && pattern[k] == '\0')
        return i;
  }
  return -1;
}
