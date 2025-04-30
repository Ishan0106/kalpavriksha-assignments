#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a new node and add it to the linked list
void createnode(node** head, int value) {
    node* new_node = (node*)malloc(sizeof(node));  // Create a new node
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {  // If the list is empty, new_node becomes the head
        *head = new_node;
    } else {
        node* temp = *head;
        // Traverse the list to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;  // Add the new node at the end
    }
}

// Function to display the linked list
void display(node* head) {
    node* temp = head;  // Start from the first node
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Print the data in the current node
        temp = temp->next;  // Move to the next node
    }
    printf("NULL\n");  // Indicate the end of the list
}

int main() {
    node* head = NULL;  // Initialize head as NULL

    int n, i;
    scanf("%d", &n);  // Read the number of elements to insert

    for (i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);  // Read each value
        createnode(&head, val);  // Pass a pointer to the head to modify it
    }

    display(head);  // Display the linked list

    return 0;
}
