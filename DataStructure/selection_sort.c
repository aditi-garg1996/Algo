#include<stdio.h>
void SelectionSort(int a[],int N)
{
	int min,i,j,temp;
	for(i=0;i<N-1;i++)
	{
		min=i;
		for(j=i+1;j<N;j++)
		{
			if(a[j]<a[min])
			  min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
int main()
{
	int N,a[100],i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	   scanf("%d",&a[i]);
	SelectionSort(a,N);
	for(i=0;i<N;i++)
	   printf("%d ",a[i]);
	return 0;
}
