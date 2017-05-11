#include<stdio.h>
typedef struct node{
	int W,V;
}node;
int max(int a,int b)
{
	return a>b?a:b;
}
void knapsack(node arr[],int s[100][100],int w,int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	   s[i][0]=0;
	for(i=0;i<=w;i++)
	   s[0][i]=0;
	for(i=1;i<=n;i++)
	{
		printf("%d---",arr[i].W);
		for(j=1;j<=w;j++)
		{
			if(j<(arr[i].W))
			  s[i][j]=s[i-1][j];
			else
			{
				s[i][j]=max(s[i-1][j],arr[i].V+s[i-1][j-(arr[i].W)]);
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
}
void traversal(int s[100][100],node arr[],int w,int n)
{
	int i,j=w,b[100],k=0,result=0;
    for(i=n;i>=1;i--)
    {
    	if(s[i][j]!=s[i-1][j])
    	{
    	    printf("******");
    		b[k++]=i;
    		result=result+arr[i].W;
    		j=w-arr[i].W;
		}
		if(result==w)
		  break;
	}
	printf("The maximum value is:%d\n",s[n][w]);
	printf("The items taken are:");
	for(i=k-1;i>=0;i--)
	  printf("%d ",b[i]);
}
int main()
{
	int n,w,i,s[100][100];
	node arr[100];
	printf("Enter the total number of items:");
	scanf("%d",&n);
	printf("Enter the corresponding weight and value of items:");
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&arr[i].W,&arr[i].V);
	}
	printf("ENter the maximum weight should be taken:");
	scanf("%d",&w);
	knapsack(arr,s,w,n);
	traversal(s,arr,w,n);
}
