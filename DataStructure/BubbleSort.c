#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void BubbleSort(int a[],int N)
{
	int i,j;
    for(i=0;i<N-1;i++)
    {
    	for(j=0;j<N-1-i;j++)
    	{
    		if(a[j]>a[j+1])
    		  swap(&a[j],&a[j+1]);
		}
	}
}
int main()
{
	int N,a[100],i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	   scanf("%d",&a[i]);
	BubbleSort(a,N);
	for(i=0;i<N;i++)
	   printf("%d ",a[i]);
	return 0;
}
