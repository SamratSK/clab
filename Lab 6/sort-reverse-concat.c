#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->info = val;
    n->next = NULL;
    return n;
}

void printList(struct Node* head) {
    struct Node* t = head;
    if (t == NULL) {
        printf("Empty\n");
        return;
    }
    while (t != NULL) {
        printf("%d ", t->info);
        t = t->next;
    }
    printf("\n");
}

struct Node* acceptListDynamic() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* node = createNode(val);
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

struct Node* sort(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;

    int swapped = 1;
    while (swapped) {
        swapped = 0;
        struct Node* curr = head;

        while (curr->next != NULL) {
            if (curr->info > curr->next->info) {
                int temp = curr->info;
                curr->info = curr->next->info;
                curr->next->info = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
    }
    return head;
}

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
    return head;
}

struct Node* concat(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;

    struct Node* curr = head1;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = head2;
    return head1;
}

int main(void) {
    printf("List 1: \n");
    struct Node* head1 = acceptListDynamic();

    printf("\nList 2: \n");
    struct Node* head2 = acceptListDynamic();

    struct Node* merged = concat(head1, head2);
    printf("\nConcat: ");
    printList(merged);

    merged = sort(merged);
    printf("Sorted: ");
    printList(merged);

    merged = reverse(merged);
    printf("Reverse: ");
    printList(merged);

    return 0;
}
