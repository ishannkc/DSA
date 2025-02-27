#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;
Node* head;
void insert(int x){
    //same as insert in head
   Node* temp1 = (Node*)malloc(sizeof(Node));
   temp1->data = x;
   if(head == NULL){
    temp1->next = temp1;
    head = temp1;
   }else{
    Node* tail = head;
    while(tail->next!=head){
        tail = tail->next;
    }
    temp1->next = head;
    head = temp1;
    tail->next = temp1;
   }
}
void print(){
    Node* temp = head;
    printf("List is: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp!=head);
 
}
int main(){
    head = NULL;

    insert(2);
    insert(7);
    insert(6);
    insert(10);
    print();

    return 0;
}