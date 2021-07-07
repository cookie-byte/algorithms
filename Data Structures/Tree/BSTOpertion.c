#include<stdio.h>
struct node {
    int data;
    struct node *right,*left;
};
struct node *newNode(int d){
    struct node *temp=(struct node *)malloc(sizeof(struct node *));

    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}
struct node *insert(struct node *node,int key){
    if(node==NULL)  return newNode(key);

    if(key<node->data)
        node->left=insert(node->left,key);

    else if(key>node->data)
        node->right=insert(node->right,key);

    return node;
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
void main(){
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    inorder(root);
}