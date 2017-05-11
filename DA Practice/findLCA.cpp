#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
#define n 9
int ind;
int euler[2*n - 1];       // For Euler tour sequence
int level[2*n - 1];       // Level of nodes in tour sequence
int firstOccurrence[n+1]; // First occurences of nodes in tour
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
// A Binary Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
void construct_tree(int seg[],int pos,int left,int right)
{
	if(left==right){
	  seg[pos]=left;
	  return;
    }
    int mid=(left+right)/2;
    construct_tree(seg,2*pos+1,left,mid);
    construct_tree(seg,2*pos+2,mid+1,right);
    if (level[seg[2*pos+1]] < level[seg[2*pos+2]])
            seg[pos] = seg[2*pos+1];
        else
            seg[pos] = seg[2*pos+2];
}
int min_query(int seg[],int start,int end,int pos,int left,int right)
{
	if(start<=left&&end>=right)
	   return seg[pos];
	if(right<start||left>end)
	   return -1;
	int mid=(left+right)/2;
	int q=min_query(seg,start,end,2*pos+1,left,mid);
	int r=min_query(seg,start,end,2*pos+2,mid+1,right);
	if(q==-1)
	  return r;
	if(r==-1)
	  return q;
	return (level[q] < level[r])?q:r;
}
void eulerTour(Node *root, int l)
{
    /* if the passed node exists */
    if (root)
    {
        euler[ind] = root->key; // insert in euler array
        level[ind] = l;         // insert l in level array
        ind++;                  // increment index
 
        /* if unvisited, mark first occurrence */
        if (firstOccurrence[root->key] == -1)
            firstOccurrence[root->key] = ind-1;
 
        /* tour left subtree if exists, and remark euler
           and level arrays for parent on return */
        if (root->left)
        {
            eulerTour(root->left, l+1);
            euler[ind]=root->key;
            level[ind] = l;
            ind++;
        }
 
        /* tour right subtree if exists, and remark euler
           and level arrays for parent on return */
        if (root->right)
        {
            eulerTour(root->right, l+1);
            euler[ind]=root->key;
            level[ind] = l;
            ind++;
        }
    }
}
int findLCA(Node* root,int u,int v)
{
	ind=0;
	memset(firstOccurrence,-1,sizeof(firstOccurrence));
	eulerTour(root,0);
	for(int i=0;i<2*n-1;i++)
	  cout<<euler[i]<<" ";
	cout<<endl;
	for(int i=0;i<2*n-1;i++)
	  cout<<level[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
	  cout<<firstOccurrence[i]<<" ";
	int seg[100];
	construct_tree(seg,0,0,2*n-2);
	cout<<endl;
	for(int i=0;i<2*(2*n-1)-1;i++)
	  cout<<seg[i]<<" ";
	for(int i=0;i<2*n-1;i++)
	  cout<<level[i]<<" ";
	 if (firstOccurrence[u]>firstOccurrence[v])
       swap(&u,&v);
 
    // Starting and ending indexes of query range
    int qs = firstOccurrence[u];
    int qe = firstOccurrence[v];
 
	int index=min_query(seg,qs,qe,0,0,2*n-2);
	return euler[index];
}
int main()
{
	Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->right->left = newNode(8);
    root->left->right->right = newNode(9);
 
    int u = 4, v = 9;
    printf("The LCA of node %d and node %d is node %d.\n", 
            u, v, findLCA(root, u, v));
    return 0;
}

