#include<stdio.h>
int mcm(int p[],int i,int j,int s[100][100])
{
	int k,q,m[100][100];
	if(i==j)
	  return 0;
	m[i][j]=100000000;
	for(k=i;k<=j-1;k++)
	{
		q=mcm(p,i,k,s)+mcm(p,k+1,j,s)+p[i-1]*p[k]*p[j];
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
	int s[100][100],p[100],i,n;
	printf("Enter the number of matrices");
	scanf("%d",&n);
	printf("Enter the size of matrices:");
	for(i=0;i<=n;i++)
	   scanf("%d",&p[i]);
    mcm(p,1,n,s);
	printmat(s,1,n);
	return 0;
}

