#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//same as insertion/deletion at head of singly linked list
typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;
Node* top; // instead of head, we can use top to represent stack clearly

bool isFull();
bool isEmpty();
void push(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    if(isFull()){   
        printf("Stack overflow\n");
        return;
    }
    temp->next = top;
    top = temp;
}
void pop(){
    Node* temp = top;
    if(isEmpty()){ //if list is empty, nothing to delete
        printf("Stack underflow!\n");
        return;
    }
    top = temp->next;
    free(temp);
}
void print(){
    Node* temp = top;
    printf("Stack: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int Top(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("Top elemet: %d\n", top->data);
    return top->data;
}
bool isEmpty(){
    if(top==NULL){  
        return true;
    } else {
        return false;
    }
}
bool isFull(){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        return true;
    } else {
        return false;
    }
}
int main(){
    top = NULL; //initially list is empty

    push(1);
    push(2);
    push(7);
    print();

    pop();
    print();
    isEmpty();
    isFull();
    Top();

    return 0;
}