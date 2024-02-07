#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
    int info;
    struct Node *next;
};

// Here last node will conatain the address of first node
// In circular linked list we assume start points to the last node
// so we can move easily to the first node with the help of start -> next

void show(struct Node *start){
    struct Node *temp = start -> next; 
     do{
        printf("%d ", temp -> info);
        temp = temp -> next;
     }while(temp != start -> next);
    
     printf("%d ", temp -> info);

}

void addBeg(struct Node **s, int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> info = value;

    if(*s == NULL){
        newNode->next =newNode;
        *s = newNode;
        return;    
    }
    newNode -> next = (*s) -> next;
    (*s) -> next = newNode;
}

void addLast(struct Node **s, int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> info = value;
    if(*s == NULL){
        newNode -> next = newNode;
        *s = newNode;
        return;
    }
    newNode -> next = (*s) -> next;
    (*s) -> next = newNode;
    (*s) = newNode;
}

void delBeg(struct Node **s){
    struct Node *temp;
    if(*s == NULL){
        printf("Empty List\n");
        exit(1);
    }
    else if(*s == (*s) -> next)
    {
        free(*s);
    }
    else
    {
        temp = (*s) -> next;
        (*s) -> next = temp -> next;
        free(temp);
    }
}

void delLast(struct Node **s){

    if(*s == NULL) // Empty circular linked list
    {
        printf("List is Empty\n");
        return;
    }
    else if((*s) -> next == *s) // only one Node
    { 
        free(*s);
        *s = NULL;
    }
    else
    {
        struct Node *temp = (*s) -> next;
        while(temp -> next != *s){
            temp = temp -> next;
        }
        temp -> next = (*s) -> next;
        free(*s);
        *s = temp;
    }
}

int takeInput() // takes value as input from the user
{ 
    int value;
    printf("Enter any value: ");
    scanf("%d", &value);
    return value;
}

int main(){

    int choice;
    struct Node *start;
    do{
        printf("\nSingle linked list primitive operations:\n");
        puts("1 --> Insert at Begining");
        puts("2 --> Insert at Last");
        // puts("3 --> Insert at Between");
        puts("3 --> Delete from Begining");
        puts("4 --> Delete from Last");
        // puts("6 --> Delete info");
        puts("5 --> Show");
        puts("6 --> Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBeg(&start, takeInput());
            break;
        case 2:
            addLast(&start,takeInput());
            break;
        // case 3:
        //     addAfter(&start, takeInput(),takeInput());
        //     break;
        case 3:
            delBeg(&start);
            break;
        case 4:
            delLast(&start);
            break;
        // case 6:
        //     delInfo(&start, takeInput());
        //     break;
        case 5:
            show(start);
            break;

        case 6:
            printf("Coded by Atishay\n");
            break;
        
        default:
            printf("Invalid Input");
            break;
        }

    }while(choice != 6);
    
    return 0;
}