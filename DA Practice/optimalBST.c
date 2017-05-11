#include<stdio.h>
int main()
{
	int w[100][100],c[100][100],r[100][100],i,j,k,p[100],q[100],l,cost;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("5d",&p[i]);
	for(i=0;i<=n;i++)
	  scanf("%d",&q[i]);
	for(i=0;i<=n;i++)
	{
		w[i][i]=q[i];
		c[i][i]=0;
		r[i][i]=0;
	}
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=(n-l+1);i++)
		{
			j=i+l-1;
			c[i][j]=9999;
			w[i][j]=w[i-1][j]+p[j]+q[j];
			for(k=i+1;k<=j;k++)
			{
				cost=c[i][k-1]+c[k+1][j]+w[i][j];
				if(cost<c[i][j])
				{
				   c[i][j]=cost;
				   r[i][j]=k;
			    }
			}
		}
	}
}
