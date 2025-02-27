#include <stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1; //initially stack is empty

void push(int x){
    //overflow control
    if(top == MAX_SIZE-1){
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    A[top] = x; //A[top] is the stack
}
void pop(){
    if(top == -1){
        printf("Stack underflow, Nothing to POP!\n");
        return;
    }
    top--;
}
int Top(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n ",A[top]);
    return A[top];
}
int IsEmpty(){
    if(top==-1){
        printf("Stack is empty!");
        return 1;
    } else {
        printf("Stack is not empty!");
        return 0;
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