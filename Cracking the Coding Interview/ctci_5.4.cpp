#include<bits/stdc++.h>
using namespace std;

int getNext(int n)
{
	int c=n;
	int c0=0;
	int c1=0;
	while((c&1)==0 && (c!=0))
	{
		c0++;
		c>>=1;
	}
	while((c&1)==1)
	{
		c1++;
		c>>=1;
	}
	if(c0+c1==31 || c0+c1==0)
	return -1;
	int p=c0+c1;
	n=n|(1<<p);
	n=n&~((1<<p)-1);
	n=n|(1<<(c1-1))-1;
	return n;
}
int getPrev(int n)
{
	int c=n;
	int c0=0;
	int c1=0;
	while((c&1)==1)
	{
		c1++;
		c>>=1;
	}
	if(c==0)
	return -1;
	while((c&1)==0 && (c!=0))
	{
		c0++;
		c>>=1;
	}
	int p=c0+c1;
	n=n&(~(1<<p));
	n=n&(~((1<<p)-1));
	//n&=((~0)<<(p+1));
	int mask=(1<<(c1+1))-1;
	n|=mask<<(c0-1);
	return n;
	
}

int main()
{
	cout<<getNext(13948);
	cout<<endl;
	cout<<getPrev(10115);
	return 0;
}
