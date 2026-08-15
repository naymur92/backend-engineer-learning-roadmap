#include <bits/stdc++.h>
using namespace std;

int main() {
  // Offset of int arrays
  int a[8] = {1, 2, 4, 8, 16, 32, 64, 128};

  for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
    printf("Offset of a[%d] = %d\n", i, (int)((char *)&a[i] - (char *)&a[0]));
  }
  printf("\n\n");

  // Offset of double arrays
  double b[8] = {1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0};

  for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
    printf("Offset of b[%d] = %d\n", i, (int)((char *)&b[i] - (char *)&b[0]));
  }
  printf("\n\n");

  // Offset of 12-byte struct arrays
  struct S {
    int a;
    int b;
    int c;
  } c[8];

  for (int i = 0; i < sizeof(c) / sizeof(c[0]); ++i) {
    printf("Offset of c[%d] = %d\n", i, (int)((char *)&c[i] - (char *)&c[0]));
  }

  return 0;
}