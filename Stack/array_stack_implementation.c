#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1; //initially stack is empty

bool isFull();
bool isEmpty();
void push(int x){
    //overflow control
    if(IsFull()){
        printf("Stack overflow, stack is full\n");
    }
    else{
    top++;
    A[top] = x; //A[top] is the stack
    }
}
void pop(){
    if(isEmpty()){
        printf("Stack underflow, nothing to pop\n");
    } else{
    top--;
    }
}
int Top(){
    if(isEmpty()){
        printf("Stack underflow, no top element\n");
    } else {
    printf("Top element: %d\n ",A[top]);
    return A[top];
    }
}
bool isEmpty(){
    if(top==-1){
        return true;
    } else {
        return false;
    }
}
bool isFull(){
    if(top == MAX_SIZE-1){
        return true;
    } else {
        return false;
    }
}
void print(){
    printf("Stack: ");
    for(int i =0; i<=top; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

}
int main(){
    push(2);
    push(3);
    print();

    pop();
    print();

    Top();

    push(7);
    print();

}