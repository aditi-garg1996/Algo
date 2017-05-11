#include<stdio.h>
void merge(int a[],int left,int mid,int right)
{
	int i,j,k,n1,n2;
	n1=mid-left+1;
	n2=right-mid;
	int l[n1+1],r[n2+1];
	for(i=1;i<=n1;i++)
	   l[i]=a[left+i-1];
	for(j=1;j<=n2;j++)
	   r[j]=a[mid+j];
	l[n1+1]=10000;
	r[n2+1]=20000;
	i=1,j=1,k=1;
	for(k=left;k<=right;k++)
	{
		if(l[i]<=r[j])
		   a[k]=l[i++];
		else
		   a[k]=r[j++];
	}
}
void mergesort(int a[],int left,int right)
{
	int mid;
	mid=(left+right)/2;
	if(left<right)
	{
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
int main()
{
	int N,a[100],i;
	printf("Enter the size");
	scanf("%d",&N);
	printf("\nEnter the elements:");
	for(i=1;i<=N;i++)
	   scanf("%d",&a[i]);
	mergesort(a,1,N);
	printf("\nThe sorted list is:");
	for(i=1;i<=N;i++)
	   printf("%d ",a[i]);
	return 0;   
}
