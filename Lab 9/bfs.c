#include <stdio.h>

int graph[20][20], visited[20], n;

void BFS(int start)
{
  int queue[20], front = 0, rear = 0;
  int node;

  visited[start] = 1;
  queue[rear++] = start;

  while (front < rear)
  {
    node = queue[front++];
    printf("%d ", node);

    for (int i = 0; i < n; i++)
    {
      if (graph[node][i] == 1 && !visited[i])
      {
        visited[i] = 1;
        queue[rear++] = i;
      }
    }
  }
}

int main()
{
  int start;

  printf("Number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);

  for (int i = 0; i < n; i++)
    visited[i] = 0;

  printf("Enter starting vertex: ");
  scanf("%d", &start);

  printf("BFS: ");
  BFS(start);

  return 0;
}
