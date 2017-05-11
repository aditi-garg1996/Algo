#include<stdio.h>
void mcm(int p[],int s[100][100],int m[100][100],int n)
{
	int i,j,k,l,q;
	for(i=1;i<=n;i++)
	  m[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=(n-l+1);i++)
		{
			j=i+l-1;
			m[i][j]=100000000;
			s[i][j]=0;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	     if(i<j)
	       printf("%d ",s[i][j]);
}
void printmat(int s[100][100],int i,int j)
{
	if(i==j)
	   printf("A%d",i);
	else
	{
		printf("(");
		printmat(s,i,s[i][j]);
		printmat(s,s[i][j]+1,j);
		printf(")");
	}
}
int main()
{
	int s[100][100],m[100][100],p[100],i,n;
	printf("Enter the number of matrices");
	scanf("%d",&n);
	printf("Enter the size of matrices:");
	for(i=0;i<=n;i++)
	   scanf("%d",&p[i]);
	mcm(p,s,m,n);
	printmat(s,1,n);
	return 0;
}

