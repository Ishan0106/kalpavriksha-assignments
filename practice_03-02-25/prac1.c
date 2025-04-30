#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define Max 100

struct Movie_Node{
    char *movie_name;
    int amount;
    int screen_No;
    int seat_No;
    int status; //0->pending 1->approved
    struct Movie_Node* next;
};

struct Movie_Node* rear1 = NULL; // booking queue
struct Movie_Node* front1 = NULL;
struct Movie_Node* rear2 = NULL;  // approved queue
struct Movie_Node* front2 = NULL;

void enque(){
    struct Movie_Node* newNode = (struct Movie_Node*)malloc(sizeof(struct Movie_Node));
    newNode->status = 0;
    char name[100];
    int amt;
    int sc_no;
    int s_no;
    printf("enter movie name\n");
    scanf("%s",name);
    printf("enter amount\n");
    scanf("%d",&amt);
    printf("enter screen no\n");
    scanf("%d",&sc_no);
    printf("enter seat no\n");
    scanf("%d",&s_no);
    newNode->movie_name = (char*)malloc(strlen(name) + 1); 
    strcpy(newNode->movie_name, name);
    newNode->amount = amt;
    newNode->screen_No = sc_no;
    newNode->seat_No = s_no;
    if(rear1 == NULL){
        rear1 = newNode;
        front1 = newNode;
    }
    else{
        rear1->next = newNode;
        rear1 = rear1->next;
    }
}

void deque(){
    struct Movie_Node* temp = front1;
    front1 = front1->next;
    temp->next = NULL;
    temp->status = 1;
    if(rear2 == NULL){
        rear2 = temp;
        front2 = temp;
    }
    else{
        rear2->next = temp;
        rear2 = rear2->next;
    }
}

void display1(){
    printf("Booked queue\n");
    struct Movie_Node* move = front1;
    while(move != NULL){
        printf("{Movie:%s, amount:%d, screen_no:%d, seat_no:%d, status:%d}->",move->movie_name,move->amount,move->screen_No,move->seat_No,move->status);
        move = move->next;
    }
    printf("\n");
}

void display2(){
    if(rear2 == NULL){
        printf("No movie is there in Approved status\n");
        return;
    }
    printf("Approved queue\n");
    struct Movie_Node* mov = front2;
    while(mov != NULL){
        printf("{Movie:%s, amount:%d, screen_no:%d, seat_no:%d, status:%d}->",mov->movie_name,mov->amount,mov->screen_No,mov->seat_No,mov->status);
        mov = mov->next;
    }
    printf("\n");
}

int main(){
    int choice;
    do{
        printf("Movie Ticketing System\n");
        printf("1.Book the movie\n");
        printf("2.Approve the movie\n");
        printf("3.Booked queue display\n");
        printf("4.Approved queue display\n");
        printf("5.Exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        if(choice == 1){
            enque();
        }
        else if(choice == 2){
            deque();
        }
        else if(choice == 3){
            display1();
        }
        else if(choice == 4){
            display2();
        }
    }while(choice != 5);
}
