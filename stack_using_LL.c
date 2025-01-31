#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int size() {
    int count = 0;
    struct Node* tempStack = NULL; 

    while (!isEmpty()) {
        struct Node* temp = top;
        top = top->next;
        temp->next = tempStack;
        tempStack = temp;
        count++;
    }

    while (tempStack != NULL) {
        struct Node* temp = tempStack;
        tempStack = tempStack->next;
        temp->next = top;
        top = temp;
    }

   printf("size:%d \n ",count);
}

int main() {
    int choice;
    int value;

    while (1) {
        printf("Enter operation: 1 for push, 2 for pop, 3 for peek, 4 for display, 5 for size, 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            peek();
        } else if (choice == 4) {
            display();
        }else if(choice==5)
        {
            size();
        } 
        else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}