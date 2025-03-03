#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* left;
    struct nodeblock* right;
}Node;

Node* root = NULL;

Node* NewNode(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

Node* Insert(Node* root, int x){
    if(root==NULL){
        root = NewNode(x);
    } else if(x < root->data){
        root->left = Insert(root->left, x);
    } else {
        root->right = Insert(root->right,x);
    }
    return root;
}

void print(Node* root){
    if(root == NULL)
    return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

Node* FindMin(Node* root){
    if(root==NULL)
    return;
    while(root->left!=NULL){ //smallest value is always found in the left nodes, so from right subtree we look towards the left subtrees to find the min element
        root = root->left;
    }
    return root; 
}
Node* Delete(Node* root, int x){
    if(root == NULL)
    return ;
    else if(x < root->data){
        root->left = Delete(root->left,x);
    } else if( x > root->data){
        root->right = Delete(root->right,x);
    } else{ //after recursion, element to be deleted is found in the bst
        //case1: no child(leaf node)
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL; //after deletion, its previous(parent) node should be set to NULL

        }
        //case2: 1child
        else if(root->left == NULL){ //the node,has a right subtree but no left subtree
            Node* temp = root;
            root = root->right;//after deletion, its right subtree becomes comes in place of the deleted node
            free(temp);
        } else if(root->right == NULL){ //tge node has a left subtree but no right subtree
                Node* temp = root;
                root = root->left;//after deletion, its left subtree comes in place of the deleted node
        }
        //case3: two child
        else{
            Node* temp = FindMin(root->right);//finding the minimum element in its right subtree
            root->data = temp->data; //copying the value to its targeted(deleting place) node
            root->right = Delete(root->right, temp->data); //deleting the duplicate from right subtree
        }
    }
    return root;
}

int main(){

    root = Insert(root, 12);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 13);
    root = Insert(root, 17);
    root = Insert(root, 20);
    root = Insert(root, 18);

    printf("BST(Before Deletion): ");
    print(root);
    printf("\n");

    root = Delete(root, 3);//case1 gets executed as 3 is leaf node;
    printf("After Deletion: ");
    print(root);
    printf("\n");

    root = Delete(root, 13); //case 2 gets execueted as 13 has 1 child
    printf("After Deletion: ");
    print(root);
    printf("\n");

    root = Delete(root, 15); //case 3 gets execuetd as 15 has 2 child
    printf("After Deletion: ");
    print(root);
    printf("\n");

}