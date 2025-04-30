#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

int isFull(Queue *q) {
    if (q->rear == MAX - 1) {
        return 1;  
    }
    return 0;
}

int isEmpty(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        return 1;  
    }
    return 0;
}

void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("%d\n", q->arr[q->front]);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;  
    }
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = q->arr[q->front];
    q->front++;
    return dequeuedValue;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    int choice;
    do {
        printf("Queue operations\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int value;
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
        } else if (choice == 2) {
            int dequeuedValue = dequeue(&q);
            if (dequeuedValue != -1) {
                printf("Dequeued: %d\n", dequeuedValue);
            }
        } else if (choice == 3) {
            peek(&q);
        } else if (choice == 4) {
            display(&q);
        } else if (choice == 5) {
            break;
        }
    } while (choice != 5);

    return 0;
}
