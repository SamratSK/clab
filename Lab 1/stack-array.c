#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int arr[MAX];
int top = -1;

void push(int n)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow: Unable to push element\n");
    }
    else
    {
        top++;
        arr[top] = n;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow: Unable to pop element\n");
        return -1;
    }
    else
    {
        int el = arr[top];
        top--;
        return el;
    }
}

void display()
{
    printf("Stack: ");
    if (top == -1)
    {
        printf("Empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int n, e;

    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &e);
            push(e);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
        printf("\n");
    }
    return 0;
}