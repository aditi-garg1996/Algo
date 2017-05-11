#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}node;
node* create(node* start,int val)
{
	node *temp,*newnode,*prev;
    newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
    	printf("node doesn't create");
    	return NULL;
	}
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		temp=start;
		while(temp)
		{
			if(val<(temp->data))
			{
				prev=temp;
				temp=temp->left;
			}
			else if(val>(temp->data))
			{
				prev=temp;
				temp=temp->right;
			}
			else
			{
				printf("duplicates not allowed");
				break;
			}
		}
		if(val<(prev->data))
		prev->left=newnode;
		else if(val>(prev->data))
		prev->right=newnode;
	}
	return start;
}
void inorder(node *start)
{
	if(start)
	{
		inorder(start->left);
		printf("%d ",start->data);
		inorder(start->right);
	}
}
int search(node* start,int key)
{
	if(start)
	{
		if(start->data==key)
		   return start->data;
		else if(start->data<key)
		   return search(start->right,key);
		else
		{
			int c=search(start->left,key);
			return c>=key?c:(start->data);
		}
	}
	else 
	  return -1;
}
int main()
{
	node* start=NULL;
	int choice=1,val,key;
	while(choice)
	{
		printf("Enter the data u want to add to bst");
		scanf("%d",&val);
		start=create(start,val);
		printf("Do you want to create bst more?press 1 or 0");
		scanf("%d",&choice);
	}
	inorder(start);
	printf("\nEnter the key u want to search");
	scanf("%d",&key);
	printf("\n%d",search(start,key));
	return 0;
}
