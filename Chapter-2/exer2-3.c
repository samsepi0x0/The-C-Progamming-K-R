#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH 100

int getLine(char s[], int lim);
int htoi(char s[], int len);

int main() {
  char line[MAXLENGTH];
  int len;

  while ((len = getLine(line, MAXLENGTH)) > 0) {
    printf("Int: %d\n", htoi(line, len));
  }

  return 0;
}

int getLine(char s[], int lim) {
  int i;
  int c;
  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c; 
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

int htoi(char s[], int len) {
  int num = 0;
  int i = 0;
  if ((s[i] == '0') && (s[i+1] == 'x' || s[i+1] == 'X'))
    i = 2;
  for(; i < len - 1; i++) {
    char c = s[i];
    if (isdigit(c))
      num = num * 16 + (c - '0');
    else if (c >= 'A' && c <= 'F')
      num = num * 16 + (c - 'A' + 10);
    else if (c >= 'a' && c <= 'f')
      num = num * 16 + (c - 'a' + 10);
    else {
      printf("\nInvalid hex number.\n");
      return -1;
    }
  }
  return num;
}
