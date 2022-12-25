#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void NhapMang(int a[],int n){
    for(int i=0;i<n;i++){
        printf("Nhap so phan tu a[%d] : ",i);
        scanf("%d",&a[i]);
    }
}
void XuatMang(int a[],int n){
    for(int i=0;i<n;i++){
        printf("phan tu thu a[%d] = %d\n",i,a[i]);
    }
}
// thêm phần tử tại vị trí bất kì
void InsertElementAt(int a[], int *n, int x, int pos)
{
    // kiểm tra vị trí pos có hợp lệ hay không
    if (pos < 0 || pos > n) return;

    // dịch các phần tử sau pos sang phải để để chèn x vào vị trí pos
    for (int i = n; i > pos; i--) a[i] = a[i - 1];

    // chèn x vào vị trí pos
    a[pos] = x;
    n++; // cập nhật số lượng phần tử trong mảng
}
// xóa phần tử tại vị trí bất kì
void DeleteElement(int a[], int *n, int pos)
{
    // kiểm tra vị trí pos có hợp lệ không
    if (pos < 0 || pos >= n) return;

    // dịch các phần tử sau pos sang trái để xóa phần tử ở vị trí pos
    for (int i = pos; i < n - 1; i++) a[i] = a[i + 1];
        n--; // cập nhật số lượng phần tử trong mảng
}

int main(){
    int n,x,pos,arr[MAX];
    printf("nhap so phan tu: ");
    do{
        scanf("%d",&n);
        if(n<=0||n>MAX){
            printf("nhap lai");
        }
    }
    while(n<=0||n>MAX);
    NhapMang(arr,n);
    printf("nhap vao phan tu can chen: ");
    scanf("%d",&x);
    printf("nhap vao vi tri phan tu can chen: ");
    scanf("%d",&pos);
    InsertElementAt(arr,n,x,pos);
    XuatMang(arr,n+1);
    printf("nhap vao vi tri phan tu can xoa: ");
    scanf("%d",&pos);
    DeleteElement(arr,n,pos);
    XuatMang(arr,n);
}