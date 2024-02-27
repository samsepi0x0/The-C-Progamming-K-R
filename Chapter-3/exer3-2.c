#include <stdio.h>
#define MAXLEN 1000

int getLine(char s[], int lim);
void copy(char from[], char to[], int len);
void reverseCopy(char from[], char to[], int len);

int main() {
  int c, len;
  char line[MAXLEN];
  char modifiedLine[MAXLEN];
  while ((len = getLine(line, MAXLEN)) > 0) {
    copy(line, modifiedLine, len);
    reverseCopy(modifiedLine, line, len);
    printf("Copied: %s\n", modifiedLine);
    printf("RCopied: %s", line);
  }
  return 0;
}

int getLine(char s[], int lim) {
  int i, c;
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

void copy(char from[], char to[], int len) {
  int i, j;
  for(i = 0, j = 0; i < len; i++) {
    char c = from[i];
    switch (c){
      case '\n':
        to[j++] = '\\';
        to[j++] = 'n';
        break;
      case '\t':
        to[j++] = '\\';
        to[j++] = 't';
        break;
      default:
        to[j++] = c;
    }
  }
}

void reverseCopy(char from[], char to[], int len) {
  int i = 0, j = 0;
  while (from[i]) {
    switch(from[i]) {
      case '\\':
        switch(from[++i]) {
          case 'n':
            to[j] = '\n';
            break;
          case 't':
            to[j] = '\t';
            break;
          default:
            to[++j] = '\\';
            to[j] = from[i];
        }
        break;
      default:
        to[j] = from[i];
    }
    ++i;
    ++j;
  }
}
