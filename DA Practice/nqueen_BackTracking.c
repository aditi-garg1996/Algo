#include<stdio.h>
typedef struct node{
	int row;
	int col;
}node;
void print(node x[],int n)
{
	int i;
	for(i=0;i<n;i++)
	   printf("%d %d\n",x[i].row,x[i].col);
}
int isSafe(int c,node pos[],int n,int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(pos[i].col==c||(pos[i].row+pos[i].col==c+k)||(pos[i].row-pos[i].col==k-c))
		   return 0;
	}
	return 1;
}
void nqueen(int k,node pos[],int n)
{
	int c;
	for(c=0;c<n;c++)
	{
		if(isSafe(c,pos,n,k))
		{
			pos[c].row=k;
			pos[c].col=c;
			if(k+1<n)
			  nqueen(k+1,pos,n);
			else
			  print(pos,n);
			return;
		}
	}
	printf("-1");
}
int main()
{
	int i,n;
	node pos[10];
	printf("Enter the number of queens");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		pos[i].row=-1;
		pos[i].col=-1;
	}
	nqueen(0,pos,n);
	return 0;
}
