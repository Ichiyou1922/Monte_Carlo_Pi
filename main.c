#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int cul_mult(int s, int n) {
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= s;
  }
  return ans;
}

int Middle_Square_Method(int n, int s) {
  if (n % 2 != 0) {
    printf("Failed to culculate\n");
    exit(1);
  }
  int s_square = s * s;
  int half = n / 2;
  int div = cul_mult(10, half);
  int mod = cul_mult(10, n);

  int middle = (s_square / div) % mod;
  return middle;
}


double Monte_Carlo_Method(int max_iter, int n, int s0) {
  int count = 0;
  int M = cul_mult(10, n); 
  int state = s0;

  for (int i = 0; i < max_iter; i++) {
    state = Middle_Square_Method(n, state);
    int cur_x = state;
    state = Middle_Square_Method(n, state);
    int cur_y = state;

    double x = (double)cur_x / M;
    double y = (double)cur_y / M;

    if (x * x + y * y <= 1.0) {
      count++;
    }
  }
  double pi = 4.0 * ((double)count / (double)max_iter);
  return pi;
}


int main() {
  //int s = 123;
  //printf("square=%d\n", cul_mult(s, 2));
  //int ans = Middle_Square_Method(4, s);
  //printf("ans=%d\n", ans);
  int max_iter = 100;
  int n = 4;
  int s = 1234;
  double pi = Monte_Carlo_Method(max_iter, n, s);
  printf("ans=%f\n", pi);
  return 0;
}
