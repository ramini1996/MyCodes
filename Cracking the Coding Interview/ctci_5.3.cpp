#include<bits/stdc++.h>
using namespace std;
/*int flipBit(int n)
{
	int len=0;
	int temp=n;
	while(temp>0)
	{
		temp/=2;
		len++;		
	}	
	int s[len];
	int k=0;
	s[k++]=-1;
	for(int i=0;i<len;i++)
	{
		if((n&(1<<i)) == 0)
		s[k++]=i;
	}
	s[k++]=len; 
	int max=0;
	int currmax;
	for(int i=1;i<k-1;i++)
	{
		currmax=s[i+1]-s[i-1]-1;
		if(currmax>max)
		max=currmax;
	}
	return max;
}*/
int flipBit(int a)
{
	int currlen=0;
	int maxlen=0;
	int prevlen=0;
	while(a!=0)
	{
		if((a&1)==1)
		currlen++;
		else if((a&1)==0)
		{
			prevlen=(a&2)==0?0:currlen;
			currlen=0;
		}
		if(prevlen+currlen+1>maxlen)
		maxlen=prevlen+currlen+1;
		a/=2;
	}
	return maxlen;
}

int main()
{
	cout<<flipBit(43);
	return 0;	
}
