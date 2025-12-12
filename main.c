#include <stdio.h>
#include <stdlib.h>


int cul_mult(int s, int n) {
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    ans *= s;
  }
  return ans;
}

int Middle_Square_Method(int n, int s) {
  int num = n / 2;
  if ((n - 1) % 2 == 0) {
    printf("Failed to culculate\n");
    exit(1);
  }
  int s_square = s * s;
  int tmp = cul_mult(10, 2 * n + 1) + s_square;
  printf("tmp=%d\n", tmp);
  int ans = (tmp % (int)cul_mult(10, 2*n-num+1)) / cul_mult(10, num+1);
  return ans;
}

/*
double Monte_Carlo_Method(int max_iter) {
  for (int i = 0; i < max_iter; i++) {
    
  }
}
*/

int main() {
  int s = 123;
  printf("square=%d\n", cul_mult(s, 2));
  int ans = Middle_Square_Method(4, s);
  printf("ans=%d\n", ans);
  return 0;
}
