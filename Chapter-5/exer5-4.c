#include <stdio.h>
#include <string.h>
#define BUFFSIZE 100

int strLen(char *s) {
  char *p = s;
  while (*p){
    p++;
  }
  return p - s;
}

int strEnd(char *s, char *t) {
  s = s + strLen(s) - strLen(t);

  for(; *s == *t; s++, t++) {
    if (*s == '\0')
      return 1;
  }
  return 0;
}

int main() {
  char s[BUFFSIZE] = "Hello World. ";
  char t[BUFFSIZE] = "World.";
  int c = strEnd(s, t);
  printf("%d\n", c);
  return 0;
}
