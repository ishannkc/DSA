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
    temp->next = head;
    head = temp;
}
void print(){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverse(){
    //current points to the node being processed
    //previous stores the previous node address to reverse the direction
    //next temporarily stores the next node address to not lose track of the reversal
    Node *current, *previous, *next;
    current = head; //current initialized to head which is the first node
    previous = NULL; //after reversal, first node will become last node, so to change it we set prev = NULL
    while(current!=NULL){ //traverse
        next = current->next; //save the next node address before moving to next
        current->next = previous; //reverse the direction

        previous = current;//move previous forward to the current node
        current = next; //move current forward to the next node
    }
    head = previous; //after reversing, head will point to NULL as first node becomes last node
}
int main(){

    head = NULL;
    printf("Before Reverse: ");
    insert(2);
    insert(5);
    insert(7);
    insert(66);
    print();

    printf("After Reverse: ");
    reverse();
    print();

    return 0;
}