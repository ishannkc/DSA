#include <stdio.h>
#include<stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;
Node* head;
void insert(int x, int n){
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = x;
    if(n==1){
        if(head==NULL){
            temp1->next = temp1;
            head = temp1;
            return;
        }
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        temp1->next = head;
        head = temp1;
        tail->next = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i =0 ; i<n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void print(){
    Node* temp = head;
    printf("List is: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp!= head);

}
void delete(int n){
    Node* temp1 = head;
    if(n==1){
        if(head==NULL){
            printf("List is empty");
            return;
        }
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }
        head = temp1->next;
        tail->next = head;
        free(temp1);
        return;
    }
    for(int i =0; i<n-2; i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
int main(){
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(7,3);
    print();

    delete(1);
    print();
    return 0;
}