#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* result = NULL;

void createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct node* split(struct node* head)
{
    struct node*slow = head;
    struct node*fast= head;
    while(fast!=NULL &&fast->next!=NULL)
    {
        fast= fast->next->next;
        if(fast!=NULL)
        {
            slow= slow->next;
        }
    }
    struct node*second = slow->next;
    slow->next = NULL;
    return second;
}

struct node* merge(struct node*temp, struct node*second)
{

        if(temp==NULL) return second;
        if(second==NULL) return temp;

        if(temp->data<second->data)
        {
            temp->next = merge(temp->next,second);
            return temp;
        }
        else{
            second->next = merge(temp, second->next);
            return second;
        }
}

struct node* mergesortSLL(struct node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    struct node *second = split(head);

    head = mergesortSLL(head);
    second = mergesortSLL(second);
    return merge(head,second);
}

struct node* removeduplicate(struct node* temp){
    if(temp == NULL || temp->next == NULL){
        return temp;
    }
    temp->next = removeduplicate(temp->next);
    if(temp != NULL && temp->next != NULL && temp->data == temp->next->data){
        struct node* t = temp->next;
        temp->next = temp->next->next;
        free(t);
    }
    return temp;
}

void displaySLL(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp= temp->next;
	}
	printf("\n");
}

int main(){
    int n,i;
    printf("enter number of elements\n");
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        int val;
        scanf("%d",&val);
        createnode(val);
    }

    head = mergesortSLL(head);
    displaySLL(head);
    result = removeduplicate(head);
    displaySLL(result);
    return 0;
}