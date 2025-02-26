#include <stdio.h>
#include <stdlib.h>
 
typedef struct nodeblock{
    int data;
    struct nodeblock* next;
    struct nodeblock* prev;
}Node;
Node* head;

void insert(int x){
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = x;
    temp1->next = NULL;
    temp1->prev = NULL;

    if(head == NULL){
        temp1->next = head;
        head = temp1;
        return;
    }
    //traverse to end
    Node* temp2 = head;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    //prev pointer of new node linked to the former end node temp2
    temp1->prev = temp2;
}
void print(){
    Node* temp = head;
    printf("List is: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    head = NULL;

    insert(2);
    insert(1);
    insert(3);
    print();

}