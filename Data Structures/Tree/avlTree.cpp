#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
} Node;

Node *newNode(int key)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->height = 1;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->key = key;
    return ptr;
}

int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}

Node *leftRotate(Node *n)
{
    Node *x = (Node *)malloc(sizeof(Node));
    Node *T2 = (Node *)malloc(sizeof(Node));
    x = n->right;
    T2 = x->left;
    //left rotating
    x->left = n;
    n->right = T2;
    //updating the height
    n->height = max(height(n->left), height(n->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
}

Node *rightRotate(Node *n)
{
    Node *x = (Node *)malloc(sizeof(Node));
    Node *T2 = (Node *)malloc(sizeof(Node));
    x = n->left;
    T2 = x->right;
    //right rotating
    x->right = n;
    n->left = T2;
    //updating the height
    n->height = max(height(n->left), height(n->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
}

int getBalance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return (height(node->left) - height(node->right));
    }
}
Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (node->key > key)
    {
        node->left = insert(node->left, key);
    }
    else if (node->key < key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && node->left->key > key)
    {
        return rightRotate(node);
    }
    if (balance < -1 && node->right->key < key)
    {
        return leftRotate(node);
    }
    if (balance > 1 && node->left->key < key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && node->right->key > key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void printPreOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << endl;
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
int main()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root = NULL;
    root = insert(root, 45);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 22);
    root = insert(root, 20);
    root = insert(root, 19);
    printPreOrder(root);
    return 0;
}
