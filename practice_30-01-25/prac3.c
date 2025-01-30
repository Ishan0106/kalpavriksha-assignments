#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char* sentence;
    int** twoDarray;
}mystr;

int main(){
    mystr* s = (mystr*)malloc(sizeof(mystr));
    s->sentence = "hello world";
    int rows = 5 , cols = 5;
    s->twoDarray = (int**)malloc(rows*sizeof(int*));
    for(int i = 0 ; i < rows ; i++){
        s->twoDarray[i] = (int*)malloc(cols*sizeof(int));
    }
    int counter = 1;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            s->twoDarray[i][j] = counter++;
        }
    }
    printf("%s\n",s->sentence);
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            printf("%d\t",s->twoDarray[i][j]);
        }
        printf("\n");
    }
    return 0;
}