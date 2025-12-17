#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *insert(struct Node *root, int val)
{
  if (root == NULL)
  {
    struct Node *newn = (struct Node *)malloc(sizeof(struct Node));
    newn->data = val;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
  }

  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  return root;
}

void inorder(struct Node *root)
{
  if (root == NULL)
    return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(struct Node *root)
{
  if (root == NULL)
    return;

  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct Node *root)
{
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main()
{
  struct Node *root = NULL;
  int choice, val;
  printf("1. Insert");
  printf("\n2. Preorder");
  printf("\n3. Inorder");
  printf("\n4. Postorder");
  printf("\n5. Display (Inorder)");
  printf("\n6. Exit");
  
  while (1)
  {
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value: ");
      scanf("%d", &val);
      root = insert(root, val);
      break;

    case 2:
      printf("Preorder: ");
      preorder(root);
      printf("\n");
      break;

    case 3:
      printf("Inorder: ");
      inorder(root);
      printf("\n");
      break;

    case 4:
      printf("Postorder: ");
      postorder(root);
      printf("\n");
      break;

    case 5:
      printf("Display (Inorder): ");
      inorder(root);
      printf("\n");
      break;

    case 6:
      exit(0);

    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}
