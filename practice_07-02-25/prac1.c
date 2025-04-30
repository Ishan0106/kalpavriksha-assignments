#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct {
    node* arr[MAX];
} hashmap;

void init(hashmap* h) {
    for(int i = 0; i < MAX; i++) {
        h->arr[i] = NULL;
    }
}

int hashfnc(int key) {
    return key % 10;
}

void insert(hashmap* h, int key, int value) {
    int index = hashfnc(key);
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (h->arr[index] == NULL) {
        h->arr[index] = newnode;
    } else {
        node* temp = h->arr[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void search(hashmap* h, int key) {
    int index = hashfnc(key);
    if (h->arr[index] == NULL) {
        printf("No value is associated with this key\n");
        return;
    } else {
        printf("Values associated with the key are: ");
        node* temp = h->arr[index];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void delete(hashmap* h, int key, int value) {
    int index = hashfnc(key);
    if (h->arr[index] == NULL) {
        printf("No value is associated with this key\n");
        return;
    } else {
        node* temp = h->arr[index];
        if (temp->data == value) {
            h->arr[index] = temp->next;
            temp->next = NULL;
            free(temp);
            printf("Successfully deleted\n");
            return;
        }
        node* prev = NULL;
        int flag = 0;
        while (temp != NULL) {
            if (temp->data == value) {
                flag = 1;
                prev->next = temp->next;
                temp->next = NULL;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (flag == 0) {
            printf("No value is associated with this key\n");
        } else {
            printf("Successfully deleted\n");
        }
    }
}

void display(hashmap* h) {
    for (int i = 0; i < MAX; i++) {
        if (h->arr[i] == NULL) {
            printf("key %d : values : No values there\n", i);
        } else {
            node* temp = h->arr[i];
            printf("key %d : values : ", i);
            while (temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main() {
    hashmap h;
    init(&h);
    int choice;
    do {
        printf("Hashmap operations\n");
        printf("1.insert\n");
        printf("2.search\n");
        printf("3.delete\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        if (choice == 1) {
            int key, value;
            printf("Enter key and value\n");
            scanf("%d %d", &key, &value); 
            insert(&h, key, value);
        } else if (choice == 2) {
            int key;
            scanf("%d", &key);
            search(&h, key);
        } else if (choice == 3) {
            int key, value;
            printf("Enter key and value\n");
            scanf("%d %d", &key, &value);
            delete(&h, key, value);
        } else if (choice == 4) {
            display(&h);
        }
    } while (choice != 5);

    return 0;
}
