#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//khai báo cau trúc Node
typedef int item;
struct node {
    item data;
    struct node* next;
};
// typedef struct node* stack;
//khai báo cau trúc stack
typedef struct stack{
    node *top;
};
void init(stack &s){
    s.top = NULL;
}
//kiem tra stack rong
int isEmpty(stack s) {
    return (s.top == NULL);
}
int Len(stack s){
	node *p = s.top;
	int i = 0;
	while(p!=NULL){
		i++;
		p = p->next;
	}
	return i;
}
//tao Node
node *createNode(item x) {
    node *p = (node*)malloc(sizeof(node));
    // tu them
//    if (p == NULL) {
//        return NULL;
//    }
    //
    p->next = NULL;
    p->data = x;
    return p;
}
 
void push(stack &s, item x) {
  // tao mot Node moi
    node *p = createNode(x);
  // ki?m tra stack r?ng
//    if (isEmpty(s)) {
//        s.top = p;
//    }
//  //n?u t?n t?i ph?n t? ta tr? d?n ph?n t? d?u danh sách
//    else {
        p->next = s.top;
        s.top = p;
//    }
}
 
//int top(stack **s) {
//    if (!isEmpty(*s)) {
//        return *s->data;
//    }
//    else {
//        printf ("Stack is empty! ");
//    }
//}

int Peak(stack s){ // lay phan tu o dau nhung khong xoa
	return s.top->data;
}
int pop(stack &s) {
    if (!isEmpty(s)) {
    //t?o m?t bi?n data
        item x = s.top ->data; // luu lai gia tri
        s.top = s.top->next; // xoa phan tu top
        return x;
    }
    else {
        printf("Stack r?ng!");
    }
}
void NhapMang(stack &s) {
    int n;
    item x;
    do{
        printf("nhap so phan tu trong ngan xep :(<%d)",MAX);
        scanf("%d", &n);	
    } while(n>MAX||n<1); // nhap 0 de ket thuc
	for(int i =0;i<n;i++){
		printf("nhap phan tu thu %d : ",i+1);
		scanf("%d",&x);
		push(s,x);
	}
}
// xuat mang ko can tham chieu do no ko can thay doi 
void XuatMang(stack s){
    node *X = s.top;
    printf("\nCac phan tu trong ngan xep la: \n");
    while(X!=NULL){
        printf("|%3d |\n",X->data);
        X = X->next;
    }
    printf("________\n");
}
// Xoa phan tu o vi tri k
int Get_k (stack &s,int k){
	stack Q;
	init(Q);
	node *X = s.top;
	item result;
	if(!isEmpty(s) && Len(s)>= k){
		for(int i =1; i<k ;i++){
			push(Q,pop(s));
		}
		result = pop(s);
		while(Q.top != NULL){
			push(s,pop(Q));
		}
		return result;
	}
}
//void Insert_k (stack &s, int k, item x){
//    stack Q;
//    init(Q);
//    node *p = createNode(x);
//    if(k == 1){ // thêm vào d?u stack
//        push(Q,x);
//        while(!isEmpty(s)){
//            push(Q,pop(s));
//        }
//        s = Q; // gán l?i stack cho s
//    }
//    else if(k > 1 && k <= Len(s)){ // thêm vào gi?a stack
//        for(int i = 1; i < k; i++){
//            push(Q,pop(s));
//        }
//        push(Q,x); // thêm ph?n t? vào v? trí k
//        while(!isEmpty(s)){
//            push(Q,pop(s));
//        }
//        s = Q; // gán l?i stack cho s
//    }
//    else if(k == Len(s) + 1){ // thêm vào cu?i stack
//        while(!isEmpty(s)){
//            push(Q,pop(s));
//        }
//        push(Q,x); // thêm ph?n t? vào v? trí cu?i cùng c?a stack
//        s = Q; // gán l?i stack cho s
//    }
//    else{
//        printf("Vi tri them khong hop le!\n");
//    }
//}
void Insert_k (stack &s, int k, item x){
    stack Q;
    init(Q);
    node *p = createNode(x);
    if(k == 1){ // thêm vào d?u stack
        push(s,x); // thêm ph?n t? vào d?u stack
    }
    else if(k > 1 && k <= Len(s)){ // thêm vào gi?a stack
        for(int i = 1; i < k; i++){
            push(Q,pop(s));
        }
        push(s,x); // thêm ph?n t? vào v? trí k
        while(!isEmpty(Q)){
            push(s,pop(Q));
        }
    }
    else if(k == Len(s) + 1){ // thêm vào cu?i stack
        while(!isEmpty(s)){
            push(Q,pop(s));
        }
        push(Q,x); // thêm ph?n t? vào v? trí cu?i cùng c?a stack
        while(!isEmpty(Q)){
            push(s,pop(Q));
        }
    }
    else{
        printf("Vi tri them khong hop le!\n");
    }
}

void Clear(stack &s){ // xoa tat ca stack
	s.top = NULL;
}
int main() {
  stack s;
  init(s);
  int k;
  NhapMang(s);
  XuatMang(s);
  item x;
  printf("Nhap phan tu chen vao ngan xep: ");
  scanf("%d",&x);
  push(s,x);
  pop(s);
  printf("ngan xep sau khi them :\n");
  push(s,x);
  XuatMang(s);
  printf("nhap vi tri can lay ra : ");
  scanf("%d",&k);
  printf("phan tu o vi tri %d la: %d",k, Get_k(s,k));
  XuatMang(s);
  printf("nhap vi tri can them : ");
  scanf("%d",&k);
  printf("nhap phan tu can them : ");
  scanf("%d",&x);
  Insert_k(s,k,x);
  XuatMang(s);
}


