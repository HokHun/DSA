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
void search_all(node* root, int key, int pos) {
// Nếu nút hiện tại là NULL, không có gì để tìm
    if (root == NULL) {
        return;
    }
    // Nếu phần tử của nút hiện tại trùng với giá trị cần tìm, in ra giá trị và vị trí đó
    if (root -> data == key) {
        printf("%d (vi tri %d) ", root -> data, pos);
    }
    // Tăng biến đếm lên 1 và tiếp tục tìm trong cây con trái và cây con phải
    search_all(root -> left, key, pos + 1);
    search_all(root -> right, key, pos + 1);
}
// them vao dau
node* insert_head(node* root, int data) {
// Nếu cây rỗng, tạo một nút mới với giá trị data và trả về nút đó
    if (root == NULL) {
        return newNode(data);
    }
    // Tạo một nút mới với giá trị data
    node* new_node = newNode(data);
    // Đặt nút mới là nút gốc của cây hiện tại
    new_node -> right = root;
    // Trả về nút mới làm nút gốc của cây
    return new_node;
}
// the vao vi tri bat ki
void insert_at_position(node** root, int data, int pos) {
// Nếu cây hiện tại là NULL, tạo nút mới với giá trị là data và gán cho cây
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }
    // Nếu vị trí hiện tại là 1, tức là cần chèn phần tử vào nút gốc,
    // thì tạo nút mới với giá trị là data và thay thế nút gốc bằng nút mới
    if (pos == 1) {
        node *temp = newNode(data);
        temp -> left = *root;
        *root = temp;
        return;
    }
    // Nếu vị trí hiện tại là lẻ, tức là cần chèn phần tử vào cây con bên trái
    // điều hướng đến cây con bên trái và giảm vị trí hiện tại xuống 1
    if (pos % 2 == 1) {
        insert_at_position(&((*root) -> left), data, pos / 2);
    }
    // Nếu vị trí hiện tại là chẵn, tức là cần chèn phần tử vào cây con bên phải
    // điều hướng đến cây con bên phải và giảm vị trí hiện tại xuống 1
    else {
        insert_at_position(&((*root) -> right), data, pos / 2);
    }
}
int main() {
    int n, i,a,b,pos,data;//pos va data de tim kiem phan tu vi tri bat ki
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
    printf("nhap phan tu can chen tai vi tri bat ki : ");
    scanf("%d",&data);
    printf("nhap vi tri phan tu can chen: ");
    scanf("%d",&pos);
    insert_at_position(&root, data, pos);
    print_tree(root);
    printf("Nhap phan tu can them vao cuoi: ");
    scanf("%d", &a);
    root = insert(root,a);
    printf("Cay sau khi them phan tu la: ");
    print_tree(root);
    printf("\nNhap phan tu can xoa : ");
    scanf("%d", &b);
    root = delete_node(root, b);
    printf("Cay sau khi xoa phan tu la: ");
    print_tree(root);
    int key;
    printf("\nNhap phan tu can tim : ");
    scanf("%d",&key);
    // Gọi hàm tìm kiếm tất cả các phần tử giống nhau
    printf("Cac phan tu trong cay giong nhau la: ");
    search_all(root, key, 0);
    printf("\n");
    printf("nhap phan tu can them vao dau : ");
    scanf("%d",&key);
    root = insert_head(root, key);
    // In cây
    printf("Cay sau khi them vao dau: ");
    print_tree(root);
    return 0;
}