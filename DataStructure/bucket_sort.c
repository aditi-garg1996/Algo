#include<stdio.h>
typedef struct node{
	int count;
	int c[10];
}node;
void InsertionSort(int a[],int N,int elem)
{
	int j;
		while(j>=0&&(a[j]>elem))
		{
			a[j+1]=a[j];
			j--;
			printf("\\\\\\");
		}
		a[j+1]=elem;
}
void bucket_sort(int a[],int m)
{
	node b[10]={0};
	int i,j,index,k,l;
	for(i=1;i<=m;i++)
	{
		index=a[i]/10;
		l=b[index].count;
		printf("*****");
		InsertionSort(b[index].c,l,a[i]);
		printf("%%%%%%");
		b[index].count++;
	}
	k=1;
	for(i=0;i<10;i++)
	{
		for(j=0;j<b[i].count;j++)
		     a[k]=b[i].c[j];
	}
}
int main()
{
	int n,a[100],i;
	printf("Enter the size of an array");
	scanf("%d",&n);
	printf("Enter the array elements");
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	bucket_sort(a,n);
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	   printf("%d ",a[i]);
}
