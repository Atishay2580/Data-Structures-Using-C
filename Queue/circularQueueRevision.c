#include<stdio.h>
#define SIZE 10

typedef struct{
    int front;
    int rear;
    int data[SIZE];
}circularQueue;

circularQueue queue;

void init(){
    queue.front = queue.rear = -1;
}

int isFull(){
    // rear ki next position par agar front mil jaaye toh iska matlab queue full hai
    return ((queue.rear+1)%SIZE == queue.front);
}

int isEmpty(){
    return queue.front == -1;
}
void enQueue(int value){
    if(isFull()){
        printf("Cicular Queue is full, insertion not possible\n");
        return;
    }
    else{
        queue.rear = (queue.rear + 1) % SIZE;
        // Agar circular queue khaali hai aur rear is at index 0 (i.e. enqueueing the first element in an empty queue) toh phir front ko bhi -1 se 0 index par lekar aao.
        if(isEmpty()){
            queue.front = 0;
        }
        queue.data[queue.rear] = value;
    }
}

void deQueue(){
    if(isEmpty()){
        printf("Cicular Queue is empty, deletion not possible\n");
        return;
    }
    else{
        int temp = queue.data[queue.front];
        if(queue.front == queue.rear) // only one element remaining in queue
        { 
            init();
        }
        else{
            queue.front = (queue.front + 1) % SIZE;
        }
        printf("%d removed successfully\n", temp);
    }
}

void show(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    else{
        printf("Numbers are: ");
        int i = queue.front;

        do{
            printf("%d ", queue.data[i]);
            i = (i + 1) % SIZE;
        }while(i != queue.rear + 1);
    }
}

int main(){
    init();
    enQueue(99);
    enQueue(86);
    deQueue();
    deQueue();

    enQueue(30);
    enQueue(40);
    enQueue(50);
    enQueue(60);
    enQueue(70);
    show();
    

    return 0;
}
