#include<stdio.h>
int BinarySearch(int a[],int left,int right,int elem)
{
	int mid;
	mid=(left+right)/2;
	if(left<=right)
	{
	if(a[mid]==elem)
	  return mid;
	else if(elem<mid)
	  return BinarySearch(a,left,mid-1,elem);
	else
	  return BinarySearch(a,mid+1,right,elem);
    }
    else
       return -1;
}
int main()
{
	int N,a[100],elem,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	  scanf("%d",&a[i]);
	scanf("%d",&elem);
	printf("%d",BinarySearch(a,0,N-1,elem));
	return 0;
}
