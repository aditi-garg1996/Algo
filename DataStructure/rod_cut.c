#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int rod_cut(int p[],int n,int r[])
{
	int i,q;
	if(r[n]>=0)
	  return r[n];
	if(n==0)
	  q=0;
	else 
	{
	q=-234;
	for(i=1;i<=n;i++)
		q=max(q,p[i]+rod_cut(p,n-i,r));
	}
	r[n]=q;
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
	printf("the max revenue is:%d",rod_cut(p,m,r));
	return 0;
}
