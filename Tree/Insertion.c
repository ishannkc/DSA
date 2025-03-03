#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* left;
    struct nodeblock* right;
}BstNode;

BstNode* root = NULL;//initially bst is empty

//function to create a new node
BstNode* NewNode(int x){
    BstNode* temp = (BstNode*)malloc(sizeof(BstNode));//temp is the new node
    temp->data = x;
    temp->left = NULL;
    temp->right =NULL;
    return temp;
}
//insertion using recursion
BstNode* Insert(BstNode* root, int x){
    //if bst is empty, we need to create a new node
    if(root ==NULL){
        root = NewNode(x); 

    } else if(x <= root->data){ //if inserted data is less than or equal to the root data, then insert at left subtree
        root->left = Insert(root->left, x); //recursive approach
    } else{ //if inserted data is greater than root data, then insert at right subtree
        root->right = Insert(root->right, x);
    }
    return root;
}
void print(BstNode* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}
int main(){
    //root = Insert() as it updates the root values, if not root remains NULL and no tree is built
    root = Insert(root,10);
    root = Insert(root,7);
    root = Insert(root,20);

    printf("BST: ");
    print(root);
    printf("\n");

    return 0;
}