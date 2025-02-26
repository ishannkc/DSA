#include <stdio.h>
#include <stdlib.h>

typedef struct  nodeblock
{
    int data;
    struct nodeblock* next;
}Node;
Node* head;

void insert(int x){
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = x;
    temp1->next = NULL;
    if(head == NULL){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void print(){
    Node* temp = head;
    printf("List is: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete(){
    Node* temp1 = head;
    while(temp1->next->next != NULL){ //traverses to the second last node
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;//temp2 stores node to be deleted
    temp1->next = NULL; //after temp2 is deleted, the second last node(temp1) should be the last so temp1 will be NULL
    free(temp2);
}
int main(){
    head = NULL;

    printf("Before deletion: \n");
    insert(2);
    insert(5);
    insert(6);
    insert(99);
    print();

    printf("After deletion: \n");
    delete();
    print();

    return 0;
}
