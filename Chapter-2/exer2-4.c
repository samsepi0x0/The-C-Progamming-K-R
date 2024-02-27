#include <stdio.h>
#include <stdbool.h>
#define MAXLENGTH 100

void squeeze(char s1[], char s2[]);

int main() {
  char c1[] = "ABCDE";
  char c2[] = "ABCde";
  squeeze(c1, c2);
  printf("%s\n", c1);
  return 0;
}


void squeeze(char s1[], char s2[]) {
  int i, j, k;
  for(i = 0, j = 0; s1[i] != '\0'; i++) {
    char c = s1[i];
    bool flag = false;
    for(k = 0; s2[k] != '\0'; k++) {
      char c2 = s2[k];
      if (c == c2) {
        flag = true;
        break;
      }
    }
    if(!flag)
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}
