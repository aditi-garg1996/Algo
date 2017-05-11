#include<stdio.h>
typedef struct node{
	int f,s;
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
    if(l<n&&(a[l].f)>(a[i].f))
       max=l;
    else
       max=i;
    if(r<n&&(a[r].f)>(a[max].f))
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
void activity_selection(node t[],int k,int n,int a[],int s )
{
	int m;
	m=k+1;
	while((t[k].f)>(t[m].s))
	  m++;
	if(m<=n)
	{
		a[s]=m;
		activity_selection(t,m,n,a,s+1);
	}
	else
	  return;
}
int main()
{
	node t[100];
	int n,i,a[100];
	printf("Enter the number of activities:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&(t[i].s),&(t[i].f));
	}
	t[0].s=0;
	t[0].f=0;
	heapsort(t,n);
	activity_selection(t,0,n,a,1);
	for(i=1;i<=n;i++)
	   printf("%d ",a[i]);
	return 0;
}
