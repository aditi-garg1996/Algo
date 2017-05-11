#include<stdio.h>
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void adjust(int a[],int i,int n)
{
	int l,r,max;
	l=2*i+1;
	r=2*i+2;
    if(l<n&&a[l]>a[i])
       max=l;
    else
       max=i;
    if(r<n&&a[r]>a[max])
       max=r;
    if(max!=i)
       swap(&a[i],&a[max]);
    if(max<n&&i!=max)
       adjust(a,max,n);
}
void heapsort(int a[],int n)
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
	int i,n,a[100];
	printf("Enter the size of an array");
	scanf("%d",&n);
	printf("Enter the array elements");
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	heapsort(a,n);
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	   printf("%d ",a[i]);
}

