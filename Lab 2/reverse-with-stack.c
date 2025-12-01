#include <stdio.h>
#include <stdlib.h>

#define MAX 512

int st[MAX];
int top = -1;

void push(int n)
{
  if (top == MAX - 1)
  {
    printf("Stack Overflow\n");
    exit(1);
  }
  st[++top] = n;
}

int pop()
{
  if (top == -1)
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  return st[top--];
}

/* Reverse array using stack */
void rev(int *a, int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    push(*(a + i));
  }

  for (i = 0; i < n; i++, a++)
  {
    *a = pop();
  }
}

int main()
{
  int n, i;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];

  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  rev(arr, n);

  printf("Reversed elements: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}
