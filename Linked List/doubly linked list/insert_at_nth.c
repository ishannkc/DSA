#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
    struct nodeblock* prev;
}Node;
Node* head;

void insert(int x, int n){
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = x;
    temp1->next = NULL;
    temp1->prev = NULL;
    if(n==1){
        temp1->next = head;
        // maintain structure of doubly
        if(head!=NULL){
            head->prev = temp1;
        }
        head = temp1;
        return;
    }
    //traversal
    Node* temp2 = head;
    for(int i = 0; i<n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    //structure maintain
    if(temp2->next!=NULL){
        temp2->next->prev = temp1;
    }
    temp2->next = temp1;
    temp1->prev = temp2; //linking previous pointer of the new node to the n-1th traversed node
    
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

    insert(2,1);
    insert(4,2);
    insert(7,1);
    insert(9,3);
    print();

}