
#include  <stdio.h>
#include  <stdlib.h>
#include  <limits.h>
// Cài đặt stack bằng mảng
struct Stack { 
    int top; 
    int maxSize; 
    int* array; 
}; 

struct Stack* create(int max) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->maxSize = max; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));  //cấp phát động
    // kích thước mỗi ô nhớ là 10*4 = 40
    return stack; 
} 

// kiểm tra stack đầy không
int isFull(struct Stack* stack) 
{ 
    if(stack->top == stack->maxSize - 1){
        printf("Will not be able to push maxSize reached\n");
    }
    // Since array starts from 0, and maxSize starts from 1
    return stack->top == stack->maxSize - 1; 
} 
  
// kiểm tra stack có rỗng không
// Will return true if top is -1
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
}

//thêm phần tử
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("We have pushed %d to stack\n", item); 
}

// Xóa phần tử 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  
// tìm phần tử đầu danh sách nhung không xóa
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 

int main()
{
struct Stack* stack = create(10); 
  
    push(stack, 5); 
    push(stack, 10); 
    push(stack, 15);
    int flag=1;
    while(flag)
    {
        if(!isEmpty(stack))
            printf("Xoa phan tu %d khoi stack\n", pop(stack));
        else
            printf("Khong the xoa vi stack rong!\n");
            flag=0;
    }
    return 0;
}