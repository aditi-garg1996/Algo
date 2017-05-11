#include<stdio.h>
int mcm(int p[],int i,int j,int s[100][100],int m[100][100])
{
	int k,q;
	if(m[i][j]<100000000)
	   return m[i][j];
	if(i==j)
	{
	  m[i][j]=0;
	  return 0;
    }
	for(k=i;k<=j-1;k++)
	{
		q=mcm(p,i,k,s,m)+mcm(p,k+1,j,s,m)+p[i-1]*p[k]*p[j];
		if(q<m[i][j])
		{
		  m[i][j]=q;
		  s[i][j]=k;
	    }
	}
	return m[i][j];
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
	int s[100][100],p[100],i,j,n,m[100][100];
	printf("Enter the number of matrices");
	scanf("%d",&n);
	printf("Enter the size of matrices:");
	for(i=0;i<=n;i++)
	   scanf("%d",&p[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		  m[i][j]==100000000;
	}
    mcm(p,1,n,s,m);
	printmat(s,1,n);
	return 0;
}

