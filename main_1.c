#include <stdio.h>
#include <stdlib.h>



void transpose_matrix(float **arr1, float **arr2, int size) {
  int i, j;
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      arr2[j][i] = arr1[i][j];
  
}

void mult_matrix(float **A, float **B, float **C, int N)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < N; k++)
            C[i][j] += A[i][k] * B[k][j];
        }
}

void sum_matrix(float **A, float **B, float **C, int N)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
        
}

void sub_matrix(float **A, float **B, float **C, int N)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            C[i][j] = A[i][j] - B[i][j];
        
}

void mult_scalar_matrix(float **A, float **B, float k, int N)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            B[i][j] = A[i][j] * k;
}

float max_sum_line(float** A, int N)
{
    float max = 0;
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += A[i][j];
        }
        if (sum > max) max = sum;
        sum = 0;
    }
    return max;
}

float max_sum_column(float** A, int N)
{
    float max = 0;
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += A[j][i];
        }
        if (sum > max) max = sum;
        sum = 0;
    }
    return max;
}

int main() 
{
    int N, M;

    scanf("%d %d", &N, &M);

    float **A = (float**)malloc(sizeof(float*) * N);
    float **tmp = (float**)malloc(sizeof(float*) * N);
    float **tmp2 = (float**)malloc(sizeof(float*) * N);
    float **AT = (float**)malloc(sizeof(float*) * N);
    float **I = (float**)malloc(sizeof(float*) * N);
    float **R = (float**)malloc(sizeof(float*) * N);
    float **Answer = (float**)malloc(sizeof(float*) * N);
    for (int i = 0; i < N; i++)
    {
        A[i] = (float*)malloc(sizeof(float) * N);
        tmp[i] = (float*)malloc(sizeof(float) * N);
        tmp2[i] = (float*)malloc(sizeof(float) * N);
        AT[i] = (float*)malloc(sizeof(float) * N);
        I[i] = (float*)malloc(sizeof(float) * N);
        R[i] = (float*)malloc(sizeof(float) * N);
        Answer[i] = (float*)malloc(sizeof(float) * N);
        for (int j = 0; j < N; j++)
        {
            A[i][j] = rand() % 101;
            Answer[i][j] = 0;
            if (i == j) I[i][j] = 1.0;
        }
    }
    
    transpose_matrix(A, AT, N);
    float k = max_sum_column(A, N) * max_sum_line(A, N);

    mult_scalar_matrix(AT, AT, 1.0/k, N); //B
    mult_matrix(AT, A, tmp, N); //BA
    sub_matrix(I, tmp, R, N); //R
    sum_matrix(Answer, I, Answer, N);
    mult_scalar_matrix(R, tmp, 1, N);
    sum_matrix(Answer, R, Answer, N);
    for (int i = 0; i < M-1; i++)
    {
        mult_matrix(tmp, R, tmp2, N);
        mult_scalar_matrix(tmp2, tmp, 1, N);
        sum_matrix(Answer, tmp, Answer, N);
    }
    mult_matrix(Answer, AT, tmp, N);
    mult_scalar_matrix(tmp, Answer,1,N);

    for (int i = 0; i < N; i++)
    {
        free(A[i]) ;
        free(tmp[i]) ;
        free(tmp2[i]);
        free(AT[i]);
        free(I[i]);
        free(R[i]);
        free(Answer[i]);
    }
    free(A) ;
    free(tmp); 
    free(tmp2);
    free(AT);
    free(I);
    free(R);
    free(Answer);
    printf("ready!");

}