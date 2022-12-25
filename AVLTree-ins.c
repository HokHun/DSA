#include<stdio.h>
#include<stdlib.h> 
// chèn vào cây cân bằng(AVL)
typedef struct node
{
    int element;
    struct node *left,*right;
    int ht;
}node;
node *insert(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int balanceFactor(node *);
int main()
{
    node *root=NULL;
    int x,n,i,option;
    do
    {
        printf("\n  1. Create AVL Tree");
        printf("\n  2. End Program");
        printf("\n\tEnter Your Choice : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("\nEnter no. of elements : ");
                    scanf("%d",&n);
                    root=NULL;
                    for(i=0;i<n;i++)
                    {
                        printf("\tEnter %d Element of tree : ",i+1);
                        scanf("%d",&x);
                        root=insert(root,x);
                    }
                    printf("\nPreorder sequence:\n");
                    preorder(root);
                    printf("\n\nInorder sequence:\n");
                    inorder(root);
                    printf("\n-----------------------------------------\n\n");
                    break;
        }
    }while(option!=2);
    return 0;
}

node * insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        T->element=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(x > T->element)        
        {
            T->right=insert(T->right,x);
            if(balanceFactor(T)==-2)
                if(x>T->right->element)
                    T=RR(T);
                else
                    T=RL(T);
        }
        else
            if(x<T->element)
            {
                T->left=insert(T->left,x);
                if(balanceFactor(T)==2)
                    if(x < T->left->element)
                        T=LL(T);
                    else
                        T=LR(T);
            }
        T->ht=height(T);
        return(T);
}

int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    if(lh>rh)
        return(lh);
    return(rh);
}

node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}

node * LL(node *T)
{
    T=rotateright(T);
    return(T);
}

node * LR(node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
    return(T);
}

node * RL(node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}
int balanceFactor(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    return(lh-rh);
}
void preorder(node *T)
{
    if(T!=NULL)
    {
        printf("\n\t%d(Balance Factor=%d)",T->element,balanceFactor(T));
        preorder(T->left);
        preorder(T->right);
    }
}
void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("\n\t%d(Balance Factor=%d)",T->element,balanceFactor(T));
        inorder(T->right);
    }
}