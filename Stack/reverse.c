#include <stdio.h>
#define MAXSIZE 101

int A[MAXSIZE];
int top = -1;

void push(int x){
    top++;
    A[top]= x;
}
int pop(){
    return A[top--];
}
void ReverseList(int arr[], int n){
    //push all elements to stack
    for(int i=0; i<n; i++){
        push(arr[i]);
    }
    //pop all elements out of stack(LIFO) and store it back to the arr
    for(int i=0; i<n; i++){
        arr[i] = pop();
    }
}
void print(int arr[], int n){
    printf("Stack: ");
    for(int i =0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before reversing: \n");
    print(arr,n);

    ReverseList(arr,n);

    printf("After reversing: \n");
    print(arr,n);
}

