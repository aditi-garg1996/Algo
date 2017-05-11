#include<stdio.h>
int x[100];
int graph[4][4] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
void print(int x[],int n)
{
	int i;
	for(i=0;i<n;i++)
	   printf("%d ",x[i]);
}
int isSafe(int k,int n,int c)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(graph[k][i]==1&&x[i]==c)
		   return 0;
	}
	return 1;
}
void graphColor(int k,int n,int m)
{
	int i;
	for(i=1;i<=m;i++)
	{
		if(isSafe(k,n,i))
		{
			x[k]=i;
			if(k+1<n)
			   graphColor(k+1,n,m);
			else
			   print(x,n);
		    return;
		}
	}
	printf("-1");
}
int main()
{
	int i,n,m;
	printf("Enter the number of nodes  and color");
	scanf("%d%d",&n,&m);
	graphColor(0,n,m);
	return 0;
}
