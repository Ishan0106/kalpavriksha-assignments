#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

// Function to push a value onto the stack (linked list)
void push(node** head, int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

// Function to display the linked list (stack)
void display(node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
node* merge(node* first, node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data <= second->data) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
        return second;
    }
}

// Function to split the linked list into two halves
node* split(node* head) {
    node* fast = head;
    node* slow = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    node* second_half = slow->next;
    slow->next = NULL;
    return second_half;
}

// Function to perform merge sort on the linked list
void mergesort(node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Split the list into two halves
    node* second = split(*head);

    // Recursively sort both halves
    mergesort(head);
    mergesort(&second);

    // Merge the sorted halves
    *head = merge(*head, second);
}

int main() {
    node* head = NULL;

    // Input and push elements to the stack (linked list)
    printf("Enter 8 values to push onto the stack:\n");
    for (int i = 0; i < 8; i++) {
        int value;
        scanf("%d", &value);
        push(&head, value);
    }

    printf("Original Stack:\n");
    display(head);    

    // Perform merge sort
    mergesort(&head);

    printf("Sorted Stack:\n");
    display(head);

    return 0;
}
