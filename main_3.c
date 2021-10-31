#include <math.h>
#include <stdio.h>
#include <intrin.h>



int main()
{
 int N, M;
 scanf("%d %d", &N, &M);
 gsl_matrix *I = gsl_matrix_calloc(N, N);
 gsl_matrix* A = gsl_matrix_calloc(N, N);
 for (int i = 0; i < N; i++)
 {
  for (int ii = 0; ii < N; ii++)
  {
   gsl_matrix_set(A, i, ii, rand() % 101;);
  }
 }
 for (int i = 0; i < N; i++)
 {
  for (int ii = 0; ii < N; ii++)
  {
   if (i == ii)
   {
    gsl_matrix_set(I, i, ii, 1);
   }
  }
 }
 gsl_matrix* B = gsl_matrix_calloc(N, N);
 gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1, A, I, 0, B);
 float a1 = gsl_matrix_norm1(A);
 gsl_matrix* AT = gsl_matrix_calloc(N, N);
 gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1, A, I, 0, AT);
 float aInf = gsl_matrix_norm1(AT);
 gsl_matrix* BN = gsl_matrix_calloc(N, N);
 gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1/(a1 * aInf), B, I, 0, BN);
 gsl_matrix_memcpy(B, BN);
 gsl_matrix* R = gsl_matrix_alloc(N, N);
 gsl_matrix_memcpy(R, I);
 gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, -1, B, A, 1, R);
 gsl_matrix* AMO = gsl_matrix_calloc(N, N);
 gsl_matrix* AMON = gsl_matrix_calloc(N, N);
 gsl_matrix* NT = gsl_matrix_calloc(N, N);
 gsl_matrix* NTN = gsl_matrix_calloc(N, N);
 gsl_matrix_memcpy(AMO, I);
 gsl_matrix_memcpy(NT, R);
 for (int i = 0; i < m; i++)
 {
  gsl_matrix_add(AMO, NT);
  gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1, NT, R, 0, NTN);
  gsl_matrix_memcpy(NT, NTN);
 }
 gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1, AMO, B, 0, AMON);
 gsl_matrix_memcpy(AMO, AMON);
 
 return 0;
}
