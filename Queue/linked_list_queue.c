#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;
Node* front;
Node* rear;


bool isEmpty();
void enQueue(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
     if(isEmpty()){
        printf("Queue is Empty! Initializing front and rear index with the newNode\n");
        front = rear = temp;
    } else {
        rear->next = temp; //enqueue is done from rear index 
        rear = temp;
    }
}
void deQueue(){
    Node* temp = front; //dequeue is done from front index
    if(isEmpty()){
        printf("Queue is empty, nothing to dequeue!");
    } else if(front == rear){//if only 1 element in the queue
        front = rear = NULL;
    } else{
        front = front->next;
    }
    free(temp);
}
bool isEmpty(){
    if(rear == NULL && front == NULL){
        return true;
    } else {
        return false;
    }
}
int Front(){
    printf("Front element(which can be dequeued): %d\n " ,front->data);
    return front->data;
}
int Rear(){
    printf("Rear element: %d\n ", rear->data);
    return rear->data;
}
void print(){
    Node* temp = front; //traverse from front which is the head
    while(temp!= rear ){ //from front to rear as rear is the end which holds NULL, i.e temp!=NULL
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    front = rear = NULL;//initially the list is empty

    enQueue(2);
    enQueue(5);
    enQueue(18);
    enQueue(28);
    print();

    deQueue();
    print();

    isEmpty();
    
    Front();
    Rear();
}