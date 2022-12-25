#include <stdio.h>
#include <stdlib.h>
// tìm kiếm theo chiều sâu 
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    
    printf("%d ", node->data);
    printInorder(node->left);
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in postorder*/
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    
    printInorder(node->left);
    printInorder(node->right);
    printf("%d ", node->data);
}
 
/* Driver program to test above functions*/
int main()
{
    struct node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
 
    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);
    
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);
    
    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);
 
    getchar();
    return 0;
}