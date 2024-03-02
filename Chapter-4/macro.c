#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define square(X) (X)*(X)
#define dprint(exp) printf(#exp " = %g\n", exp)
#define paste(front, back) front ## back
int main() {
  int x = max(10, 38);
  int y = square(5+1);
  int xy = x % y;
  printf("Max: %d\n", x);
  printf("Square: %d\n", y);
  dprint(x / y);
  printf("%d\n", paste(x, y));
  return 0;
}
