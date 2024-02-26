#include <stdio.h>

int main() {
  char ch[26];
  int c;

  while ((c = getchar()) != EOF) {
    if (c >= 65 && c <= 90) 
      ch[c - 'A']++;
    if (c >= 97 && c <= 122)
      ch[c - 'a']++;
  }
  
  for(int i = 0; i < 26; i++) {
    printf("%c: ", (char)(i+97));
    for(int j = 0; j < ch[i]; j++)
      printf("#");
    printf("\n");
  }

  return 0;
}
