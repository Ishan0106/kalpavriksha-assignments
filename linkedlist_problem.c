/*
Create a linked list containing integers. Write a function to find the middle element of the
linked list and then reverse the second half of the list. Merge the
two halves alternately into a single list.

Total Time Complexity:
𝑂(𝑛)
Space Complexity:
𝑂(1)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseList(Node *head)
{
    Node *prev = NULL, *current = head, *next = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *mergeLists(Node *first, Node *second)
{
    Node *dummy = createNode(0);
    Node *current = dummy;

    while (first && second)
    {
        current->next = first;
        first = first->next;
        current = current->next;

        current->next = second;
        second = second->next;
        current = current->next;
    }
    if (first)
        current->next = first;
    if (second)
        current->next = second;

    Node *mergedHead = dummy->next;
    free(dummy);
    return mergedHead;
}

void printList(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    Node *middle = findMiddle(head);
    Node *secondHalf = reverseList(middle->next);
    middle->next = NULL;

    printf("First Half: ");
    printList(head);
    printf("Reversed Second Half: ");
    printList(secondHalf);

    Node *mergedList = mergeLists(head, secondHalf);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
