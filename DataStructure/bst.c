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
node* search(node* tree,int val)
{
  if(tree)
  {
	if(val==(tree->data))
	  return tree;
	else if(val<(tree->data))
	  return search(tree->left,val);
	else
	  return search(tree->right,val);
  }
  else
      return NULL;
}
node* inordersuccesor(node* tree)
{
	node* t;
	if(tree)
	{
		t=tree;
		tree=tree->left;
	}
	return t;   
}
node* deletet(node* tree,int val)
{
	if(tree==NULL)
	  return tree;
	if(val<tree->data)
	   tree->left=deletet(tree->left,val);
	else if(val>tree->data)
	   tree->right=deletet(tree->right,val);
	else
	{
		if(tree->left==NULL)
		{
			node* temp=tree->right;
			free(tree);
			return temp;
		}
		else if(tree->right==NULL)
		{
			node* temp=tree->left;
			free(tree);
			return temp;
		}
		else 
		{
			node* temp=inordersuccesor(tree->right);
			tree->data=temp->data;
			tree->right=deletet(tree->right,temp->data);
		}
	}
	return tree;
}
int countinorder(node *start,int k)
{
	int count;
	if(!start)
	{
		return 0;
	}
	else
	{
		count=1+countinorder(start->left,k)+countinorder(start->right,k);
		return count;
	}
}
int main()
{
	node* start=NULL;
	int choice=1,val;
	while(choice)
	{
		printf("Enter the data u want to add to bst");
		scanf("%d",&val);
		start=create(start,val);
		printf("Do you want to create bst more?press 1 or 0");
		scanf("%d",&choice);
	}
	inorder(start);
/*	printf("enter the data u want to search");
	scanf("%d",&val);
	if(search(start,val))
	  printf("Data found");
	else
	  printf("data not found");
	printf("Enter the data u want to delete");
	scanf("%d",&val);
	start=deletet(start,val);
	inorder(start);*/
	countinorder(start,5);
	return 0;
}
