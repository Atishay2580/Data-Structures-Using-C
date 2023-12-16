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
    // rear ke next element ki position par agar front mil jaaye toh iska matlab queue full hai
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
        // Agar queue khaali hai aur rear 0 index pe hai toh front ko 0 pe le aao i.e. enqueue element at first index
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