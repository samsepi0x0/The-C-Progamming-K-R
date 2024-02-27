#include <stdio.h>

int  any(char[], char[]);

int main() {
  char c1[] = "ABCDE";
  char c2[] = "abcdEF";

  int pos = any(c1, c2);
  printf("%d\n", pos);
  return 0;
}
int any(char s1[], char s2[]) {
  int i, k;
  for(i = 0; s1[i] != '\0'; i++) {
    char c1 = s1[i];
    for(k = 0; s2[k] != '\0'; k++) {
      char c2 = s2[k];
      if (c1 == c2)
        return i;
    }
  }
  return -1;
}
