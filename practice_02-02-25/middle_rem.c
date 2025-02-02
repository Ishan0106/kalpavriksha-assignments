#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    } else {
        struct Node* move = head;
        while(move->next != NULL) {
            move = move->next;
        }
        move->next = temp;
    }
}

// Function to remove the middle node
void removeMiddleNode(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return; // No middle to remove if the list is empty or has one element
    }

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;

    // Using slow and fast pointer technique to find the middle node
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Removing the middle node
    if (prev != NULL) {
        prev->next = slow->next;
        free(slow);  // Free the memory of the middle node
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        createNode(value);
    }

    printf("Initial Linked List:\n");
    printList(head);

    // Remove the middle node
    removeMiddleNode(head);
    
    printf("Linked List after removing middle node:\n");
    printList(head);

    return 0;
}
