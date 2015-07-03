#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int **a, n;

int min(int a, int b)
{
  return a < b ? a : b;
}

void floyds()
{
  int **b, i, j, k, tid;
  double start, end;

  b = calloc(n, sizeof(int *));
  for (i = 0; i < n; i++) {
    b[i] = calloc(n, sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      b[i][j] = a[i][j];
    }
  }

  omp_set_num_threads(2);
  start = omp_get_wtime();
  #pragma omp parallel for shared(b) private(i, j, k)

  for (k = 0; k < n; k++) {
    for (j = 0; j < n; j++) {
      for (i = 0; i < n; i++) {
        b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
        tid = omp_get_thread_num();
        printf("Thread %d: b[%d][%d] = %d\n", tid, i, j, b[i][j]);
      }
    }
  }

  end = omp_get_wtime();

  printf("All pair shortest distance matrix : \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d\t", b[i][j]);
    }
    printf("\n");
  }

  printf("Elasped Time : %lf\n", end - start);
}

int main()
{
  int i, j;

  printf("Number of vertices : ");
  scanf("%d", &n);

  a = calloc(n, sizeof(int *));
  for (i = 0; i < n; i++) {
    a[i] = calloc(n, sizeof(int));
  }

  printf("Distance Matrix : \n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  floyds();

  return 0;
}