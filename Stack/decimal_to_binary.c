#include <stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int x){
    top ++;
    A[top] = x;
}
int pop(){
    return A[top--];
}
void DecimaltoBinary(int num){

    while(num!=0){ //run the loop unless the remainder is 0
        push(num%2);
        num = num/2;
    }
}
int isEmpty(){
    if(top==-1){
        return 1;
    } else{
        return 0;
    }
}
void print(){
    printf("Binary Equivalent: ");
    while(!isEmpty()){
        printf("%d ", pop()); 
    }
    printf("\n");
}
int main(){
    int num;
    printf("Enter the decimal number: ");
    scanf("%d", &num);

    DecimaltoBinary(num);
    print();

}