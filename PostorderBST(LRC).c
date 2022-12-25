// PrepInsta's program for postorder traversal
#include <stdio.h>
#include <stdlib.h>
//duyệt theo trình tự: trái-phải-giữa(L-R-C)
// Basic struct of Tree 
struct node 
{ 
    int val; 
    struct node *left, *right; 
}; 
   
// Function to create a new Node
struct node* newNode(int item) 
{ 
    struct node* temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->val = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// Function print the node in postorder format, when insertion is complete
void postorder(struct node* root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right);
        printf("%d ", root->val);  
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
              90 
           /     \ 
          70      130 
         /  \    /  \ 
       50   75  110  150 */
    struct node* root = NULL; 
    root = insert(root, 90); 
    insert(root, 70); 
    insert(root, 50); 
    insert(root, 75); 
    insert(root, 130); 
    insert(root, 110); 
    insert(root, 150);
    
   
    // Finally printing the tree using postorder
    postorder(root); 
   
    return 0; 
}