#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};

void show(struct Node *start){
    if(start == NULL){
        printf("Empty List\n");
        return;
    }
    struct Node *temp = start;
    printf("Nodes are: ");
    do{
        printf("%d ", temp -> info);
        temp = temp -> next;
    }while( temp != NULL);
}

void addBeg(struct Node **s, int value){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> info = value;
    newNode -> prev = NULL;

    if(*s == NULL){
        newNode -> next = NULL;
    }
    else{
        newNode -> next = *s;
        (*s) -> prev = newNode;
    }
    *s = newNode;
    
}

void addLast(struct Node **s, int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> info = value;
    newNode -> next = NULL;

    if(*s == NULL){
        *s = newNode;
        newNode -> prev = NULL;
        return;
    } 

    struct Node *temp = *s;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
}

void addAfter(struct Node **s, int value, int info){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> info = value;

    struct Node *curr = *s;
    while(curr -> info != info){
            curr = curr -> next;
    }
    newNode -> prev = curr;
    newNode -> next = curr -> next;
    if(curr -> next == NULL)
    {
        curr -> next  = newNode;
    }
    else
    {
        curr -> next -> prev = newNode; // this step is done before the below step so that we do not loose the reference to node which is next to the newNode
        curr -> next = newNode;
    }
}

void addBefore(struct Node **s, int value, int info){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> info = value;

    struct Node *curr = *s;
    while(curr -> info != info){
            curr = curr -> next;
    }
    if(curr -> prev == NULL) // info is present at first node -> insertion before first node
    {
        newNode -> next = curr;
        curr -> prev = newNode;
        newNode -> prev = NULL;
        *s = newNode; // shifting start to newNode
        return;
    }
    newNode -> next = curr;
    newNode -> prev = curr -> prev;
    struct Node *back = curr -> prev;
    back -> next = newNode;
    curr -> prev = newNode;
}

void delBeg(struct Node **s){
    if(*s == NULL) // empty list
    {
        printf("Empty list, cannot delete\n");
        return;
    }
    struct Node *temp = *s;
    *s = (*s) -> next;
    (*s) -> prev = NULL;
    free(temp);
}

void delLast(struct Node **s){
    if(*s == NULL) // empty list
    {
        printf("Empty list, cannot delete\n");
        return;
    }
    struct Node *temp = *s;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    struct Node *back = temp -> prev;
    back -> next = NULL;
    free(temp);
}

void delNode(struct Node **s, int value){
    if(*s == NULL)
    {
        printf("Empty List, cannot delete\n");
        return;
    }
    struct Node *temp = *s;
    if((*s) -> info == value)
    {
        temp = *s;
        *s = (*s) -> next;
        free(temp);
        return;
    }
    while(temp != NULL)
    {
        if(temp -> info == value)
        {
            break;
        }
        temp = temp -> next;
    }
    if(temp == NULL)
    {
        printf("value not found\n");
        return;
    }
    else{
        struct Node *forward = temp -> next;
        temp -> next = forward -> next;
        if(forward -> next == NULL)
        {
            temp -> prev = NULL;
        }
        else
        {
            forward -> next -> prev = temp;
        }
        free(forward);
    }
}
// void delLast(struct Node **s){
//     if(*s == NULL) // empty list
//     {
//         printf("Empty list, cannot delete\n");
//         return;
//     }
//     struct Node *temp = *s;
//     while(temp -> next != NULL){
//         temp = temp -> next;
//     }
//     struct Node *back = temp -> prev;
//     back -> next = NULL;
//     free(temp);
// }

void delBefore(struct Node **s, int value){
    if(*s == NULL)
    {
        printf("Empty List, cannot delete\n");
        return;
    }
    struct Node *temp = *s;
    
    while(temp != NULL)
    {
        if(temp -> info == value)
        {
            break;
        }
        temp = temp -> next;
    }
    if(temp == NULL)
    {
        printf("value not found\n");
        return;
    }
    struct Node *back = temp;
    if(back -> prev = NULL)
    {
        temp -> prev = NULL;
        free(back);
        *s = temp;
    }
    else
    {
        temp -> prev = back -> prev;
        back -> prev -> next = temp;
        free(back);
    }
}

int main(){
    struct Node *start = NULL;
    addBeg(&start,100);
    addBeg(&start,200);
    addBeg(&start,300);
    show(start);
    
    return 0;
}