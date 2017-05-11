#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void quicksort(int a[],int left,int right)
{
	int pivot,i,j;
	i=left-1;
	pivot=right;
	if(left<right)
	{
	for(j=left;j<right;j++)
	{
		if(a[j]<=a[pivot])
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[pivot]);
	quicksort(a,left,i);
	quicksort(a,i+2,right);
    }
}
int main()
{
	int N,a[100],i;
	printf("Enter the size:");
	scanf("%d",&N);
	printf("Enter the elements of an array:");
	for(i=1;i<=N;i++)
	   scanf("%d",&a[i]);
	quicksort(a,1,N);
	printf("\nThe sorted array is:");
	for(i=1;i<=N;i++)
	   printf("%d ",a[i]);
	return 0;
}
