#include <stdio.h>
#include <limits.h>
#include <float.h>

float floatSize(unsigned char, unsigned, unsigned);
double doubleSize(unsigned char, unsigned, unsigned);

int main() {
  printf("Using Standard Headers:\n");
  printf("CHAR:\t%d\t%d\t%d\n", CHAR_BIT, CHAR_MIN, CHAR_MAX);
  printf("INT:\t%ld\t%ld\n", INT_MIN, INT_MAX);
  printf("LONG:\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
  printf("SHORT:\t%d\t%d\n", SHRT_MIN, SHRT_MAX);
  printf("SSIZE:\t%ld\n", SSIZE_MAX);
  printf("LLONG:\t%lu\t%lu\n", LLONG_MIN, LLONG_MAX);
  printf("ULLONG:\t%lu\n", ULLONG_MAX);

  printf("\nUsing Direct Computation:\n");

  unsigned char c;
  unsigned short s;
  unsigned int i;
  unsigned long l;
  unsigned long long ll;

  /* Char */
  c = ~0;
  c >>= 1;
  printf("Signed Char:\t%d\t%d\n", -c-1, c);
  printf("Unsigned Char:\t%d\t%d\n", 0, 2*c+1);
 
  /* Short */
  s = ~0;
  s >>= 1;
  printf("Signed Short:\t%d\t%d\n", -s-1, s);
  printf("Unsigned Short:\t%d\t%d\n", 0, 2*s+1);

  /* Int */
  i = ~0;
  i >>= 1;
  printf("Signed Integer:\t%d\t%d\n", -i-1, i);
  printf("Unsigned Integer:\t%d\t%ld\n", 0, 2*i+1);

  /* Long */
  l = ~0;
  l >>= 1;
  printf("Signed Long:\t%ld\t%ld\n", -l-1, l);
  printf("Unsigned Long:\t%d\t%llu\n", 0, 2*l+1);

  /* Long Long */
  ll = ~0;
  ll >>= 1;
  printf("Signed Long Long:\t%lld\t%lld\n", -ll-1, l);
  printf("Unsigned Long Long:\t%d\t%llu\n", 0, 2*ll+1);

  printf("\nFloating Point:\n");
  printf("Float:\t%g\t%g\n", floatSize(1, 0, 1), floatSize(0, ~0-1, ~0));
  printf("Double:\t%g\t%g\n", doubleSize(1, 0, 1), doubleSize(0, ~0-1, ~0));
  return 0;
}

double doubleSize(unsigned char s, unsigned exp, unsigned mantissa) {
  /*    1        11          52
   * | Sign | Exponent | Mantissa |*/
  unsigned long long d = (unsigned long long)(s != 0) << 63 | (unsigned long long)(exp & 0x7FF) << 52 | (unsigned) mantissa & 0xfffffffffffff;
  return *((double *) &d);
}

float floatSize(unsigned char s, unsigned int exp, unsigned int mantissa) {
  /*    1         8          23
   * | Sign | Exponent | Mantissa |*/
  unsigned f = (unsigned)(s != 0) << 31 | (unsigned)exp << 23 | (unsigned) mantissa & 0x7fffff;
  return *((float *) &f);
}
