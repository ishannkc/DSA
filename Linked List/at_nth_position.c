#include <stdlib.h>
#include <stdio.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;

Node* head;

void insert(int x, int pos){
    Node* temp1 = (Node*)malloc(sizeof(Node));//new node created
    temp1->data = x;
    temp1->next = NULL; //making the new node position to the end
    if(pos == 1){ //if position to insert is at first, then the first node should be the HEAD
        temp1->next = head;
        head = temp1;
        return; //exits the function
    } 
    Node* temp2 = head; //traverse
    for(int i = 0 ; i<pos-2; i++){  //traverse until the pos-1 node, as we need to update the pos-1th node address
        temp2 = temp2->next; //move to next node
    }
    temp1->next = temp2->next; //link new node to the pos node
    temp2->next = temp1; //link pos-1 node to new node

}

void print(){
    Node* temp = head;
    printf("Updated list: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    head = NULL; //initially, list is empty
    int size, num, position;
    printf("Enter size: ");
    scanf("%d", &size);
    for(int i =0; i<size; i++){
        printf("Enter the number and its position: ");
        scanf("%d%d", &num,&position);

        insert(num,position);
        print();
    
    }

}