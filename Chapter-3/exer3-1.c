#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(){
  int arr[10000];
  int x;
  for(int i = 0; i < 10000; i++)
    arr[i] = i;
  x = 93;
  printf("Element %d in array at: %d\n", x, binsearch(x, arr, 100));
  x = 10100;
  printf("Element %d in array at: %d\n", x, binsearch(x, arr, 100));
  return 0;
}

/* Binary search implementation given in K&R
int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else 
      return mid;
  }
  return -1;
}
*/

int binsearch(int x, int v[], int n) {
  int low, mid, high;
  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  while (low <= high && v[mid] != x) {
    if (x < v[mid])
      high = mid - 1;
    else 
      low = mid + 1;
    mid = (low + high) / 2;
  }
  return v[mid] == x ? mid : -1;
}
