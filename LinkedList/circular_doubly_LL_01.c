#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int info;
    struct Node *next;
    struct Node *prev;
}Node;

// Start will point to last node

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> info  = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

Node* search(Node *s, int info)
{
    Node *address = NULL;
    if(s == NULL)
    {
        return NULL;
    }
    // traverse list to find the address of node containing info
    Node *temp = s -> next;
    do{
        if(temp -> info == info)
        {
            return temp;
        }
        temp = temp -> next;
    }while(temp != s -> next);
    // info not present in the list
    return NULL;
}

void show(Node *s){
    // Empty List
    if(s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *temp = s -> next;
    do{
        printf("%d ", temp -> info);
        temp = temp -> next;
    }while(temp != s -> next);
}

void addBeg(Node **s, int value){
    Node *newNode = createNode(value);
    // If List is already empty
    if(*s == NULL)
    {
        newNode -> next = newNode;
        newNode -> prev = newNode;
        *s = newNode;
        return;
    }
    // Else -> Atleast one node is present in the list
    newNode -> next = (*s) -> next;
    (*s) -> next = newNode;
    newNode -> prev = *s;
    Node *temp = newNode -> next;
    temp -> prev = newNode;
    // or the above 2 lines can be also be combined as
    // newNode -> next -> prev = newNode;
}

void addLast(Node **s, int value)
{
    Node *newNode = createNode(value);
    // If the list is already empty
    if((*s) == NULL)
    {
        newNode -> next = newNode;
        newNode -> prev = newNode;
        *s = newNode;
        return;
    }
    // else -> List has atleast one node
    newNode -> next = (*s) -> next;
    (*s) -> next = newNode;
    newNode -> prev = *s;
    newNode -> next -> prev = newNode;
    *s = newNode;
}

void addAfter(Node **s, int info, int value)
{
    Node *temp = search(*s, info);
    // Node containing info not present
    if(temp == NULL)
    {
        printf("Info not found\n");
        return;
    }
    // Node containing info found
    Node *newNode = createNode(value);
    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    newNode -> prev = temp;
    temp -> next = newNode;
}

void delBeg(Node **s)
{
    if(*s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    if((*s) -> next == *s)
    {
        *s = NULL;
        return;
    }
    Node *temp = (*s) -> next;
    temp -> next -> prev = *s;
    (*s) -> next = temp -> next;
    free(temp);
}

void delLast(Node **s)
{
    if(*s == NULL)
    {
        printf("Empty List\n");
        return;
    }
    if((*s) -> next == *s)
    {
        *s = NULL;
        return;
    }
    Node *temp = (*s) -> prev;
    temp -> next -> prev = *s;
    (*s) -> next -> prev = temp;
    temp -> next = (*s) -> next;
    *s = temp;
    free(temp);
}

int main(){

    Node *start = NULL;
    addBeg(&start, 10);
    addBeg(&start, 20);
    addBeg(&start, 30);
    addBeg(&start, 40);
    addLast(&start,50);
    addLast(&start,60);
    addLast(&start,70);
    addAfter(&start,60,65);
    show(start);
    
    return 0;
}