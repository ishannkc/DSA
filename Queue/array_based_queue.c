#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
//initially queue is empty
int front = -1;
int rear = -1;

bool isEmpty();
bool isFull();

void EnQueue(int x){
    if (isFull()){
        printf("Queue is Full\n");
    }
    else if(isEmpty()){
        //if stack is empty, both front and rear index are 0;
        printf("Queue is empty, initializing front and rear index!\n");
        front = rear = 0;
    }
    else{
        rear++;
    }
    A[rear] = x;//element is enqueued from rear/tail in queue
    
}
void DeQueue(){
    if(isEmpty()){
        printf("Queue is empty! Nothing to Dequeue\n");
    } else if(front == rear){
        //if only one element in the queue, set front and rear index to -1, i.e empty queue
        front = rear = -1;
    }   
    else{
        front ++;//element is deqeued by incrementing front/head index
    }
}
int Front(){
    printf("Element at front(which can deqeued): %d\n", A[front]);
    return A[front];
}
int Rear(){
    printf("Element at rear: %d\n", A[rear]);
    return A[rear];
}
bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    } else{
        return false;
    }
}
bool isFull(){
    if(rear == MAX_SIZE-1){
        return true;
    } else {
        return false;
    }
}
void print(){
    printf("Queue: ");
    //traverse from front to rear as queue extends from front to rear
    for(int i = front; i<=rear; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main(){

    EnQueue(2);
    EnQueue(3);
    EnQueue(5);
    EnQueue(7);
    print();

    DeQueue();
    print();

    Front();
    Rear();


    return 0;
}
