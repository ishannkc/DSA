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
    printf("List is: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void findLength(){
    int count = 0; //initialize count to 0
    Node* temp = head; //traverse
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    printf("Length is: %d", count);
}
int main(){
    head = NULL;

    insert(2);
    insert(5);
    insert(10);
    insert(100);
    insert(98);
    insert(7);
    insert(28);
    print();

    findLength();

    return 0;
}