#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode; 
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = newNode;
    newNode->prev = temp; 
}


struct Node* findMiddle(struct Node* start, struct Node* end) {
    if (start == NULL) return NULL;

    struct Node* slow = start;
    struct Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow; 
}


int binarySearch(struct Node* head, int key) {
    struct Node* start = head;
    struct Node* end = NULL;

    while (start != end) {
        struct Node* mid = findMiddle(start, end);

        if (mid == NULL) return 0;

        if (mid->data == key) {
            return 1;
        } else if (mid->data < key) {
            start = mid->next; 
        } else {
            end = mid; 
        }
    }

    return 0;
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter the number of elements in the doubly linked list: ");
    scanf("%d", &n);

    printf("Enter the sorted elements of the doubly linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value); 
    }

    printf("Doubly Linked List: ");
    displayList(head);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    if (binarySearch(head, key)) {
        printf("Key %d is present in the doubly linked list.\n", key);
    } else {
        printf("Key %d is not present in the doubly linked list.\n", key);
    }
    return 0;
}