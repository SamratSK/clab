#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int info;
  struct Node *next;
};
struct Node *start = NULL;

struct Node *insertbeg(int value)
{
  struct Node *p = (struct Node *)malloc(sizeof(struct Node));
  p->info = value;
  p->next = start;
  start = p;
  return start;
}

struct Node *insertend(int value)
{
  struct Node *p = (struct Node *)malloc(sizeof(struct Node));
  p->info = value;
  p->next = NULL;

  if (start == NULL)
  {
    start = p;
  }
  else
  {
    struct Node *t = start;
    while (t->next != NULL)
      t = t->next;
    t->next = p;
  }
  return start;
}

struct Node *insertpos(int item, int pos)
{
  struct Node *p = (struct Node *)malloc(sizeof(struct Node));
  p->info = item;

  if (pos == 1)
  {
    p->next = start;
    start = p;
    return start;
  }

  struct Node *temp = start;
  for (int i = 1; i < pos - 1; i++)
  {
    if (temp == NULL)
    {
      printf("Invalid position\n");
      return start;
    }
    temp = temp->next;
  }

  p->next = temp->next;
  temp->next = p;
  return start;
}

void display()
{
  struct Node *t = start;
  if (t == NULL)
  {
    printf("List is empty\n");
    return;
  }
  while (t != NULL)
  {
    printf("%d ", t->info);
    t = t->next;
  }
  printf("\n");
}

int main()
{
  int c, i, p;
  int e = 0;

  printf("Insert at:\n1.Beginning\n2.End\n3.Position\n4.Display\n5.Exit\n");

  while (1)
  {
    printf("Choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
      printf("Element: ");
      scanf("%d", &i);
      start = insertbeg(i);
      break;

    case 2:
      printf("Element: ");
      scanf("%d", &i);
      start = insertend(i);
      break;

    case 3:
      printf("Element: ");
      scanf("%d", &i);
      printf("Position: ");
      scanf("%d", &p);
      start = insertpos(i, p);
      break;

    case 4:
      display();
      break;

    case 5:
      e = 1;
      break;
    }

    if (e)
      break;

    printf("\n");
  }

  return 0;
}
