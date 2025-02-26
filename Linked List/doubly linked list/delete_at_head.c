#include <stdio.h>
#include <stdlib.h>

typedef struct  nodeblock
{
    int data;
    struct nodeblock* next;
    struct nodeblock* prev;
}Node;
Node* head;
void insert(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;
    if(head!=NULL){
        head->prev = temp;
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
void delete(){
    Node* temp = head;
    head = temp->next;
    if(head!=NULL){ //update the prev pointer of the 2nd node that becomes head
        head->prev = NULL;
    }
    free(temp);

}
int main(){
    head = NULL;
    insert(2);
    insert(4);
    insert(7);
    print();

    delete();
    print();
    
    return 0;
}
