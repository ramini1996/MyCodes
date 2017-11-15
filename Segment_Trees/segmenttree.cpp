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
	segarr[pos]=segarr[2*pos+1]+segarr[2*pos+2];
}

int getSum(int segarr[],int l,int r,int qs,int qe,int pos)
{
	if(qs<=l && qe>=r)
	return segarr[pos];
	if(qs>r || qe<l)
	return 0;
	int mid=l+(r-l)/2;
	int a=getSum(segarr,l,mid,qs,qe,2*pos+1);
	int b=getSum(segarr,mid+1,r,qs,qe,2*pos+2);
	return (a+b);
}


void updateValue(int segarr[],int l,int r,int i,int diff,int pos)
{
	if(i<l || i>r)
	return;
	segarr[pos]+=diff;
	if(l!=r)
	{
		int mid=l+(r-l)/2;
		updateValue(segarr,l,mid,i,diff,2*pos+1);
		updateValue(segarr,mid+1,r,i,diff,2*pos+2);
	}
}

void update(int arr[],int segarr[],int n,int i,int val)
{
	if(i<0 || i>n-1)
	{
		printf("Invalid Input");
		return;
	}
	int diff=val-arr[i];
	arr[i]=val;	
	updateValue(segarr,0,n-1,i,diff,0);	
}

int main()
{
	int arr[]={5,2,1,3,4,6,7,9,8,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=ceil(log2(n));//log2->log to the base 2,log2(10)->3.32,ceil(log2(10))=4
	int p=2*pow(2,x)-1;
	int segarr[p];
	int pos=0;
	constructST(arr,segarr,0,n-1,pos);
	/*for(int i=0;i<p;i++)
	cout<<segarr[i]<<" ";
	cout<<endl;*/
	int qs,qe;
	cin>>qs>>qe;
	int ans=getSum(segarr,0,n-1,qs,qe,pos);
	cout<<ans;
	int i,newval;
	cin>>i>>newval;
	update(arr,segarr,n,i,newval);
	int a,b;
	cin>>a>>b;
	cout<<getSum(segarr,0,n-1,a,b,pos);
	return 0;
}
