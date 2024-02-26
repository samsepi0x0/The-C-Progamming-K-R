#include <stdio.h>
#include <limits.h>

/* This results in overflow, enum only can number till int range
 enum YEARS {
   JAN=INT_MAX, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEPT, OCT, NOV, DEC
  }; */
enum YEARS {
  JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEPT, OCT, NOV, DEC
};

int main() {
  enum YEARS var = MAR;
  printf("%d\n", MAR);
  return 0;
}
