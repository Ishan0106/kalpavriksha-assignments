#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear  = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int ele) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;
    if (isEmpty()) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("No element to remove.\n");
        return;
    }

    printf("Dequeued element: %d\n", front->data);
    struct node* temp = front;
    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }
}


void peek() {
    if (isEmpty()) {
        printf("No element to peek.\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

void display() {
    if (isEmpty()) {
        printf("No element to display.\n");
        return;
    }

    struct node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void size() {
    struct node* temp = front;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Queue size: %d\n", count);
}

int main() {
    int choice;

    printf("Queue operations\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Size\n6. Exit\n");

    while (1) {
        printf("Enter operation (1-6): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int ele;
            printf("Enter element to enqueue: ");
            scanf("%d", &ele);
            enqueue(ele);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            peek();
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            size();
        } else if (choice == 6) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid operation. Please enter a valid option.\n");
        }
    }

    return 0;
}
