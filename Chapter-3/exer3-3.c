#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main() {
  char s1[] = "-a-z -5-5-6A-Z0-9";
  char s2[MAXLEN];
  
  printf("%s\n", s1);
  expand(s1, s2);
  printf("%s\n", s2);

  return 0;
}

void expand(char s[], char s2[]) {
  int i;
  int t;
  int N = strlen(s);
  for(i = 0, t = 0; i < N; i++) {
    char c = s[i+2];
    if ((s[i] >= 'a' && s[i+1] == '-' && s[i+2] <= 'z') ||
        (s[i] >= 'A' && s[i+1] == '-' && s[i+2] <= 'Z') ||
        (s[i] >= '0' && s[i+1] == '-' && s[i+2] <= '9')) {
      for(char ch = s[i]; ch < s[i+2]; ch++) {
        s2[t++] = ch;
      }
      i += 1;
    } else {
      s2[t++] = s[i];
    }
  }
  s2[t++] = '\0';
}
