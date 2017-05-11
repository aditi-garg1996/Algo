#include<stdio.h>
#include<stdlib.h>
#define capacity 100
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
node* stack[capacity];
int top=-1;
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
void push(node* elem)
{
	if(!isFull())
	{
		top++;
		stack[top]=elem;
    }
	else
	{
		printf("stack full\n");
		return;
	}
	   
}
node* pop()
{
	if(!isEmpty())
	{
		return stack[top--];
	}
	else
	    return NULL;
}
int isEmpty()
{
	if(top==-1)
	  return 1;
	else
	  return 0;
}
int isFull()
{
	if(top==capacity-1)
	  return 1;
	else
	  return 0;
}
void inorder(node *tree)
{
	while(1)
	{
		while(tree!=NULL)
		{
			push(tree);
			tree=tree->left;
		}
		if(isEmpty())
		   break;
		tree=pop();
		printf("%d ",tree->data);
		tree=tree->right;
	}
}
int main()
{
	node* tree;
	int choice;
	printf("Do u want to create tree?If yes press 1");
	scanf("%d",&choice);
	tree=create(choice);
	inorder(tree);
	return 0;
}
