#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int bottom_up(int p[],int n,int r[])
{
	int i,j,q;
	r[0]=0;
	for(i=1;i<=n;i++)
	{
		q=-234;
		for(j=1;j<=i;j++)
		{
			q=max(q,p[j]+r[i-j]);
		}
		r[i]=q;
	}
	return r[n];
}
int main()
{
	int n,m,p[100],i,r[100];
	for(i=0;i<100;i++)
	   r[i]=-123;
	printf("Enter the size of an array");
	scanf("%d",&n);
	printf("Enter the cost:");
	for(i=1;i<=n;i++)
	  scanf("%d",&p[i]);
	printf("Enter the size of rod to cut:");
	scanf("%d",&m);
	printf("the max revenue is:%d",bottom_up(p,m,r));
	return 0;
}
