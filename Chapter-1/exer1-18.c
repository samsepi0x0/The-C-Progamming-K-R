#include <stdio.h>
#define MAXLENGTH 1000

int getLine(char s[], int lim);
void removeBlanks(char line[], int len);

int main() {
  int len;
  char line[MAXLENGTH];

  while ((len = getLine(line, MAXLENGTH)) > 0) {
    removeBlanks(line, len);
    printf("%s", line);
  }

  return 0;
}

int getLine(char s[], int lim) {
  int i, c;
  int wc = 0;
  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n'){
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

void removeBlanks(char line[], int len) {
  for(int i = 0; i < len; i++){
    if (line[i] == ' ' || line[i] == '\t')
      line[i] = '\b';
    else 
      i = len + 1;
  }
}
