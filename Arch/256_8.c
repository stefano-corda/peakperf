#include "256_8.h"

#define OP_PER_IT 8
#define FMA_AVAILABLE 2
#define SIZE OP_PER_IT*2

TYPE farr_256_8[MAX_NUMBER_THREADS][SIZE] __attribute__((aligned(64)));  

double get_gflops_256_8(int n_threads) {
  return (double)((long)n_threads*MAXFLOPS_ITERS*OP_PER_IT*(BYTES_IN_VECT/4)*FMA_AVAILABLE)/1000000000;        
}

void compute_256_8(TYPE *farr, TYPE mult, int index) {
  farr = farr_256_8[index];
  for(long i=0; i<MAXFLOPS_ITERS; i++) {
      farr[0]  = _mm256_fmadd_ps(mult, farr[0], farr[1]);
      farr[2]  = _mm256_fmadd_ps(mult, farr[2], farr[3]);
      farr[4]  = _mm256_fmadd_ps(mult, farr[4], farr[5]);
      farr[6]  = _mm256_fmadd_ps(mult, farr[6], farr[7]);
      farr[8]  = _mm256_fmadd_ps(mult, farr[8], farr[9]);
      farr[10] = _mm256_fmadd_ps(mult, farr[10], farr[11]);
      farr[12] = _mm256_fmadd_ps(mult, farr[12], farr[13]);
      farr[14] = _mm256_fmadd_ps(mult, farr[14], farr[15]);
    }
}
