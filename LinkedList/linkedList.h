#include <stdio.h>
#include <malloc.h>

struct Node
{
    int info;
    struct Node *next;
};

void show(struct Node *temp) // To display the list
{   
    printf("\nList Elements are: \n");
    while (temp != NULL)
    {
        printf("%d --> ", temp->info);
        temp = temp->next;
    }
    printf("NULL");
}

void addBeg(struct Node **s, int value) // addBeg(Start,value)
{
    // creating newNode using DMA
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // set the given data in the newly created node 
    newNode->info = value;

    if (*s == NULL) // start == Null -> Empty list condition
        newNode->next = NULL;
    else // Not an empty list -> contains atleast one node
        newNode->next = *s;

    *s = newNode; // start now points to new inserted node

    printf("Node is added\n");
}

void addLast(struct Node **s, int value) // addLast(start,value)
{   
    // creating newNode using DMA
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // set the given data in the newly created node
    newNode -> info = value;
    newNode -> next = NULL;

    struct Node *temp = *s;

    if(*s == NULL){   // linked list is empty
        *s = newNode; 
        return;
    }    
    while(temp -> next != NULL){
        temp = temp -> next; // traversing till last node 
    }
    temp -> next = newNode; // inserting the newNode at last
}

void addAfter(struct Node **s, int element, int value) // addAfter(start,element,value)
{
    // creating  a temporary pointer for traversal
    struct Node *temp = *s;

    if(*s == NULL){ // list is already empty
        printf("List is Empty\n");
        return;
    }
    // treverse to search the element next to which newNode is to be inserted
    while(temp != NULL){ 
        if(temp -> info == element) break;
        temp = temp -> next;
    }

    if(temp == NULL){ // Element not found in the list
        printf("Not found");
        return;
    }
    else // Element found -> insert node afert the node containing element
    { 
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode -> info = value;
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void delBeg(struct Node **s) // delBeg(start)
{
    // check if the list is already empty
    if(*s == NULL){  
        printf("Empty list, cannot delete\n");
        return;
    }

    // creating a temp pointer
    struct Node *temp = *s; 
    // shifting start to the second node
    *s = (*s) -> next; 
    // deleting the first/prev node
    free(temp); 
    printf("Node deleted\n");
}

void delLast(struct Node **s) // delLast(start)
{
    // check if the list is already empty
    if(*s == NULL){ 
        printf("Empty list, cannot delete\n");
        return;
    }
    // if the list has only one node
    if((*s) -> next == NULL){
        *s = NULL;
        return;
    }

/*  struct Node *temp = *s;
    while (temp -> next -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
*/
        // OR
    
    // creating two pointers to keep a track of current and previous node while deletion
    struct Node *prev, *curr; 
    // Initially prev points to the first node and curr to the next node 
    curr = (*s) -> next;
    prev = *s;
    // traversing the list until curr points last node and prev points to second last node
    while(curr -> next != NULL){
        curr = curr -> next;
        prev = prev -> next;
    }
    // deleting last node pointed by curr
    free(curr);
    // set the second last node as last node i.e. secondLast[next] = Null
    prev -> next = NULL;
}

void delInfo(struct Node **s, int info) // delInfo(start,info)
{
    struct Node *temp;
    // check if list is empty
    if(*s == NULL){ 
        printf("Empty List\n");
        return;
    }
    if((*s) -> info == info){ // info found at first node
        temp = *s;
        *s = (*s) -> next; // shifting start pointer to next node
        free(temp); // deleting node containing info
        printf("Node deleted\n");
        return;
    }

    // using two pointers for node deletion
    struct Node *prev, *curr; 
    // Initializing these pointers
    prev = *s;
    curr = (*s) -> next;
    // Search for node containing info
    while(curr != NULL)
    {
        // info found
        if(curr -> info == info) break; 
        // else keep traversing
        curr = curr -> next;
        prev = prev -> next;
    }
    // traversal complete 

    // info not present in the list
    if(curr == NULL){
        printf("%d info not found\n",info);
    }
    else
    {
        // delete the node containing info
        prev -> next = curr -> next;
        free(curr);
        printf("Node deleted\n");
    }

}