#include <stdio.h>
#include <stdlib.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* left;
    struct nodeblock* right;
}BtNode;

BtNode* root = NULL;

BtNode* NewNode(int x){
    BtNode* temp = (BtNode*)malloc(sizeof(BtNode));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
BtNode* Insert(BtNode* root, int x){
   if(root == NULL){
    root = NewNode(x);
   } else if(x <= root->data){
    root->left = Insert(root->left,x);
   } else {
    root->right = Insert(root->right,x);
   }
   return root;
}
void print(BtNode* root){
    if(root == NULL){
        return;
    } 
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

int FindHeight(BtNode* root){
    if(root==NULL){
        return -1; // leaf node or empty node has height -1
    }
    //recursion 
    int leftheight = FindHeight(root->left);
    int rightheight = FindHeight(root->right);
    
    return Max(leftheight,rightheight)+1;
}
int Max (int left, int right){
    if(left > right){
        return left;
    } else{
        return right;
    }
}
int main(){

    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 13);
    root = Insert(root, 17);
    root = Insert(root, 25);
    printf("BST: ");    
    print(root);
    printf("\n");

    printf("Height of the tree is: %d ", FindHeight(root));
    

    return 0;
}