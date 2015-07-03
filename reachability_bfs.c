#include <stdlib.h>
#include <stdio.h>

int **a, n, *visited, *q, f = 0, r = 0;

void bfs(int src)
{
  int u, v;

  q[r++] = src;
  visited[src] = 1;

  while (f < r) {
    u = q[f++];
    for (v = 0; v < n; v++) {
      if (visited[v] != 1 && a[u][v] == 1) {
        q[r++] = v;
        visited[v] = 1;
      }
    }
  }
}

int main()
{
  int i, j, src;

  printf("Number of vertices : ");
  scanf("%d", &n);

  a = calloc(n, sizeof(int *));
  for (i = 0; i < n; i++) {
    a[i] = calloc(n, sizeof(int));
  }
  visited = calloc(n, sizeof(int));
  q = calloc(n, sizeof(int));

  printf("Adjacency Matrix : \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Source Vertex : ");
  scanf("%d", &src);

  bfs(src);

  for(i = 0; i < n; i++) {
    if (visited[i] == 1) {
      printf("Vertex %d -- Reachable\n", i);
    } else {
      printf("Vertex %d -- Not Reachable\n", i);
    }
  }

  return 0;
}