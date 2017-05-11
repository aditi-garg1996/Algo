#include<stdio.h>
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
void traversal(node* start)
{
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->link;
	}
}
node* merge(node* a,node* b)
{
	node* z=NULL;
	node* last;
	if(a==NULL&&b==NULL)
	   return NULL;
	else if(a==NULL)
	   return b;
	else if(b==NULL)
	   return a;
	while(a!=NULL&&b!=NULL)
	{
		if((a->data)<=(b->data))
		{
			if(z==NULL)
			{
				z=a;
				last=z;
			}
			else
			{
				last->link=a;
				last=a;
			}
			a=a->link;
		}
		else
		{
			if(z==NULL)
			{
				z=b;
				last=z;
			}
			else
			{
				last->link=b;
				last=b;
			}
			b=b->link;
		}
	}  
	while(a!=NULL)
	{
		last->link=a;
		last=a;
		a=a->link;
	}
	while(b!=NULL)
	{
		last->link=b;
		last=b;
		b=b->link;
	}
	return z;
}
void findMid(node* start,node** s2,node** s1)
{
	node* prev;
	*s1=start;
	*s2=start;
	while((*s2)->link!=NULL&&(*s2)->link->link!=NULL)
	{
		*s1=(*s1)->link;
		*s2=(*s2)->link->link;
	}
	prev=*s1;
	*s1=(*s1)->link;
	prev->link=NULL;
	*s2=start;
}
void mergesort(node **s1)
{
	node *f=NULL,*b=NULL,*s2=*s1;
	if(s2!=NULL&&s2->link!=NULL)
	{
		findMid(s2,&f,&b);
	    mergesort(&f);
		mergesort(&b);
		*s1=merge(f,b);	
	}
}
int main()
{
	node *s1,*s2,*a=NULL,*b=NULL;
    int choice;
	printf("Do u want to create list1??press 1 if yo");
	scanf("%d",&choice);
	s1=create(choice);
	mergesort(&s1);
	traversal(s1);
	return 0;
}
