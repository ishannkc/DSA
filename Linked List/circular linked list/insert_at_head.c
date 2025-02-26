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
    if(head==NULL){
        temp->next = temp; //if list is empty it should circle back and point to itself
        head = temp;
        return;
    }
    Node* tail = head; //traversal of temporary variable tail which stores address of end node
    while(tail->next!=head){//traversing to the last node
        tail = tail->next;
    }
    temp->next = head; //new node becomes the head
    head = temp; 
    tail->next = temp; //end node address is now pointing to the new added node

}
void print(){
    Node* temp = head;
    printf("List is: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp!=head);
    printf("\n");
}
int main(){
    head = NULL;

    insert(2);
    insert(4);
    insert(7);
    print();

    return 0;
}