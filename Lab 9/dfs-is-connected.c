#include <stdio.h>
#define MAX 20

int visited[MAX], adj[MAX][MAX], n;

void DFS(int v)
{
  visited[v] = 1;

  for (int i = 0; i < n; i++)
  {
    if (adj[v][i] == 1 && !visited[i])
    {
      DFS(i);
    }
  }
}

int isConnected()
{
  for (int i = 0; i < n; i++)
    visited[i] = 0;

  DFS(0);

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
      return 0;
  }
  return 1;
}

int main()
{
  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &adj[i][j]);

  if (isConnected())
    printf("Graph is connected");
  else
    printf("Graph is NOT connected");

  return 0;
}
