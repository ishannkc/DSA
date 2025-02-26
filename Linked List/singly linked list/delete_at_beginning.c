#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock
{
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
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete(){
    Node* temp = head;
    head = temp->next;
    free(temp);
}
int main(){
    head = NULL;

    printf("Before deletion: \n");
    insert(2);
    insert(1);
    insert(10);
    insert(7);
    print();

    printf("After deletion: \n");
    delete();
    print();
}
