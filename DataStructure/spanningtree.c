#include<stdio.h>
typedef struct node{
	int data;
	int u,v;
}node;
int graph[10][10];
void createGraph(int nodes)
{
	int i,j;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			if(i!=j)
			{
			    printf("Enter weight of edge if %d-%d edge exist",i,j);
			    scanf("%d",&graph[i][j]);
		    }
		    else
		        graph[i][j]=0;
		}  
	}
}
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void adjust(node a[],int i,int n)
{
	int l,r,max;
	l=2*i+1;
	r=2*i+2;
    if(l<n&&(a[l].data)>(a[i].data))
       max=l;
    else
       max=i;
    if(r<n&&(a[r].data)>(a[max].data))
       max=r;
    if(max!=i)
       swap(&(a[i].data),&(a[max].data));
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
		swap(&(a[0].data),&(a[i].data));
		n=n-1;
		adjust(a,0,n);
	}
}
int main()
{
	int k,i,l=0,j;
	node a[100];
	printf("Enter the number of nodes in graph");
	scanf("%d",&k);
	createGraph(k);
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
		    if(graph[i][j])
		    {
		    	a[l].data=graph[i][j];
		    	a[l].u=i;
		    	a[l].v=j;
		    	l++;
			}
		}
	}
	heapsort(a,l);
	for(i=0;i<l;i++)
	{
		printf("(%d,%d,%d) ",a[i].data,a[i].u,a[i].v);
	}
	return 0;
}
