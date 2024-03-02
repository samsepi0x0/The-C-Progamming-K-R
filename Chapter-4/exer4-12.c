#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void itoa(int n, char s[], int base, int p) {
  if (n < 0) {
    s[p] = '-';
    n = -n;
  } else {
    if (n / base)
      itoa(n/base, s, base, p+1);
    int c = n % base;
    if (c < 10)
      s[p] = c + '0';
    else 
      s[p] = 'A' + (c - 10);
  }
}

void reverse(char s[], int i, int j) {
  if (i < j) {
    int c = s[i];
    s[i] = s[j];
    s[j] = c;
    reverse(s, i+1, j-1);
  }
}

int main(void) {
  int b = 10;
  char s[MAXLEN];
  int n = 255;
  printf("%d\n", n);
  itoa(n, s, b, 0);
  reverse(s, 0, strlen(s) - 1);
  printf("%s\n", s);
}


