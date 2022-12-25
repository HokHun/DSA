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

// Chọn trực tiếp
void SwapSelectionSort(int *min,int *i)
{ // nếu giảm dần thì thay min bằng max
    int temp = *min;
    *min = *i;
    *i = temp;
}

void SelectionSort(int a[],int n )
{
    int min,i,j; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
    for (i=0; i<n-1 ; i++) //chỉ số đầu tiên của dãy hiện hành
    {
        min = i;
        for(j = i+1; j <n ; j++)
                if (a[j ] < a[min]) // tăng dần
                // if (a[j ] > a[min]) // giảm dần
                    min = j; // lưu vtrí phần tử hiện nhỏ nhất
                SwapSelectionSort(&a[min],&a[i]); 
    // truyền tham chiếu, nếu hàm swap truyền tham chiếu "&" dc( như C++) thì ko cần truyền tham chiếu ở đây
    }
}
// ---------------------------------------------------------------------------------------------------------
// Chèn trực tiếp
void InsertionSort(int a[], int n )
{   
    int pos, i;
    int x;//lưu giá trị a[i] tránh bị ghi đè khi dời chỗ các phần tử.
    for(i=1 ; i<n ; i++) //đoạn a[0] đã sắp
    {
        x = a[i]; pos = i-1;
        // tìm vị trí chèn x
        while((pos >= 0)&&(a[pos] > x)) // tăng dần
        while((pos >= 0)&&(a[pos] < x)) // giảm dần
        {//kết hợp dời chỗ các phần tử sẽ đứng sau x trong dãy mới   
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x; // chèn x vào dãy
    }
}
// ---------------------------------------------------------------------------------------------------------
// Chèn nhị phân  // bug
void BInsertionSort(int a[],int n )
{
    int l,r,m,i; // I=left , r=right, m=mid
    int x;//lưu giá trị a[i] tránh bị ghi đè khi dời chỗ các phần tử.
    for(int i=1 ; i<n ; i++)
    {       
        x = a[i]; l = 1; r = i-1;
        while(i<=r) // tìm vị trí chèn x
        {       
            m = (l+r)/2; // tìm vị trí thích hợp m
            if(x <= a[m]) r = m-1;// tăng dần
            // if(x > a[m]) r = m-1;// giảm dần
            else l = m+1;
        }
        for(int j = i-1 ; j >=l ; j--)
        {
            a[j+1] = a[j];// dời các phần tử sẽ đứng sau x
        }
        a[l] = x; // chèn x vào dãy
    }
}
// ---------------------------------------------------------------------------------------------------------
//  Đổi chỗ trực tiếp
void SwapInterchangeSort(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
void InterchangeSort(int a[], int n )
{
    int i, j;
    for (i = 0 ; i<n-1 ; i++)
        for (j =i+1; j < n ; j++)
            if(a[j ]< a[i]) // (tăng dần)Thỏa 1 cặp nghịch thế
            // if(a[j ]> a[i]) // (giảm dần)Thỏa 1 cặp nghịch thế
                SwapInterchangeSort(&a[i], &a[j]);
}
// ---------------------------------------------------------------------------------------------------------
// Nổi Bọt - BubbleSort
void SwapBubbleSort(int *j,int *u)
{
    int temp = *j;
    *j = *u;
    *u=temp;
}
void BubbleSort(int a[],int n)
{
    int i, j,u; // đặt u để gán u = j -1 để swap cho dễ
    for (i = 0 ; i<n-1 ; i++)
    {
        for (j =n-1; j >i ; j --)
        {
            if(a[j]< a[j-1])//(tăng dần) nếu sai vị trí thì đổi chỗ
            // if(a[j]> a[j-1])//(giảm dần) nếu sai vị trí thì đổi chỗ
            {               
                u = j-1; // gán u = j -1 để swap cho dễ
                SwapBubbleSort(&a[j], &a[u]);
            }
        }
    }
}
// ---------------------------------------------------------------------------------------------------------
// Shaker Sort
void SwapShakeSort(int *j,int *u )
{
    int temp = *j;
    *j = *u;
    *u = temp;
}
void ShakeSort(int a[],int n)
{
    // nếu giảm dần thì đổi dấu 2 điều kiện của if
    int i, j;
    int left, right, k, u;  // đặt u để gán u = j -1 hoặc j+1 để swap cho dễ
    left = 0; right = n-1; //đoạn l->r là đoạn cần được sắp xếp
    k = n-1; //ghi nhận vị trí k xảy ra hoán vị sau cùng để làm cơ sơ thu hẹp đoạn l->r
    while (left < right)
    {
        for (j = right; j > left; j --) //đẩy phần tử nhỏ về đầu mảng
        {
            if (a[j]< a[j-1]) //(tăng dần)
            // if (a[j]> a[j-1]) // (giảm dần)
            {
                u = j-1;
                SwapShakeSort(&a[j],&a[u]);
                k =j;
            }
        }
        left = k; //loại phần tử đã có thứ tự ở đầu dãy
        for (j = left; j < right; j ++)
        {
            if (a[j]> a[j+1]) // tăng dần
            // if (a[j]< a[j+1]) // giảm dần
            {
                u = j+1;
                SwapShakeSort(&a[j],&a[u]);
                k = j; 
            }
        }
        right = k;//loại các phần tử đã có thứ tự ở cuối dãy
    }
}
// ---------------------------------------------------------------------------------------------------------
// Shell Sort
void ShellSort(int a[],int n, int h[], int k)
{ 
    int step,i,j, x,len;
    for (step = 0 ; step <k; step ++)
    { 
        len = h[step];
        for (i = len; i <n; i++)
        {
            x = a[i];
            j = i-len; // a[j] đứng kề trước a[i] trong cùng dãy con
            while ((x<a[j])&&(j>=0))//(tăng dần) sắp xếp dãy con chứa x
            // while ((x>a[j])&&(j>=0))//(giảm dần) sắp xếp dãy con chứa x
            { // bằng phương pháp chèn trực tiếp
                a[j+len] = a[j];
                j = j - len;
            }
            a[j+len] = x;
        }
    }
}
// ---------------------------------------------------------------------------------------------------------
// Heap Sort
void SwapHeapSort( int *u,int *r)
{
    int temp = *u;
    *u = *r;
    *r = temp;
}
void shift(int a[],int l,int r)
{
    // giảm dần thay đổi 2 điều kiện của if
    int x,i,j;
    i=l;
    j=2*i+1;
    x=a[i];
    while(j<=r)
    { 
        if(j<r)
        {
            if(a[j]<a[j+1]) //(tăng dần) tim phan tu lon nhat a[j] va a[j+1]
            // if(a[j]>a[j+1]) //(giảm dần) tim phan tu lon nhat a[j] va a[j+1]
            j++; //luu chi so cua phan tu nho nhat trong hai phan tu
        }
        if(a[j]<=x)// tăng dần
        // if(a[j]>=x)// giảm dần
        {
            return;
        }
        else
        { 
            a[i]=a[j];
            a[j]=x;
            i=j;
            j=2*i+1;
            x=a[i];
        }
    }
}
void CreateHeap(int a[],int n)
{ 
    int l;
    l=n/2-1;
    while(l>=0)
    {
        shift(a,l,n-1);
        l=l-1;
    }
}
void HeapSort(int a[],int n)
{ 
    int r;
    int u; // đặt u  để lát swap cho dễ
    CreateHeap(a,n);
    r=n-1;
    while(r>0)
    {
        u =0;
        SwapHeapSort(&a[u],&a[r]);//a[0] la nút gốc
        r--;
        if(r>0)
        {
            shift(a,0,r);
        }
    }
}
// ---------------------------------------------------------------------------------------------------------
// QuickSort
void SwapQuickSort(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
void QuickSort(int a[], int left, int right)
{ 
    // nếu giảm dần thì thay đổi điều kiện 2 vòng lặp while
    int i, j, x;
    x = a[(left+right)/2];
    i = left; j = right;
    while(i < j)
    {
        while(a[i] < x) i++;// tăng dần
        // while(a[i] > x) i++;// giảm dần
        while(a[j] > x) j--;// tăng dần
        // while(a[j] < x) j--;// giảm dần
        if(i <= j)
        {
            SwapQuickSort(&a[i],&a[j]);
            i++ ; j--;
        }
    }
    if(left<j)
    {
        QuickSort(a, left, j);
    }
    if(i<right)
    {
        QuickSort(a, i, right);
    }
}
// ----------------------------------------------------------------------------------------------------------
void MergeSort(int a[], int left, int right)
{
    int mid;
    if(left < right)
    {
        // can also use mid = left + (right - left) / 2
        // this can avoid data type overflow
        mid = (left + right)/2;
        // recursive calls to sort first half and second half subarrays
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}

void Merge(int a[], int left, int mid, int right)
{
    //Lưu ý: nếu giảm dần thì thay đổi điều kiện if
    int i = left, j = mid + 1, p, index = left;
    int temp[10];

    while(i<=mid && j<=right)
    {
        if(a[i]<a[j]) { temp[index] = a[i]; i = i+1; } else { temp[index] = a[j]; j = j+1; } index++; } if(i>mid)// tăng dần
        // if(a[i]>a[j]) { temp[index] = a[i]; i = i+1; } else { temp[index] = a[j]; j = j+1; } index++; } if(i>mid)// giảm dần
    {
        while(j<=right)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    p = left;
    while(p<index)
    {
        a[p]=temp[p];
        p++;
    }
}
// ---------------------------------------------------------------------------------------------------------
//RadixSort
int main(){
    int n;
    // 2 var của ShellSort
        int k;
        int hrr[MAX];
    //
    int arr[MAX];
    printf("nhap so phan tu: ");
    do{
        scanf("%d",&n);
        if(n<=0||n>MAX){
            printf("nhap lai");
        }
    }
    while(n<=0||n>MAX);
    NhapMang(arr,n);
    // SelectionSort(arr,n);
    // InsertionSort(arr,n);
    // BInsertionSort(arr,n);
    // InterchangeSort(arr,n);
    // BubbleSort(arr,n);
    // ShakeSort(arr,n);
    // ShellSort
    // printf("Nhap kich thuoc cua mang: ");
    // scanf("%d", &k);
    // printf("Nhap kich thuoc cua day khoang cach: ");
    // for (int i = 0; i < k; i++) {
    //     scanf("%d", &hrr[i]);
    // }
    // ShellSort(arr,n,hrr,k); 
    // HeapSort(arr,n);
    QuickSort(arr,0,n-1);
    // MergeSort(arr,0,n-1); 
    XuatMang(arr,n);
}