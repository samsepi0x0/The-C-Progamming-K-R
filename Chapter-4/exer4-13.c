#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void reverse(char s[], int i, int j) {
  if (i < j) {
    int c = s[i];
    s[i] = s[j];
    s[j] = c;
    reverse(s, i+1, j-1);
  }
}

int main() {
  char s[] = "Lorem ipsum dolor sit amet, qui minim labore adipisicing minim sint cillum sint consectetur cupidatat.";
  printf("%s\n", s);
  reverse(s, 0, strlen(s) - 1);
  printf("%s\n", s);
  return 0;
}
