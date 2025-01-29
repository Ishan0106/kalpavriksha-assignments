#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int value;
	struct node * next;
};

struct node* head1 = NULL;



struct node* createnode(int value)
{
	struct node* newnode = (struct node*)malloc( sizeof(struct node));
	newnode->value= value;
	newnode->next = NULL;
	return newnode;
}

void insertatend( struct node**head, int value)
{
	struct node* newnode= createnode(value);
	if(*head==NULL)
	{
		*head = newnode;
		return;
	}
	struct node* temp = *head;

	while(temp->next !=NULL)
	{
		temp= temp->next;
	}
	temp->next = newnode;

}

void displaySLL(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		printf("%d-",temp->value);
		temp= temp->next;
	}
	printf("\n");
}

struct node* swap(struct node*a, struct node*b)
{
	int temp= a->value;
	a->value= b->value;
	b->value=  temp;
}

void selectionsortSLL(struct node**head)
{
	struct node*temp = *head;

	struct node*min = NULL;

	while(temp->next!=  NULL)
	{
	    struct node*j = temp->next;
	    min = temp;
	    while(j!=NULL)
	    {
	        if(j->value< min->value)
	        {
	            min =j;
	        }
	        j=j->next;
	    }


	    if(min!=temp)
	    {
	    swap(min,temp);
	    }
	    temp = temp->next;
	}

}


int main()
{
    //1 ll
	char input[100];
	printf("Enter first LL:  ");
	fgets(input,sizeof(input),stdin);
	char * token;
	token= strtok(input," ");
	while(token!=NULL)
	{
		int num= atoi(token);
		insertatend(&head1,num);
		token= strtok(NULL," ");
	}

	


	selectionsortSLL(&head1);

	printf("\n After sorting:  ");
	displaySLL(head1);


}