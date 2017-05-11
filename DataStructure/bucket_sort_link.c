#include<stdio.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node* insert(node* start,int val)
{
	node *temp,*newnode,*prev;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("The malloc fails");
		exit(1);
	}
	newnode->data=val;
	if(start==NULL)
	{
		start=newnode;
		newnode->next=NULL;
	}
	else
	{
		temp=start;
		while(temp&&(temp->data)<=val)
		{
			prev=temp;
			temp=temp->next;
		}
		newnode->next=temp;
		if(temp==start)
		   start=newnode;
		else
		   prev->next=newnode;
	}
	return start;
}
void bucket_sort(int a[],int n)
{
	node *b[10]={NULL},*s;
	int i,k;
	for(i=1;i<=n;i++)
	{
		k=a[i]/10;
		b[k]=insert(b[k],a[i]);
	}
	k=1;
	for(i=0;i<10;i++)
	{
		s=b[i];
		while(s!=NULL)
		{
			a[k++]=s->data;
			s=s->next;
		}
	}
}
int main()
{
	int a[100],n,i;
	printf("Enter the size of array");
	scanf("%d",&n);
	printf("Enter the elements of an array:");
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	bucket_sort(a,n);
	printf("The sorted array is:");
	for(i=1;i<=n;i++)
	   printf("%d ",a[i]);
	return 0;
}
