#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int position, int value)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(int position, int newValue)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    temp->data = newValue;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position)
{
    if (position < 1 || head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int operation;
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            int x;
            scanf("%d", &x);
            insertAtEnd(x);
            break;
        }
        case 2:
        {
            int x;
            scanf("%d", &x);
            insertAtBeginning(x);
            break;
        }
        case 3:
        {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insertAtPosition(pos, x);
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            int pos, x;
            scanf("%d %d", &pos, &x);
            updateAtPosition(pos, x);
            break;
        }
        case 6:
        {
            deleteAtBeginning();
            break;
        }
        case 7:
        {
            deleteAtEnd();
            break;
        }
        case 8:
        {
            int pos;
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        }
        default:
            printf("Invalid operation\n");
            break;
        }
    }
    return 0;
}
