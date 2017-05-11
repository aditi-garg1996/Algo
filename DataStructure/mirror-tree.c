
#include<stdio.h>
typedef struct node{
    struct node *left,*right;
	int data;	
}node;
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
void inorder(node* start){
	if(start)
	{
		inorder(start->left);
		printf("%d ",start->data);
		inorder(start->right);
	}
}
void swap(node** a,node** b)
{
	node *temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
node* mirror(node* tree)
{
	if(tree)
	{
		tree->left=mirror(tree->left);
		tree->right=mirror(tree->right);
		//if(tree->left!=NULL&&tree->right!=NULL)
		  swap(&(tree->left),&(tree->right));
		return tree;
	}
	else
	   return NULL;
}
int main()
{
	int choice;
	node* t1;
	printf("Do u want to create root");
	scanf("%d",&choice);
	t1=create(choice);
	printf("The tree is :\n");
	inorder(t1);
	t1=mirror(t1);
	printf("\nThe mirror image of tree is:\n");
	inorder(t1);
}
