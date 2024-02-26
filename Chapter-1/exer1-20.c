// this is comment 1
#include <stdio.h>
#define MAXLENGTH 1000
#define N 4

// this is comment 2

int getLine(char s[], int lim);

/* this is 
  comment 3*/

int main() {
  int c, len;
  char line[MAXLENGTH];

  while ((len = getLine(line, MAXLENGTH)) > 0) {
    int sp = 1;
    for(int i = 0 ; line[i] != '\0'; i++) {
      if (line[i] == '\t'){
        while ((sp % N) != 0){
          putchar(' ');
          sp++;
        }
      } else {
        putchar(line[i]);
      }
    }
  }

  return 0;
}

int getLine(char s[], int lim) {
  int i, c;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}
