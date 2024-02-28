#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  int n = 255;
  char s[MAXLEN];
  int b = 16;
  printf("%d\n", n);
  itob(n, s, b);
  printf("%s\n", s);
}

void itob(int n, char s[], int b) {
  int i, sign, c;
  
  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    c = n % b;
    if (c < 10) {
      s[i++] = c + '0';
    } else {
      s[i++] = 'A' + (c - 10);
    }
  } while ((n /= b) > 0);
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;
  for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
