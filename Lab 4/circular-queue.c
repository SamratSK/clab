#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int i)
{
  if ((front == 0 && rear == MAX - 1) || ((rear + 1) % MAX == front))
  {
    printf("Queue Overflow\n");
    return;
  }
  else if (front == -1)
  {
    front = 0;
  }

  rear = (rear + 1) % MAX;
  queue[rear] = i;
  printf("Inserted %d\n", i);
}

void dequeue()
{
  if (front == -1)
  {
    printf("Queue Empty\n");
    return;
  }

  int r = queue[front];

  if (front == rear)
  {
    front = rear = -1;
  }
  else
  {
    front = (front + 1) % MAX;
  }

  printf("Deleted %d\n", r);
}

void display()
{
  if (front == -1)
  {
    printf("Empty\n");
    return;
  }

  printf("Items: ");
  int i = front;

  while (i != rear)
  {
    printf("%d ", queue[i]);
    i = (i + 1) % MAX;
  }
  printf("%d\n", queue[rear]);
}

int main()
{
  int c, i;
  int e = 0;

  printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");

  while (1)
  {
    printf("Choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
      printf("Element: ");
      scanf("%d", &i);
      enqueue(i);
      break;

    case 2:
      dequeue();
      break;

    case 3:
      display();
      break;

    case 4:
      e = 1;
      break;
    }

    if (e)
      break;

    printf("\n");
  }

  return 0;
}
