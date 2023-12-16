#include<stdio.h>
#include<limits.h>
#define SIZE 10

typedef struct{
    int front;
    int rear;
    int data[SIZE];
}linearQueue;

linearQueue queue;

void reset(void){
    queue.front = -1;
    queue.rear = -1;
}

int isFull(){
    // queue is full if rear is at last index
    return queue.rear == SIZE - 1;
}

int isEmpty(){
    // queue is empty if front is equal to -1
    return queue.front == -1;
}

void enQueue(int value){
    // insert value only if the queue is not full
    if(isFull()){
        printf("Queue is full, insertion not possible\n");
        return;
    }
    queue.data[++queue.rear] = value;
    // for the first element front & rear should point to the same element
    if(queue.rear == 0) queue.front = 0;
}

void deQueue(){
    if(isEmpty()){
        printf("Queue is empty, deletion not possible\n");
        return;
    }
    // store the element at front
    int temp = queue.data[queue.front++];
    // the element is not actually deleted. we're just incrementing front pointer
    printf("\n%d removed successfully\n",temp);
    if(queue.front > queue.rear){ // now queue becomes empty
        reset();
    }
}

void show(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = queue.front;
    while(i <= queue.rear){
        printf(" %d",queue.data[i++]);
    }
}

// Queue follows FIFO(First in first out)
// Insertion from Rear and Deletion from Front
// Can be implemented using Array, structure or Linked List

int main(){
    // reset the value of front & rear bcuz default value of global variables(front,rear) is 0
    reset();
    enQueue(5);
    enQueue(3);
    enQueue(9);
    enQueue(6);
    enQueue(10);
    show();
    deQueue();
    show();
    return 0;
}