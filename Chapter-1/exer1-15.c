#include <stdio.h>

double cels2fahr(double cels);

int main() {
  for(int i = -40; i <= 40; i += 20)
    printf("%d\t->\t%f\n", i, cels2fahr(i));
  return 0;
}

double cels2fahr(double cels) {
  return ((9.0/5.0) * (cels)) + 32;
}
