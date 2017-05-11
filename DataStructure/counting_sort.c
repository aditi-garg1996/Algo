#include<stdio.h>
void counting_sort(int a[],int b[],int n,int k)
{
	int i,c[6]={0};
	for(i=1;i<=n;i++)
	{
		c[a[i]]++;
	}
	for(i=1;i<=k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=n;i>=1;i--)
	{
	    b[c[a[i]]]=a[i];
	    c[a[i]]--;
	}
}
int main()
{
	int n,a[100],b[100],i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements of an array:");
	for(i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	counting_sort(a,b,n,5);
	printf("The sorted array is:");
	for(i=1;i<=n;i++)
	   printf("%d ",b[i]);
	return 0;
}
