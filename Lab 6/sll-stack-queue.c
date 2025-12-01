#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int info;
  struct Node *next;
};

struct Node *stackHead = NULL;
struct Node *queueHead = NULL;

struct Node *stackPush(struct Node *head, int value)
{
  struct Node *newnode;

  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->info = value;
  newnode->next = head;

  head = newnode;
  return head;
}

struct Node *stackPop(struct Node *head)
{
  struct Node *temp;

  if (head == NULL)
  {
    printf("Stack Underflow\n");
    return head;
  }

  temp = head;
  printf("Popped: %d\n", temp->info);
  head = head->next;
  free(temp);

  return head;
}

void displayStack(struct Node *head)
{
  if (head == NULL)
  {
    printf("Stack Empty\n");
    return;
  }

  printf("Stack: ");
  while (head != NULL)
  {
    printf("%d ", head->info);
    head = head->next;
  }
  printf("\n");
}

struct Node *enqueue(struct Node *head, int value)
{
  struct Node *newnode, *current;

  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->info = value;
  newnode->next = NULL;

  if (head == NULL)
  {
    head = newnode;
    return head;
  }

  current = head;
  while (current->next != NULL)
    current = current->next;

  current->next = newnode;
  return head;
}

struct Node *dequeue(struct Node *head)
{
  struct Node *temp;

  if (head == NULL)
  {
    printf("Queue Underflow\n");
    return head;
  }

  temp = head;
  printf("Dequeued: %d\n", temp->info);
  head = head->next;
  free(temp);

  return head;
}

void displayQueue(struct Node *head)
{
  if (head == NULL)
  {
    printf("Queue Empty\n");
    return;
  }

  printf("Queue: ");
  while (head != NULL)
  {
    printf("%d ", head->info);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  int choice, value;

  printf("1. Stack Push\n2. Stack Pop\n3. Stack Display\n4. Enqueue\n5. Dequeue\n6. Queue Display\n7. Exit\n");
  while (1)
  {
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value: ");
      scanf("%d", &value);
      stackHead = stackPush(stackHead, value);
      break;

    case 2:
      stackHead = stackPop(stackHead);
      break;

    case 3:
      displayStack(stackHead);
      break;

    case 4:
      printf("Enter value: ");
      scanf("%d", &value);
      queueHead = enqueue(queueHead, value);
      break;

    case 5:
      queueHead = dequeue(queueHead);
      break;

    case 6:
      displayQueue(queueHead);
      break;

    case 7:
      return 0;

    default:
      printf("Invalid Choice\n");
    }

    printf("\n");
  }
}
