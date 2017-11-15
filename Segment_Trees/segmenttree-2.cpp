#include<bits/stdc++.h>
using namespace std;
void constructST(int arr[],int segarr[],int l,int r,int pos)
{
	if(l==r)
	{
		segarr[pos]=arr[l];
		return;	
	}
	int mid=l+(r-l)/2;
	constructST(arr,segarr,l,mid,2*pos+1);
	constructST(arr,segarr,mid+1,r,2*pos+2);
	segarr[pos]=min(segarr[2*pos+1],segarr[2*pos+2]);	
}

int getMin(int segarr[],int l,int r,int qs,int qe,int pos)
{
	if(qs<=l && qe>=r)
	return segarr[pos];
	if(qs>r || qe<l)
	return INT_MAX;
	int mid=l+(r-l)/2;
	int a=getMin(segarr,l,mid,qs,qe,2*pos+1);
	int b=getMin(segarr,mid+1,r,qs,qe,2*pos+2);
	return min(a,b);
}
void updateMin(int segarr[],int l,int r,int i,int val,int pos)
{
	if(i<l || i>r)
	return;
	if(val<segarr[pos])
	segarr[pos]=val;
	if(l!=r)
	{
		int mid=l+(r-l)/2;
		updateMin(segarr,l,mid,i,val,2*pos+1);
		updateMin(segarr,mid+1,r,i,val,2*pos+2);
	}
}
void update(int arr[],int segarr[],int n,int i,int val)
{
	if(i<0 || i>n-1)
	{
		cout<<"Invalid";
		return;
	}
	arr[i]=val;
	updateMin(segarr,0,n-1,i,val,0);
}
int main()
{
	int arr[]={5,2,1,3,4,6,7,9,8,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=ceil(log2(n));
	int p=2*pow(2,x)-1;
	int segarr[p];
	int pos=0;
	constructST(arr,segarr,0,n-1,pos);
	int qs,qe;
	cin>>qs>>qe;
	int min=getMin(segarr,0,n-1,qs,qe,pos);
	cout<<min<<endl;
	int i,val;
	cin>>i>>val;
	update(arr,segarr,n,i,val);
	int a,b;
	cin>>a>>b;
	cout<<getMin(segarr,0,n-1,a,b,pos)<<endl;
	return 0;		
}

