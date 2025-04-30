// typedef struct Person
// {
//     char name[50];
//     int age;
//     char country[50];
// } Person;
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char strp[] = "<name>Dhruv</name><age>21</age><city>Bangalore</city>";
    //char* ptr = strp;
    char *token=strtok(strp,"><");
    int i = 1;
    while(token!=NULL){
        // printf("%s\n",token);
        // token=strtok(NULL,">/<");
        char key[50];
        char value[50];
        if(i%2==1){
            sscanf(token,"%s",key);
            token=strtok(NULL,"><");
           
        }
        else {
            sscanf(token,"%s",value);
             token=strtok(NULL,"><");
              token=strtok(NULL,"><");
              printf("%s:%s\n",key,value);

        }
        i++;

        //printf("%s:%s\n",key,value);
    }

    
   
  
}
 