#include<bits/stdc++.h>
using namespace std;

void sortedMerge(int a[],int b[])
{
	int n1=8;
	int n2=4;
	int i=0;
	int j=0;
	while(j<n2)
	{
		if(a[i]<=b[j])
		i++;
		else
		{
			for(int k=n1-n2-(j+1);k>=i;k--)
			a[k+1]=a[k];
			a[i]=b[j];
			j++;
		}
	}
}



int main()
{
	int a[8]={2,10,30,50};
	int b[4]={8,15,39,70};
	sortedMerge(a,b);
	for(int i=0;i<8;i++)
	cout<<a[i]<<" ";
	return 0;
	
}
