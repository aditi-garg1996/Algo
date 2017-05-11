#include<stdio.h>
typedef struct node{
	int id;
	double x,y,z;
}node;
void swap(node* a,node* b)
{
	node temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void adjust(node ab[],int i,int n)
{
	int l,r,max;
	l=2*i+1;
	r=2*i+2;
    if(l<n&&(ab[l].z>ab[i].z))
       max=l;
    else
       max=i;
    if(r<n&&(ab[r].z>ab[max].z))
       max=r;
    if(max!=i)
       swap(&ab[i],&ab[max]);
    if(max<n&&i!=max)
       adjust(ab,max,n);
}
void heapsort(node ab[],int n)
{
	int i,j;
	for(i=n/2-1;i>=0;i--)
	{
	  adjust(ab,i,n);
    }
	for(i=n-1;i>=0;i=n-1)	{
		swap(&ab[0],&ab[i]);
		n=n-1;
		adjust(ab,0,n);
	}
}
int main()
{
	int n,b,buc[100],k,i,j;
	node val[100];
	scanf("%d%d",&n,&b);
	for(i=0;i<n;i++)
	  scanf("%d%lf%lf%lf",&(val[i].id),&(val[i].x),&(val[i].y),&(val[i].z));
	heapsort(val,n);
	buc[0]=val[n-1].id;
	buc[1]=val[n-2].id;
	k=n-2;
	while(1)
	{
		char c;
		int a,p,flag=0;
		p=scanf("%c,%d",&c,&a);
		if(p==0)
		  break;
		if(c=='F'||c=='f')
		{
			flag=0;
			for(j=0;j<b;j++)
			{
				if(buc[j]==a)
				{
				  printf("%d->(%lf,%lf,%lf)",val[a-1].id,val[a-1].x,val[a-1].y,val[a-1].z);
				  flag=1;
				  break;
			    }
			}
			if(flag==0)
			   printf("Point doesn’t exist in the bucket.");
		}
		else if(c=='R'||c=='r')
		{
			for(j=0;j<b;j++)
			{
				if(buc[j]==a)
				{
				  printf("Point id %d removed.",a);
				  if(k!=1)
				  {
				     buc[j]=val[k-1].id;
				     k--;
				  }
				  else
				     printf("No more points can be deleted.");
				  flag=1;
				  break;
			    }
			}
			if(flag==0)
			{
				printf("Point doesn’t exist in the bucket.");
			}
		}
	}
}
