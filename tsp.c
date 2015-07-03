#include <stdlib.h>
#include <stdio.h>

int **a, n, sum1, sum2, *v1, *v2;

void nearest_neighbour(int src)
{
  int count, v, min, city, u;

  city = src;
  v1[city] = 1;
  count = 1;
  printf("%d -> ", src);

  while (count <= n - 1) {

    min = 999;

    for (v = 0; v < n; v++) {
      if (v1[v] != 1 && a[city][v] != 0 && a[city][v] < min) {
        min = a[city][v];
        u = v;
      }
    }

    sum1 += min;
    city = u;
    v1[city] = 1;
    count++;

    printf("%d -> ", city);

  }

  sum1 += a[city][src];
  printf("%d\n", src);
  printf("Cost : %d\n", sum1);

}

int main()
{
  int i, j, src;

  printf("Number of cities : ");
  scanf("%d", &n);

  a = calloc(n, sizeof(int *));
  for (i = 0; i < n; i++) {
    a[i] = calloc(n, sizeof(int));
  }

  v1 = calloc(n, sizeof(int));
  v2 = calloc(n, sizeof(int));

  sum1 = 0;
  sum2 = 0;

  printf("Cost Matrix : \n");
  for(i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Starting city : ");
  scanf("%d", &src);

  printf("Approximate : \n");
  nearest_neighbour(src);

  return 0;
}