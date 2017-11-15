#include<bits/stdc++.h>
using namespace std;
void constructST(int arr[],int segarr[],int low,int high,int pos)
{
	if(low==high)
	{
		segarr[pos]=arr[low];
		return;
	}
	int mid=(low+high)/2;
	constructST(arr,segarr,low,mid,2*pos+1);
	constructST(arr,segarr,mid+1,high,2*pos+2);
	segarr[pos]=segarr[2*pos+1]+segarr[2*pos+2];
}
int getSum(int segarr[],int low,int high,int qs,int qe,int pos)
{
	if(qs<=low && qe>=high)
	return segarr[pos];
	if(qs>high || qe<low)
	return 0;
	int mid=(low+high)/2;
	int a=getSum(segarr,low,mid,qs,qe,2*pos+1);
	int b=getSum(segarr,mid+1,high,qs,qe,2*pos+2);
	return a+b;
}
void updateValue(int segarr[],int low,int high,int i,int diff,int pos)
{
	if(i<low || i>high)
	return;
	segarr[pos]+=diff;
	if(low!=high)
	{
		int mid=(low+high)/2;
		updateValue(segarr,low,mid,i,diff,2*pos+1);
		updateValue(segarr,mid+1,high,i,diff,2*pos+2);
	}
}
void update(int arr[],int segarr[],int n,int i,int val)
{
	if(i<0 || i>n-1)
	return;
	int diff=val-arr[i];
	arr[i]=val;
	updateValue(segarr,0,n-1,i,diff,0);
}

int main()
{
	int arr[]={5,2,1,3,4,6,7,9,8,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=ceil(log2(n));
	int p=2*pow(2,x)-1;
	int segarr[p];
	constructST(arr,segarr,0,n-1,0);
	int qs,qe;
	scanf("%d%d",&qs,&qe);
	cout<<getSum(segarr,0,n-1,qs,qe,0)<<endl;
	int i,val;
	scanf("%d%d",&i,&val);
	update(arr,segarr,n,i,val);
	scanf("%d%d",&qs,&qe);
	cout<<getSum(segarr,0,n-1,qs,qe,0)<<endl;
	return 0;
}
