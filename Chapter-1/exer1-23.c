#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  bool multiComment = false;
  while ((len = getLine(line, MAXLINE)) > 0) {
    bool singleComment = false;
    for(int i = 0; i < len-1; i++) {
      char x = line[i];
      if (i == ' ')
        continue;
      if (x == '/' && line[i+1] == '/') {
        singleComment = true;
        break;
      }
      if (x == '/' && line[i+1] == '*') {
        multiComment = true;
        break;
      }
      if (x == '*' && line[i+1] == '/') {
        multiComment = false;
        singleComment = true;
        break;
      }
    }
    if (!singleComment && !multiComment)
      printf("%s", line);
  }
  return 0;
}

int getLine(char s[], int lim) {
  int c, i , j;
  for(i = 0, j = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < lim - 1) {
      s[i] = c;
      j++;
    }
  }
  if (c == '\n') {
    s[j] = c;
    j++;
  }
  s[j] = '\0';
  return j;
}
