// PrepInsta's program to do insertion in a Binary Search Tree (BST)
#include <stdio.h>
#include <stdlib.h>
// duyệt theo trình tự : Trái- giữa phải(L-C-R)
// khởi tạo Node
struct node 
{ 
    int val; 
    struct node *left, *right; 
}; 

// Tạo Node
struct node* newNode(int item) 
{ 
    struct node* temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->val = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// Function print the node in inorder format, when insertion is complete
void inorder(struct node* root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->val); 
        inorder(root->right); 
    } 
} 

// Here we are finding where to insert the new node so BST is followed
struct node* insert(struct node* node, int val) 
{ 
    /* If the tree(subtree) is empty, return a new node by calling newNode func.*/
    if (node == NULL) return newNode(val); 

    /* Else, we will do recursion down the tree to further subtrees */
    if (val < node->val) 
        node->left  = insert(node->left, val); 
    else if (val > node->val) 
        node->right = insert(node->right, val);    

    /* (Safety) return the node's pointer which is unchanged */
    return node; 
} 

int main() 
{ 
    /* Our BST will look like this 
              100 
           /     \ 
          90      140 
         /  \    /  \ 
       40   80  120  160 */
    struct node* root = NULL; 
    root = insert(root, 100); 
    insert(root, 90); 
    insert(root, 40); 
    insert(root, 80); 
    insert(root, 140); 
    insert(root, 120); 
    insert(root, 160);

    // Finally printing the tree using inorder
    inorder(root); 

    return 0; 
} 