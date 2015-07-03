#include <stdlib.h>
#include <stdio.h>

int **a, n, *p, **sel;

void make_union(int i, int j)
{
  int k;

  if (i < j) {
    p[j] = i;
    for (k = 0; k < n; k++) {
      if (p[k] == j) {
        p[k] = i;
      }
    }
  } else {
    p[i] = j;
    for (k = 0; k < n; k++) {
      if (p[k] == i) {
        p[k] = j;
      }
    }
  }
}

void kruskals(int src)
{
  int i, j, u, v, min, count, k, sum;

  count = 0;
  k = 0;
  sum = 0;

  while (count < n - 1) {

    min = 999;

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][j] < min) {
          min = a[i][j];
          u = i;
          v = j;
        }
      }
    }

    i = p[u];
    j = p[v];

    if (i != j) {
      sel[k][0] = u;
      sel[k][1] = v;
      sum += a[u][v];
      k++;
      count++;
      make_union(u, v);
    }

    a[u][v] = a[v][u] = 999;

  }

  if (count == n - 1) {
    printf("Spanning Tree exists. The selected edges are : \n");
    for (i = 0; i < n - 1; i++) {
      printf("%d -- %d\n", sel[i][0], sel[i][1]);
    }
    printf("The sum is %d.\n", sum);
  } else {
    printf("Spanning Tree does not exist.\n");
  }

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

  p = calloc(n, sizeof(int));

  sel = calloc(n, sizeof(int *));
  for (i = 0; i < n; i++) {
    sel[i] = calloc(2, sizeof(int));
  }

  for (i = 0; i < n; i++) {
    p[i] = i;
  }

  printf("The elements : \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  kruskals(0);

  return 0;
}