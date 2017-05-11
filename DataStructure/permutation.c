#include<stdio.h>
typedef struct node{
	int data;
	int index;
}node;
void swap(node* a,node* b)
{
	node temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void adjust(node a[],int i,int n)
{
	int l,r,max;
	l=2*i+1;
	r=2*i+2;
    if(l<n&&(a[l].data>a[i].data))
       max=l;
    else
       max=i;
    if(r<n&&(a[r].data>a[max].data))
       max=r;
    if(max!=i)
       swap(&a[i],&a[max]);
    if(max<n&&i!=max)
       adjust(a,max,n);
}
void heapsort(node a[],int n)
{
	int i,j;
	for(i=n/2-1;i>=0;i--)
	{
	  adjust(a,i,n);
    }
	for(i=n-1;i>=0;i=n-1)	{
		swap(&a[0],&a[i]);
		n=n-1;
		adjust(a,0,n);
	}
}
int main()
{
	int i,n,s,min,k;
	node a[100],b[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&(a[i].data));
	    a[i].index=i;
    }
    for(i=0;i<n;i++)
	{
	    scanf("%d",&(b[i].data));
	    b[i].index=i;
    }
	heapsort(a,n);
	heapsort(b,n);
	min=abs(a[0].index-b[0].index);
	k=0;
	for(i=1;i<n;i++)
	{
		s=abs(a[i].index-b[i].index);
		if(s<min)
		{
		  min=s;
		  k=i;
	    }
	}
	printf("%d\n",a[k].data);
}
