#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
    struct nodeblock* prev;
}Node;
Node* head;

void insert(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    //newly added node prev is always NULL
    temp->prev = NULL; 
    temp->next = head;
    //when list is not empty, and for proper structure of a doubly linked list
    if(head!=NULL){
        head->prev = temp; //head->prev is the previous pointer of the current head node
    }
    head = temp;
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
void Reverse(){
    //left to do;
}
int main(){
    head = NULL;//initially list is empty

    insert(1);
    insert(2);
    insert(3);
    insert(7);
    print();
}