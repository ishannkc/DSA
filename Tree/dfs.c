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
    if(root == NULL){
        root = NewNode(x);
    }
    else if(x <= root->data){
        root->left = Insert(root->left,x);
    } else{
        root->right = Insert(root->right,x);
    }
    return root;
}
//preorder = DLR
void PreOrder(Node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);//D
    PreOrder(root->left);//L
    PreOrder(root->right);//R
}
//inorder = LDR
void InOrder(Node* root){
    if(root == NULL)
    return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}
//postorder = LRD
void PostOrder(Node* root){
    if(root==NULL)
    return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}
int main(){

    root = Insert(root, 45);
    root = Insert(root, 15);
    root = Insert(root, 88);
    root = Insert(root, 68);
    root = Insert(root, -5);
    root = Insert(root, 91);

    printf("Preorder Traversal: ");
    PreOrder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    InOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    PostOrder(root);
    printf("\n");

    return 0;
}