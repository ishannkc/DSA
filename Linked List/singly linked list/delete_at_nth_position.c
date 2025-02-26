    #include <stdlib.h>
    #include <stdio.h>

    typedef struct nodeblock{
        int data;
        struct nodeblock* next;
    }Node;
    Node* head;
    void insert(int x, int pos){
        Node* temp1 = (Node*)malloc(sizeof(Node));
        temp1->data = x;
        temp1->next = NULL;
        if(pos==1){
            temp1->next = head;
            head = temp1;
            return;
        }
        Node* temp2 = head;
        for(int i=0; i<pos-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
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
    void delete(int n){
    Node* temp1 = head;//start from head
    if(n==1){
        head = temp1->next; //for first position, the former second position should be the first, i.e head
        free(temp1); //free space occupied by the deleted node
        return;
    }
    //traversing to the n-1th position which 
    for(int i = 0; i<n-2; i++){
        temp1 = temp1->next; //temp1 will now point at n-1th position 
    }
    Node* temp2 = temp1->next; //temp2 stores the node to be deleted
    temp1->next = temp2->next; //bypass the nth node by linking n-1th node, i.e temp1->next to the n+1th node, i.e. temp2->next after bypassing
    free(temp2);
    }
    int main(){
        head = NULL;

        printf("Before deletion: \n");
        insert(2,1);
        insert(7,2);
        insert(6,3);
        insert(10,4);
        print();

        int n;
        printf("Enter the position to be removed from the list: ");
        scanf("%d", &n);
        delete(n);
        printf("After deletion: \n");
        print();

    }