#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Tìm kiếm, xóa, thêm phần tử trong cây nhị phân
struct node {
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
// them 1 node
node* insert(node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }
    return root;
    }
}
// xoa 1 node
node* delete_node(node* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete_node(root->right, data);
    }
    else {
    // Case 1: No child
    if (root->left == NULL && root->right == NULL) {
        free(root);
        root = NULL;
    }
    // Case 2: One child
    else if (root->left == NULL) {
        node* temp = root;
        root = root->right;
        free(temp);
    }
    // Case 3: Two children
    else {
        node* temp = root->right;
        while (temp->left != NULL) {
        temp = temp->left;
    }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    }
    return root;
}
void print_tree(node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}
bool check_element( node * root, int key) {
    // If root is null, element is not found:Backtrack 
    if (root == NULL) {
        return false;
    }
    // Check whether same or not
    if (root -> data == key) {
        return true;
    }
    if (root -> data > key) {
        // Traverse the left subtree
        return check_element(root -> left, key);
    }
    // Else Traverse the right subtree
    else {
        return check_element(root -> right, key);
    }
}
int main() {
    int n, i,a,b;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    node *root = NULL;

    printf("Nhap cac phan tu: \n");
        for (i = 0; i < n; i++) {
            int data;
            scanf("%d", &data);
            root = insert(root, data);
        }
    printf("Cay duoc sap xep la: ");
    print_tree(root);
    printf("\n");
    printf("Nhap phan tu can tim: ");
    scanf("%d", &n);
    if (check_element(root, n)) {
        printf("Tim thay\n");
    }
    else {
        printf("Khong tim thay\n");
    }
    printf("Nhap phan tu can them: ");
    scanf("%d", &a);
    root = insert(root,a);
    printf("Cay sau khi them phan tu la: ");
    print_tree(root);
    printf("Nhap phan tu can xoa: ");
    scanf("%d", &b);
    root = delete_node(root, b);
    printf("Cay sau khi xoa phan tu la: ");
    print_tree(root);
    return 0;
}