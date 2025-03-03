#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodeblock{
    int data;
    struct nodeblock* left;
    struct nodeblock* right;
}BstNode;

BstNode* root = NULL;

BstNode* NewNode(int x){
    BstNode* temp = (BstNode*)malloc(sizeof(BstNode));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
bool Search(BstNode* root, int x);
BstNode* Insert(BstNode* root, int x){
    if(root == NULL){
        root = NewNode(x);
    } else if(x <= root->data){
        root->left = Insert(root->left, x);
    } else{
        root->right = Insert(root->right,x);
    }
    return root;
}
void print(BstNode* root){
    if(root == NULL){
        return;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}
bool Search(BstNode* root, int x){
    if(root == NULL){
        printf("Tree is empty!\n");
        return false;
    }
    else if(root->data == x){
        return true;
    }
    else if(x <= root->data){
        return Search(root->left, x); //if data is less than the root data, then recursive approach applied to the left subtree  
    }
    else{
        return Search(root->right,x);
    }
}
int main(){

    root = Insert(root, 50);
    root = Insert(root, 17);
    root = Insert(root, 60);
    root = Insert(root, 8);
    printf("BST: ");
    print(root);

    int num;
    printf("\n Enter the number to be searched in the BST: ");
    scanf("%d", &num);
    if(Search(root, num) == true){
        printf("Number Found\n");
    } else{
        printf("Number Not Found\n");
    }
}