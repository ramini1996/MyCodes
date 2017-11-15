#include<bits/stdc++.h>
using namespace std;

int search(int a[],int x,int low,int high)
{
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)
		return mid;
		else if(a[low]<a[mid])
		{
			if(x>=a[low] && x<a[mid])
			high=mid-1;
			else
			low=mid+1;
		}
		else if(a[low]>a[mid])
		{
			if(x>a[mid] && x<=a[high])
			low=mid+1;
			else
			high=mid-1;
		}		
		else if(a[low]==a[mid])
		{
			if(a[high]!=a[mid])
			low=mid+1;
			else
			{
				int result=search(a,x,mid+1,high);
				if(result==-1)
				return search(a,x,low,mid-1);
				else
				return result;
			}
		}
	}
	return -1;
}
int main()
{
	//int a[]={15,16,17,19,21,2,7,9,12,13};
	int a[]={2,2,2,2,3,4,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<search(a,2,0,n-1);
	return 0;	
}
