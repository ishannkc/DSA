#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty();
bool isFull();

void enQueue(int x){
    if(isFull()){
        printf("Circular Queue is Full\n");
    } else if(isEmpty()){
        printf("Circular queue is empty, initializing front and rear index\n");
        front = rear = 0;
    } else{
        rear = (rear+1)%MAX_SIZE; // next position will be rear incremented by the remainder of the size of array so that unused space in the array can be used
    }
    A[rear] = x;
}
void deQueue(){
    if(isEmpty()){
        printf("Circular queue is empty, nothing to dequeue\n");
    } else if(front == rear){
        front = rear = -1;
    } else{
        front = (front+1)%MAX_SIZE;
    }
}
void Front(){   
    printf("Element at front(which can be dequeded) in circular array: %d\n" ,A[front]);
    return A[front];
}
void Rear(){
    printf("Element at rear\tail: %d\n", A[rear]);
    return A[rear];
}
bool isFull(){
    if(front == (rear+1)%MAX_SIZE){
        return true;
    } else {
        return false;
    }
}
bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    } else {
        return false;
    }
}
void print(){
    printf("Circular Queue: ");
    for(int i = front; i<=rear; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main(){
    enQueue(2);
    enQueue(7);
    enQueue(8);
    print();

    deQueue();
    print();

    Front();
    Rear();

    return 0;
}