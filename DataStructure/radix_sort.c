#include<stdio.h>
int digits(int a[],int n)
{
	int i,l,max=0,count=0;
	for(i=0;i<=n;i++)
	{
		l=a[i];
		count=0;
		while(l)
		{
			count++;
			l/=10;
		}
		if(count>max)
		  max=count;
	}
	return max;
}
int power(int a,int b)
{
	int i=1,p=1;
	for(i=1;i<=b;i++)
	{
		p*=a;
	}
	return p;
}
void counting_sort(int a[],int n,int j,int k)
{
	int i,c[10]={0},l,b[100];
	for(i=1;i<=n;i++)
	{
		l=a[i]/(power(10,j-1));
		l=l%10;
		c[l]++;
	}
	for(i=1;i<=k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=n;i>=1;i--)
	{
		l=a[i]/power(10,j-1);
		l=l%10;
	    b[c[l]]=a[i];
	    c[l]--;
	}
	for(i=1;i<=n;i++)
	  a[i]=b[i];
}
void radix_sort(int a[],int n,int k)
{
	int i;
	for(i=1;i<=k;i++)
	{
		counting_sort(a,n,i,10);
	}
}
int main()
{
	int n,i,a[100],d;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements of an array:");
	for(i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	d=digits(a,n);
	radix_sort(a,n,d);
	printf("The sorted array is:");
	for(i=1;i<=n;i++)
	   printf("%d ",a[i]);
	return 0;
}
