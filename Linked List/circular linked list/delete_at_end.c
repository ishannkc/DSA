#include<stdlib.h>
#include<stdio.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;
Node* head;
void insert(int x){
    
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = x;
    if(head==NULL){
        temp1->next = temp1;
        head = temp1;
    } else{
    Node* tail = head;
    while(tail->next!=head){
        tail = tail->next;
         }
    temp1->next = head;
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
void delete(){
    Node* temp = head;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    Node* prev = NULL; //prev is the second last node
    while (temp->next!=head)
    {
        prev= temp;
        temp = temp->next;
    }
    prev->next = head; //after last node is removed, second last should point to head
    free(temp);
    
}
int main(){
    head = NULL;
    insert(1);
    insert(7);
    insert(6);
    insert(5);
    print();

    delete();
    print();

    return 0;
}