#include <stdlib.h>
#include <stdio.h>

int **a, n, *visited, count = 0;

void dfs(int u)
{
  int v;

  visited[u] = 1;
  count++;

  for (v = 0; v < n; v++) {
    if (visited[v] != 1 && a[u][v] == 1) {
      dfs(v);
    }
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
  visited = calloc(n, sizeof(int));

  printf("Adjacency matrix : \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  dfs(0);

  if (count == n) {
    printf("Connectd Graph.\n");
  } else {
    printf("Disconnected Graph.\n");
  }

  return 0;
}