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
void deletetree(node* start){
	if(start)
	{
		deletetree(start->left);
		deletetree(start->right);
		printf("node deleted is->%d",start->data);
		free(start);
	}
}
int main()
{
	int choice;
	
	node* t1;
	printf("Do u want to create root");
	scanf("%d",&choice);
	t1=create(choice);
	deletetree(t1);
}
