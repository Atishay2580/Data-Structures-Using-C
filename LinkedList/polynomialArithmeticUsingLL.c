#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coe;
    int pow;
    struct Node *next;
};

struct Node *createNode(int coe, int pow){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> coe = coe;
    newNode -> pow = pow;
    newNode -> next = NULL;
    return newNode;

}

void addLast(struct Node **s, int coe, int pow){
    struct Node *newNode = createNode(coe ,pow);
    if(*s == NULL) // Empty list condition check
    { 
        *s = newNode;
    }
    else
    {
        // creating a temporary structure type pointer for traversing over the list
        struct Node *temp = *s;

        // traverses the list to find the last node and links the new node to it. 
        while(temp -> next != NULL)
        { 
            temp = temp -> next; // shift/move temp to the next node
        }

        temp -> next = newNode;  // linking the newNode at last
    }
}

void show(struct Node *temp){
    printf("%dx^%d ", temp -> coe, temp -> pow); // print the first term as it is.
    temp = temp -> next; // move the temp pointer to the next node
    while(temp != NULL){

        if(temp -> pow != 0){ // Not a constant term and contains x of degree pow

          if(temp -> coe >0){ // positive coefficient -> print term with '+' sign
            printf("+%dx^%d ", temp -> coe, temp -> pow);
          }
          else{ // Negative coefficient -> No need to print '-' sign manually
            printf("%dx^%d ", temp -> coe, temp -> pow);
          }

        }
        else{ // degree/power of variable is zero -> constant term

            if(temp -> coe > 0) // postive
                printf("+%d " , temp -> coe);
            else // Negative
                printf("%d " , temp -> coe);
        }
        temp = temp -> next; // shift the pointer to the next node
    }
    printf("\n");
}

struct Node *addPolynomial(struct Node *poly1, struct Node *poly2){
    struct Node *poly3 = NULL; // new linked list representing the sum of polynomials

    while(poly1 != NULL && poly2 != NULL){
        // comparing the powers of the current terms
        if(poly1 -> pow == poly2 -> pow) 
        {
           // add the coefficients and creates a new term in poly3
           addLast(&poly3 ,poly1 -> coe + poly2 -> coe, poly1 -> pow);
           poly1 = poly1 -> next;
           poly2 = poly2 -> next; 
        }
        else if(poly1 -> pow > poly2 -> pow) // power of the term in poly1 is greater
        {
            // add the term from poly1 to poly3
            addLast(&poly3, poly1 -> coe, poly1 -> pow);
            poly1 = poly1 -> next;
        }
        else // power of the term in poly2 is greater
        {
            addLast(&poly3, poly2 -> coe, poly2 -> pow);
            poly2 = poly2 -> next;
        }
    }
        // If one polynomial is longer than the other, add the remaining terms to poly3
        while(poly1 != NULL){
            addLast(&poly3, poly1 -> coe, poly1 -> pow);
            poly1 = poly1 -> next;
        }

        while(poly2 != NULL){
            addLast(&poly3, poly2 -> coe, poly2 -> pow);
            poly2 = poly2 -> next;
        }
    return poly3;
}

struct Node *subPolynomial(struct Node *poly1, struct Node *poly2){
    struct Node *poly4 = NULL;

    while(poly1 != NULL && poly2 != NULL){
        if(poly1 -> pow == poly2 -> pow){
           addLast(&poly4 ,poly1 -> coe - poly2 -> coe, poly1 -> pow);
           poly1 = poly1 -> next;
           poly2 = poly2 -> next; 
        }
        else if(poly1 -> pow > poly2 -> pow){
            addLast(&poly4, poly1 -> coe, poly1 -> pow);
            poly1 = poly1 -> next;
        }
        else{
            addLast(&poly4, -poly2 -> coe, poly2 -> pow);
            poly2 = poly2 -> next;
        }
    }
        while(poly1 != NULL){
            addLast(&poly4, poly1 -> coe, poly1 -> pow);
            poly1 = poly1 -> next;
        }

        while(poly2 != NULL){
            addLast(&poly4, -poly2 -> coe, poly2 -> pow);
            poly2 = poly2 -> next;
        }
    return poly4;
}

int main(){

    struct Node *poly1 = NULL;
    addLast(&poly1,2,5);
    addLast(&poly1,39,3);
    addLast(&poly1,-10,0);

    struct Node *poly2 = NULL;
    addLast(&poly2,10,4);
    addLast(&poly2,5,3);
    addLast(&poly2,20,1);
    addLast(&poly2,50,0);

    show(poly1);
    show(poly2);

    struct Node *poly3 = NULL;
    poly3 = addPolynomial(poly1, poly2);

    struct Node *poly4 = NULL;
    poly4 = subPolynomial(poly1, poly2);

    printf("polynomial addition: ");
    addPolynomial(poly1, poly2);
    show(poly3);

    printf("polynomial subtraction: ");
    addPolynomial(poly1, poly2);
    show(poly4);
    
    return 0;
}