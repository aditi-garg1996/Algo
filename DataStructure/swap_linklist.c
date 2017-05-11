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
node* swap(node *start,int val1,int val2)
{
	int i;
	node *s1,*temp,*temp1,*s2,*temp2,*temp3;
	s1=start;
	if(start==NULL)
    {
    	printf("list is empty\n");
    	return NULL;
	}
	if(start->data==val1)
	{
		s1=start;
	}
	else
	{
	s1=start;
	while(s1->link&&s1->link->data!=val1)
	{
		s1=s1->link;
	}
	if(s1->link==NULL)
	{
		printf("The second data entered is not in the list\n");
		return start;
	}
    }
    if(start->data==val2)
	{
		s2=start;
	}
	else
	{
	s2=start;
	while(s2->link&&s2->link->data!=val2)
	{
		s2=s2->link;
	}
	if(s2->link==NULL)
	{
		printf("The second data entered is not in the list\n");
		return start;
	}
    }
    if(start->data==val1)
    temp=start;
    else
    temp=s1->link;
    if(start->data==val2)
    temp1=start;
    else
    temp1=s2->link;
    if(start->data==val1)
    start=temp1;
    else
    s1->link=temp1;
    if(start->data==val2)
    start=temp;
    else
    s2->link=temp;
    temp2=temp->link;
    temp->link=temp1->link;
    temp1->link=temp2;
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
	int val1,val2,choice;
	printf("Do u want to create list");
	scanf("%d",&choice);
	s1=create(choice);
	traversal(s1);
	printf("Enter the datas of nodes u want to swap");
	scanf("%d%d",&val1,&val2);
	if(val1==val2)
	{
	printf("equals not valid");
	s2=s1;
    }
    else
	s2=swap(s1,val1,val2);
	traversal(s2);
}
