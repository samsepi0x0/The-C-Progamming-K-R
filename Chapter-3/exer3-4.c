#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 1000

void reverse(char s[]) {
  int c, i, j;
  for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(long n, char s[]){
  int i, sign;

  if((sign = n) < 0) {
    n = -n; 
    // this line does not work when n = INT_MIN;
    //printf("  ## %d\n", n);
  }
  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while (n /= 10);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main() {
  int n = INT_MIN;
  char s[MAXLEN];
  printf("%d\n", n);
  itoa(n, s);
  printf("%s\n", s);
  return 0;
}
