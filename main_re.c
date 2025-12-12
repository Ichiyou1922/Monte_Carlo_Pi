#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


static uint32_t rng_state = 2463534242u;

static uint32_t xorshift32(void) {
  uint32_t x = rng_state;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  rng_state = x;
  return x;
}


static int rand_int(int M) {
  return (int)(((uint64_t)xorshift32() * (uint64_t)M) >> 32);
}


static double Monte_Carlo(int N, int M) {
  int R = M / 2;
  long long count = 0;

  for (int i = 0; i < N; i++) {
    int x = rand_int(M);
    int y = rand_int(M);

    long long dx = (long long)x - R;
    long long dy = (long long)y - R;

    if (dx*dx + dy*dy <= (long long)R*R) {
      count++;
    }
  }

  double ratio = (double)count / (double)N;
  double pi = 4.0 * ratio;

  printf("inside=%lld N=%d ratio=%.12f R=%d M=%d\n",
         count, N, ratio, R, M);
  return pi;
}


int main() {
  int M = 10000;
  int N = 1000000000;

  double pi = Monte_Carlo(N, M);
  printf("pi=%.12f\n", pi);

  return 0;
}
