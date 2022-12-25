#include <stdio.h>
#include <stdlib.h>
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
int main()//main function to use all our declared function
{
	int opt,n,i,data;
	printf("Nhap lua chon: ");
	while(1){
		printf("\n\n1 Them vao dau hang doi \n2 Xoa vi tri cuoi hang doi\n0 Thoat\n");
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
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
	}
}