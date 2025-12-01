#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void deletebeg()
{
  if (head == NULL)
    return;
  struct Node *temp = head;
  head = head->next;
  free(temp);
}

void deleteval(int v)
{
  if (head == NULL)
    return;

  if (head->data == v)
  {
    deletebeg();
    return;
  }

  struct Node *temp = head;

  while (temp->next != NULL && temp->next->data != v)
  {
    temp = temp->next;
  }

  if (temp->next == NULL)
    return;

  struct Node *target = temp->next;
  temp->next = target->next;
  free(target);
}

void deletelast()
{
  if (head == NULL)
    return;

  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }

  struct Node *temp = head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }

  free(temp->next);
  temp->next = NULL;
}

void display()
{
  struct Node *t = head;
  printf("Items: ");
  while (t != NULL)
  {
    printf("%d ", t->data);
    t = t->next;
  }
  printf("\n");
}

void inputsll()
{
  int n, x;
  printf("Enter number of nodes: ");
  scanf("%d", &n);

  struct Node *tail = NULL;
  head = NULL;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
      exit(1);

    p->data = x;
    p->next = NULL;

    if (head == NULL)
    {
      head = tail = p;
    }
    else
    {
      tail->next = p;
      tail = p;
    }
  }
}

int main()
{
  int choice, v;

  inputsll();
  display();
  printf("\n");

  printf("Delete at:\n1. Beginning\n2. Last\n3. Value\n4. Display\n5. Exit\n");

  while (1)
  {
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      deletebeg();
      break;
    case 2:
      deletelast();
      break;
    case 3:
      printf("Enter value: ");
      scanf("%d", &v);
      deleteval(v);
      break;
    case 4:
      display();
      break;
    case 5:
      return 0;
    default:
      break;
    }
    printf("\n");
  }
}
