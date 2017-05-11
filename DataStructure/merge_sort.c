#include<stdio.h>
void Merge(int a[],int left,int right,int mid)
{
	int i,j,temp[1000],k;
	i=left;
	j=mid+1;
	k=0;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
		}
		else 
		{
		  temp[k++]=a[j++];
	    }
	}
	while(i<=mid)
	   temp[k++]=a[i++];
	while(j<=right)
	   temp[k++]=a[j++];
	for(i=0;i<k;i++)
	   a[i+left]=temp[i];
}
void MergeSort(int a[],int left,int right)
{
	int mid;
	mid=(left+right)/2;
	if(left<right)
	{
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,right,mid);
	}
}
int main()
{
	int N,a[100],i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	   scanf("%d",&a[i]);
	MergeSort(a,0,N-1);
	for(i=0;i<N;i++)
	   printf("%d ",a[i]);
	return 0;
}
