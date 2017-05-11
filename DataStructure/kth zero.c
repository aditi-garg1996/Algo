#include<stdio.h>
int main()
{
	int n,m,a[100],i,j,q,r,s,count,flag=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	for(j=0;j<m;j++)
	{
		scanf("%d",&q);
		if(q==1)
		  scanf("%d",&r);
		else if(q==2)
		  scanf("%d%d",&r,&s);
		if(q==1)
		{
			count=0;
			flag=0;
			for(i=0;i<n;i++)
			{
				if(a[i]==0)
				  count++;
			    if(count==r)
			    {
			    	flag=1;
			    	r=i;
			    	break;
				}
			}
			if(flag==1)
			  printf("%d\n",r);
			else
			  printf("NO\n");
		}
		else if(q==2)
		{
			a[r]=s;
		}
	}
	return 0;
}
