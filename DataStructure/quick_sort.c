#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void QuickSort(int a[],int left,int right)
{
	int pivot,i,j;
	i=left;
	j=right+1;
	pivot=left;
	if(left<right)
	{
	while(i<j)
	{
		do{
			i++;
		}while(i<=right&&(a[i]<a[pivot]));
		do{
			j--;
		}while(j>left&&(a[j]>a[pivot]));
		if(i<j)
		{
		    swap(&a[j],&a[pivot]);
		}
	}
		swap(&a[j],&a[pivot]);
		QuickSort(a,left,j-1);
	    QuickSort(a,j+1,right);
    }
}
int main()
{
	int N,a[100],i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	   scanf("%d",&a[i]);
	QuickSort(a,0,N-1);
	for(i=0;i<N;i++)
	   printf("%d ",a[i]);
	return 0;
}
