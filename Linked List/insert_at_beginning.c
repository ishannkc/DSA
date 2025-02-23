#include <stdlib.h>
#include <stdio.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* next;
}Node;

Node* head;///global declaration to access anywhere, head stores the address of the first node, i.e HEAD NODE

void insert(int x){//function to insert node at the beginning
     Node* temp = (Node*)malloc(sizeof(Node)); //creates a new node
    temp->data = x;
    //since newly created node is inserted in the beginning, it should be the HEAD node
    temp->next = head;
    head = temp;
}

void print(){
    Node* temp1 = head; //to traverse starting from head 
    printf("New list is: ");
    while(temp1 != NULL){
        printf("%d ", temp1->data); //print the current node
        temp1 = temp1->next; // moving to the next node
    }
    printf("\n");

}

int main(){

    head = NULL; //list is empty in the beginning
    int size,num;

    printf("Enter size: ");
    scanf("%d", &size);
    for(int i = 0; i<size; i++){
        printf("Enter the number: ");
        scanf("%d", &num);

        insert(num);
        print();

    }


}