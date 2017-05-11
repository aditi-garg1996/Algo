#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}node;
node* create(int choice)
{
	int val;
	node *start,*last,*temp;
	start=NULL;
	while(choice==1)
	{
		printf("Enter the value:");
		scanf("%d",&val);
		temp=(node*)malloc(sizeof(node));
		if(temp==NULL)
		  exit(1);
		temp->data=val;
		if(start==NULL)
		{
			start=temp;
			last=start;
		}
		else
		{
			last->link=temp;
			last=temp;
		}
		printf("want to enter more??pres 1 if yes:");
		scanf("%d",&choice);
	}
	if(start)
	last->link=NULL;
	return start;
}
node* insertAfter(node *start,int val)
{
	node *temp,*s1,*newnode;
	s1=start;
	while(s1!=NULL&&s1->data!=val)
	  s1=s1->link;
	if(s1==NULL)
	{
		printf("data u entered is not in the list\n");
		return start;
	}
	newnode=(node*)malloc(sizeof(node*));
	if(newnode==NULL)
	exit(1);
	printf("Enter the data u want to insert");
	scanf("%d",&(newnode->data));
	newnode->link=s1->link;
	s1->link=newnode;
	return start;
}
void traversal(node* start)
{
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->link;
	}
}
int main()
{
	node *s1,*s2;
	int val,choice;
	printf("Do u want to create list");
	scanf("%d",&choice);
	s1=create(choice);
	traversal(s1);
	printf("Enter the data after which u want to insert");
	scanf("%d",&val);
	s2=insertAfter(s1,val);
	traversal(s2);
}
