#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *prev;
    struct Node *next;
};

struct Node *start = NULL;

void create() {
    int n, value, i;
    struct Node *newn, *temp;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return;

    start = NULL;

    printf("Enter nodes: ");
    for (i = 1; i <= n; i++) {
        if (scanf("%d", &value) != 1) return;

        newn = (struct Node *)malloc(sizeof(struct Node));
        if (!newn) return;

        newn->info = value;
        newn->prev = NULL;
        newn->next = NULL;

        if (start == NULL) {
            start = newn;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newn;
            newn->prev = temp;
        }
    }
}

void insert_left(int val, int key) {
    struct Node *temp = start, *newn;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }

    newn = (struct Node *)malloc(sizeof(struct Node));
    if (!newn) return;

    newn->info = val;
    newn->next = temp;
    newn->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newn;
    else
        start = newn;

    temp->prev = newn;
}

void delete_node(int key) {
    struct Node *temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct Node *temp = start;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, key;
    printf("1. Create\n2. Insert Left\n3. Delete\n4. Display\n5. Exit\n");

    while (1) {
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter key element: ");
                scanf("%d", &key);
                insert_left(val, key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_node(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }

    return 0;
}
