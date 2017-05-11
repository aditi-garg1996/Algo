#include<stdio.h>
#define Size 20
typedef struct node{
    struct node *left,*right;
	int data;	
}node;
int front=0,rear=0;
node* queue[Size];
void insertq(node* elem)
{
	if(!isFull())
	{
	rear=(rear+1)%(Size);
	queue[rear]=elem;
    }
    else
    printf("fulll");
}
node* deleteq()
{
	if(!isEmpty())
	{
	front=(front+1)%(Size);
	return queue[front];
    }
    else 
    return NULL;
}
int isEmpty()
{
	if(rear==front)
	 return 1;
	else
	 return 0;
}
int isFull()
{
	if((rear+1)%(Size)==front)
	  return 1;
	else
	  return 0;
}
node* create(int choice)
{
	if(choice==1)
	{
	node *temp,*start=NULL;
	temp=(node*)malloc(sizeof(node));
	if(temp!=NULL)
	{
		printf("Enter the data u want to insert");
		scanf("%d",&(temp->data));
		if(start==NULL)
		start=temp;
		printf("Do u want to create left child of node %d:",temp->data);
		scanf("%d",&choice);
		temp->left=create(choice);
		printf("Do u want to create right child of node %d:",temp->data);
		scanf("%d",&choice);
		temp->right=create(choice);
		return start;
	}
    }
    else
      return NULL;
}
void levelOrder(node* tree)
{
	node* temp;
	if(tree)
	{
		insertq(tree);
	}
	while(!isEmpty())
	{
		temp=deleteq();
		printf("%d ",temp->data);
		if(temp->left)
		   insertq(temp->left);
		if(temp->right)
		   insertq(temp->right);
	}
}
void levelOrderLine(node* tree)
{
	node* temp;
	int size;
	if(tree)
	{
		insertq(tree);
	}
	while(1)
	{
		size=rear-front;
		if(size==0)
		   break;
	while(size!=0)
	{
		temp=deleteq();
		printf("%d ",temp->data);
		if(temp->left)
		   insertq(temp->left);
		if(temp->right)
		   insertq(temp->right);
		size--;
	}
	printf("\n");
    }
}
int main()
{
	node* tree;
	int choice;
	printf("Want to create tree?Press 1 if yes");
	scanf("%d",&choice);
	tree=create(choice);
	levelOrder(tree);
	printf("\n");
	levelOrderLine(tree);
	return 0;
}
