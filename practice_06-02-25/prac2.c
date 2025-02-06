#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void push(node** head, int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

void pop(node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    free(temp);
}

void peek(node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", (*head)->data);  // Fix: Use (*head)->data to access the data
}

void display(node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = *head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int choice;
    do {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int val;
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(&head, val);
        } else if (choice == 2) {
            pop(&head);
        } else if (choice == 3) {
            peek(&head);
        } else if (choice == 4) {
            display(&head);
        }
    } while (choice != 5);

    return 0;
}
