#include<stdio.h>
typedef struct node{
	int max_left,max_right;
	int total_sum;
}node;
node cross_max_subarray(int b[],int left,int mid,int right)
{
	int left_sum=-2390,right_sum=-3456,sum=0,k;
	node c;
	for(k=mid;k>=left;k--){
	    sum=sum+b[k];
	    if(sum>left_sum)
	    {
		    c.max_left=k;
		    left_sum=sum;
      	}
    }
    sum=0;
    for(k=mid+1;k<=right;k++){
    	sum=sum+b[k];
    	if(sum>right_sum)
    	{
    		right_sum=sum;
    		c.max_right=k;
		}
	}
    c.total_sum=left_sum+right_sum;
    return c;
}
node max_subarray(int a[],int left,int right)
{
	node c,d,e;
	int mid;
	if(left==right)
	{
		c.max_left=left;
		c.max_right=right;
		c.total_sum=a[left];
		return c;
	}
	else
	{
		mid=(left+right)/2;
		c=max_subarray(a,left,mid);
		d=max_subarray(a,mid+1,right);
		e=cross_max_subarray(a,left,mid,right);
		if(((c.total_sum)>(d.total_sum))&&((c.total_sum)>(e.total_sum)))
		    return c;
		else if(((d.total_sum)>(c.total_sum))&&((d.total_sum)>(e.total_sum)))
		    return d;
		else
		    return e;
	}
}
int main()
{
	node b;
	int a[100],n,i;
	printf("Enter the size:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	b=max_subarray(a,0,n-1);
	for(i=b.max_left;i<=b.max_right;i++)
	{
		printf("%d ",a[i]);
	}
	printf("The maximum sum is:%d",b.total_sum);
	return 0;
}
