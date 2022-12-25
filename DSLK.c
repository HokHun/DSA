#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node *next;
};
typedef struct node node;

node* makeNode(int x){
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data = x;
    newNode->next =NULL;
    return newNode;
}
void  duyet ( node *head){
    while (head  != NULL)
    {
        // printf("%d ", node -> data);
        printf("%d\t", head->data);
        head = head->next;
    }
}
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}
void pushBack(node **head, int x){
    node *temp = * head;
    node *newNode = makeNode(x);
    if(temp == NULL){
        *head = newNode; // neu thay *head = temp thi ko anh huong gi toi head ca , nen khong in ra duoc gi
        return;
    }
    while (temp ->next !=NULL)
    {
        temp = temp ->next;
    }
    temp ->next = newNode;
}
// them giua
void insert(node **head, int k,int x)
{
    int n = sizeof(*head);
    if(k<1||k>n+1)
    {
        return;
    }
    if(k ==1)
    {
        pushFront(head ,x);
        return;
    }
    node *temp =*head;
    for (int i =1 ;i<=k-2;i++)
    {
        temp =temp ->next;
    }
    node *newNode =makeNode(x);
    newNode->next =temp ->next;
    temp ->next =newNode;
}
// xoa dau
void popFront(node **head)
{
    if(*head == NULL)
    {
        return ;
    }
    node* temp = *head;
    *head = temp->next;
    free (temp);
}
// xoa cuoi
void popBack(node **head)
{
    if(*head == NULL)
    {
        return ;
    }
    node* temp = *head;
    if(temp->next == NULL)
    {
        *head = NULL;
        free (temp);
        return ;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *last = temp->next;
    temp ->next = NULL;
    free (last);
}
// xoa giua
void erase(node **head,int k)
{
    int n = sizeof(*head);
    if(k<1 || k>n)
    {
        return ;
    }
    if(k==1)
    {
        popFront(head);
    }
    else
    {
        node *temp = *head;
        for(int i =1;i<=k-2;i++)
        {
            temp = temp ->next;
        }
        // temp : k-1
        node *thuk = temp ->next;
        //cho k =1 => ket noi voi node thu k+1
        temp ->next = thuk->next;
        free(thuk);
    }
}
int main(){
    node *head =NULL; // phai luon khai bao cai nay trc
    int choice,x,k;
    // for (int i=1;i<=5;i++ )
    // {
    //     // pushFront(&head,i);
    //     pushBack(&head,i);

    // }
    // duyet(head);
    while(1)
    {
        printf("\n-----------------------------------\n");
        printf("1 . Them vao dau \n");
        printf("2 . Them vao cuoi \n");
        printf("3 . Them vao giua \n");
        printf("4 . Xoa dau\n");
        printf("5 . Xoa cuoi \n");
        printf("6 . Xoa giua \n");
        printf("0 . Thoat ! \n");
        printf("-----------------------------------\n");
        printf("nhap lua chon : ");
        scanf("%d",&choice);
        if(choice == 1)
        {

            printf("nhap phan tu muon them vao dau : "); 
            scanf("%d",&x);
        // for(int x  = 1; x < y; x++){
        //     printf("nhap vi tri %d: ",x); 
        //     scanf("%d",&x);
        // }
            pushFront(&head,x);  
            duyet(head);
        }
        else if(choice == 2)
        {
            printf("nhap phan tu muon them vao cuoi : "); 
            scanf("%d",&x); 
            pushBack(&head,x);
            duyet(head);
        }     
        else if(choice ==3)
        {
            if(head == NULL)
            {
                printf("\nLoi , Ban chua co Node, hay tao Node\n");
                printf("1 . Them vao dau \n");
                printf("2 . Them vao cuoi \n");
                printf("nhap lua chon : ");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("nhap phan tu muon them vao dau : "); 
                    scanf("%d",&x);
                    pushFront(&head,x);  
                    duyet(head);
                }
                else if(choice == 2)
                {
                    printf("nhap phan tu muon them vao cuoi : "); 
                    scanf("%d",&x); 
                    pushBack(&head,x);
                    duyet(head);
                }     
            }
            else
            {
                printf("nhap so muon chen : "); 
                scanf("%d",&x); 
                printf("nhap vi tri muon chen : "); 
                scanf("%d",&k); 
                insert(&head,k,x);
                duyet(head);
            }
        }
        else if (choice == 4)
        {
            if(head == NULL)
            {
                printf("\nLoi , Ban chua co Node, hay tao Node\n");
                printf("1 . Them vao dau \n");
                printf("2 . Them vao cuoi \n");
                printf("nhap lua chon : ");
                scanf("%d",&choice);
                if(choice == 1)
                {

                    printf("nhap phan tu muon them vao dau : "); 
                    scanf("%d",&x);
                    pushFront(&head,x);  
                    duyet(head);
                }
                else if(choice == 2)
                {
                    printf("nhap phan tu muon them vao cuoi : "); 
                    scanf("%d",&x); 
                    pushBack(&head,x);
                    duyet(head);
                }     
            }
            else
            {
                popFront(&head);
                duyet(head);
            }
        }
        else if (choice == 5)
        {
            if(head == NULL)
            {
                printf("\nLoi , Ban chua co Node, hay tao Node\n");
                printf("1 . Them vao dau \n"); 
                printf("2 . Them vao cuoi \n");
                printf("nhap lua chon : ");
                scanf("%d",&choice);
                if(choice == 1)
                {

                    printf("nhap phan tu muon them vao dau : "); 
                    scanf("%d",&x);
                    pushFront(&head,x);  
                    duyet(head);
                }
                else if(choice == 2)
                {
                    printf("nhap phan tu muon them vao cuoi : "); 
                    scanf("%d",&x); 
                    pushBack(&head,x);
                    duyet(head);
                }     
            }
            else
            {
                popBack(&head);
                duyet(head);
            }
        }
        else if(choice ==6)
        {
            if(head == NULL)
            {
                printf("\nLoi , Ban chua co Node, hay tao Node\n");
                printf("1 . Them vao dau \n");
                printf("2 . Them vao cuoi \n");
                printf("nhap lua chon : ");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("nhap phan tu muon them vao dau: "); 
                    scanf("%d",&x);
                    pushFront(&head,x);  
                    duyet(head);
                }
                else if(choice == 2)
                {
                    printf("nhap phan tu muon them vao cuoi : "); 
                    scanf("%d",&x); 
                    pushBack(&head,x);
                    duyet(head);
                }     
            }
            else
            {
                printf("nhap vi tri muon xoa: "); 
                scanf("%d",&k); 
                erase(&head,k);
                duyet(head);
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}