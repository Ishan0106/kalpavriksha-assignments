#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
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
}

int linearSearch(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0; 
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 
    int n, value, key;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value); 
    }

    printf("Linked List: ");
    displayList(head);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    if (linearSearch(head, key)) {
        printf("Key %d is present in the linked list.\n", key);
    } else {
        printf("Key %d is not present in the linked list.\n", key);
    }

    return 0;
}