#include<stdio.h>
void InsertionSort(int a[],int N)
{
	int i,j,elem;
	for(i=1;i<N;i++)
	{
		elem=a[i];
		j=i-1;
		while(j>=0&&(a[j]>elem))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=elem;
	}
}
int main()
{
	int N,a[100],i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	   scanf("%d",&a[i]);
	InsertionSort(a,N);
	for(i=0;i<N;i++)
	   printf("%d ",a[i]);
	return 0;
}
