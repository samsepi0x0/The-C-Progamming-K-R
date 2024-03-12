#include <stdio.h>
#include <string.h>
#define BUFFSIZE 100

void strCat(char *s, char *t) {
  while (*s) {
    s++;
  }
  
  while ((*s++ = *t++) != '\0');
}

int main() {
  char s[BUFFSIZE] = "Hello ";
  char t[BUFFSIZE] = "World.";
  strCat(s, t);
  printf("%s\n", s);
  return 0;
}
