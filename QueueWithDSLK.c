#include <stdio.h>
#include <stdlib.h>
// hàng đợi cài đặt bằng DSLK
struct node
{
	int data;
	struct node* next;
};//defining linked list to implement queue
struct node *Front = NULL;
struct node *Rear = NULL;
void enqueue(int d)//function to insert a node in queue
{
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = d;
	newNode->next = NULL;
	if((Front == NULL)&&(Rear == NULL)){
		Front = Rear = newNode;
	}
	else{
		Rear->next = newNode;
		Rear = newNode;
	}
	
}
void print()//function to display the queue
{
	struct node* temp;
	if((Front == NULL)&&(Rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		temp = Front;
		while(temp){
			printf("\n| %d |",temp->data);
			temp = temp->next;
		}
	}
}
void dequeue()//function to delete an element from a queue
{
	struct node *temp;
	temp = Front;
	if((Front == NULL)&&(Rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		Front = Front->next;
		free(temp);
	}
}
void Insert_k(int d, int k) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next = NULL;
    if (k == 1) { // thêm vào đầu hàng đợi
        newNode->next = Front;
        Front = newNode;
    }
    else {
        struct node* temp = Front;
        int i = 1;
        while (temp != NULL && i < k - 1) { // duyệt đến vị trí k - 1
            temp = temp->next;
            i++;
        }
        if (temp == NULL) { // k lớn hơn số lượng phần tử trong hàng đợi
            printf("Vi tri them khong hop le!\n");
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void Delete_k(int k) {
    if (Front == NULL) { // hàng đợi rỗng
        printf("Hang doi rong!\n");
    }
    else if (k == 1) { // xóa đầu hàng đợi
        struct node* temp = Front;
        Front = Front->next;
        free(temp);
    }
    else {
        struct node* temp = Front;
        int i = 1;
        while (temp != NULL && i < k - 1) { // duyệt đến vị trí k - 1
            temp = temp->next;
            i++;
        }
        if (temp == NULL || temp->next == NULL) { // k lớn hơn số lượng phần tử trong hàng đợi
            printf("Vi tri xoa khong hop le!\n");
        }
        else {
            struct node* temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
		}
	}
}
// Sắp xếp hàng đợi theo thứ tự tăng dần 
void Sort1() {
    if (Front == NULL) { // hàng đợi rỗng
        printf("Hang doi rong!\n");
    }
    else {
        struct node* temp1 = Front;
        while (temp1->next != NULL) {
            struct node* temp2 = temp1->next;
            while (temp2 != NULL) {
                if (temp1->data > temp2->data) { // đổi chỗ 2 phần tử nếu cần
                    int t = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = t;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
}
// Sap xep hang doi theo thu tu giam dan
void Sort2() {
    if (Front == NULL) { // hàng đợi rỗng
        printf("Hàng đợi rỗng!\n");
    }
    else {
        struct node* temp = Front;
        struct node* temp2;
        int t;
        while (temp != NULL) {
            temp2 = temp->next;
            while (temp2 != NULL) {
                if (temp->data < temp2->data) { // đổi chỗ 2 phần tử
                    t = temp->data;
                    temp->data = temp2->data;
                    temp2->data = t;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
}
// Tìm phan tu x bất kì trong hàng đợi
void Find(int x) {
    if (Front == NULL) { // hàng đợi rỗng
        printf("Hnag doi rong!\n");
    }
    else {
        struct node* temp = Front;
        int i = 1;
        while (temp != NULL) {
            if (temp->data == x) { // tìm thấy phần tử
                printf("Phan tu %d tim thay tai vi tri %d\n", x, i);
                return;
            }
            temp = temp->next;
            i++;
        }
        printf("Khong tim thay phan tu %d trong hang doi!\n", x);
    }
}
// Tim tat ca phan tu x bat ki trong hang doi
void FindMulti(int x) {
    if (Front == NULL) { // hàng đợi rỗng
        printf("Hang doi rong!\n");
    }
    else {
        struct node* temp = Front;
        int i = 1;
        while (temp != NULL) {
            if (temp->data == x) { // tìm thấy phần tử
                printf("Phan tu %d tim thay tai vi tri %d\n", x, i);
            }
            temp = temp->next;
            i++;
        }
    }
}
// Tìm phần tử lớn nhất trong hàng đợi
void FindMax() {
    if (Front == NULL) { // hàng đợi rỗng
        printf("Hang doi rong!\n");
    }
    else {
        struct node* temp = Front;
        int max = Front->data; // gán giá trị lớn nhất ban đầu là phần tử đầu tiên
        while (temp != NULL) {
            if (temp->data > max) { // tìm thấy phần tử lớn hơn
                max = temp->data;
            }
            temp = temp->next;
        }
        printf("Phan tu lon nhat trong hang doi la: %d\n", max);
    }
}
// Tim phan tu nho nhat
void FindMin() {
    if (Front == NULL) { // hàng đợi rỗng
        printf("Hang doi rong!\n");
    }
    else {
        struct node* temp = Front;
        int min = Front->data; // gán giá trị nhỏ nhất ban đầu là phần tử đầu tiên
        while (temp != NULL) {
            if (temp->data < min) { // tìm thấy phần tử nhỏ hơn
                min = temp->data;
            }
            temp = temp->next;
        }
        printf("Phan tu nho nhat trong hang doi la: %d\n", min);
    }
}

int main()//main function to use all our declared function
{
	int opt,n,i,k,x,data; // k de them va xoa, x de tim
	printf("Nhap lua chon: ");
	while(1){
		printf("\n\n1 Them vao dau hang doi \n2 Xoa vi tri cuoi hang doi\n3.Them vao vi tri bat ki\n4.Xoa vi tri bat ki\n5.Sort tang\n6.Sort giam\n7.Tim phan tu bat ki\n8.Tim tat ca phan tu giong nhau\n9.Find Max\n10.Find Min\n0 Thoat\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nNhap so luong phan tu can them: ");
				scanf("%d",&n);
				printf("\nNhap gia tri: \n");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
                print();
				break;
			case 2:
				dequeue();
                print();
				break;
			case 3:
				printf("\nNhap du lieu can them: ");
				scanf("%d",&data);
				printf("\nNhap vi tri can them: ");
				scanf("%d",&k);
				Insert_k(data, k);
				print();
			case 4:
				printf("\nNhap vi tri can xoa: ");
				scanf("%d",&k);
				Delete_k(k);
				print();
            break;
			case 0:
				break;
				default:
				printf("\nLua chon khong hop le");
		    case 5:
			Sort1();
			print();
			case 6:
			Sort2();
			print();
			case 7:
			printf("nhap phan tu can tim: ");
			scanf("%d",&x);
			Find(x);
			print();
			case 8:
			printf("nhap phan tu can tim: ");
			scanf("%d",&x);
			FindMulti(x);
			print();
			case 9:
			FindMax();
			case 10:
			FindMin();
        }
        }
    return 0;
    }

		