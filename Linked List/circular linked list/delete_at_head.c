#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;

Node* head;
void insert(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    if(head==NULL){
        temp->next = temp;
        head = temp;
        return;
    }
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
    }
    temp->next = head;
    head = temp;
    tail->next = temp;
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
    Node* tail = head;
    while(tail->next!=head){
        tail = tail->next;
    }
    head = temp->next;
    tail->next = head;
    free(temp);
}
int main(){
    head = NULL;

    insert(2);
    insert(4);
    insert(6);
    print();

    delete();
    print();
    
    return 0;
}