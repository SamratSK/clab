#include <stdio.h>

#define MAX 5
int q[MAX];
int rear = -1, front = -1;

void enqueue(int i) {
    if(rear == MAX - 1) {
        printf("Queue full");
    } else if (front == -1)  {
        front = 0;
        rear = 0;
        q[rear] = i;
    } else {
        rear = rear + 1;
        q[rear] = i;
    }
}

int dequeue() {
    int i;
    if(front == -1) {
        printf("Queue empty");
        i = -1;
    } else if (front == rear)  {
        i = q[front];
        front = -1;
        rear = -1;
    } else {
        front = front + 1;
        i = q[front];
    }

    return i;
}

void display() {
    printf("Queue: ");
    if(front == -1) {
        printf("Empty\n");
    } else {
        int i;
        for(i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
    }
}

int main() {
    printf("Operations: \n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
    int c, e;

    while(1) {
        printf("Enter choice: ");
        scanf("%d", &c);

        if(c == 1) {
            printf("Enter element: ");
            scanf("%d", &e);
            enqueue(e);
        } else if(c == 2) {
            int r = dequeue();
        } else if(c == 3) {
            display();
        } else if(c == 4) {
            break;
        } else {
            printf("Invalid choice");
        }

        printf("\n\n");
    }

    return 0;
}
