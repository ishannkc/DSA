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

BstNode* Insert(BstNode* root, int x){
    if(root == NULL){
        root = NewNode(x);
    } else if(x <= root->data){
        root->left = Insert(root->left, x);
    } else{
        root->right = Insert(root->right, x);
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
        printf("Tree is Empty\n");
        return false;
    } else if( x == root->data){
        return true;
    } else if (x <= root->data){
        return Search(root->left, x);
    }  else {
        return Search(root->right, x);
    }
}

int FindMin(BstNode* root){
    BstNode* temp = root; //traversal starting from root
    if(root == NULL){
        printf("Tree is Empty, Cannot find Min\n");
        return;
    }
    while(temp->left !=NULL){ //traversing only left subtree elements until the leaf node which is NULL
        temp = temp->left; //in bst, minimum elements are towards the left subtree
    }
    return temp->data;
}
int FindMax(BstNode* root){
    BstNode* temp = root;
    if(root == NULL){
        printf("Tree is Empty, Cannot find Max\n");
        return;
    }
    while(temp->right!=NULL){
        temp = temp->right; //in bst, max elements are towards the right subtree
    }
    return temp->data;
}
int main(){

    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 15);
    root = Insert(root , 25);
    printf("Bst: ");
    print(root);
    printf("\n");

    printf("Max element from BST: %d \n", FindMax(root));
    printf("Min element from BST: %d \n", FindMin(root));

    int n;
    printf("Enter the number to search: ");
    scanf("%d", &n);
    if(Search(root, n) == true){
        printf("Found\n");
    } else{
        printf("Not Found\n");
    }


    return 0;
}
