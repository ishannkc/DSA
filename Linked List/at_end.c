#include <stdlib.h>
#include <stdio.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;

Node* head;


void insertEnd(int x){
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = x;
    temp1->next = NULL;
    //newly created node should be in the beginning
    if(head == NULL){
        head = temp1;
        return;
    }
    //if list not empty, traverse to the last node
    Node* temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    //attach new node to last node
    temp2->next = temp1; //since temp2(former end node) is traversed node to the end, former end node's  address needs to be modified with the newly added node
}
void print(){
    Node* temp = head;
    printf("New list is: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    head = NULL; 

    int size, num;
    printf("Enter the size: ");
    scanf("%d", &size);
    for(int i = 0; i<size; i++){
        printf("Enter the number: ");
        scanf("%d", &num);
        
        insertEnd(num);
        print();
    }
}