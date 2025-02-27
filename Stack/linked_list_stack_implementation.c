#include <stdlib.h>
#include <stdio.h>
//same as insertion/deletion at head of singly linked list
typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;
Node* top; // instead of head, we can use top to represent stack clearly
void push(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    if(temp == NULL){   
        printf("Stack overflow\n");
        return;
    }
    temp->next = top;
    top = temp;
}
void pop(){
    Node* temp = top;
    if(top == NULL){ //if list is empty, nothing to delete
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
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top elemet: %d\n", top->data);
    return top->data;
}
int isEmpty(){
    if(top==NULL){
        printf("Stack is empty\n");
        return 1;
    } else {
        printf("Stack is not empty\n");
        return 0;
    }
}
int isFull(){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        printf("Stack is FULL\n");
        return 1;
    } else {
        printf("Stack is not full\n");
        return 0;
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