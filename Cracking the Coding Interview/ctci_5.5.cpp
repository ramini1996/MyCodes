#include<bits/stdc++.h>
using namespace std;

/*int flipNumber(int a,int b)
{
	if(a==b)
	return 0;
	int c=a^b;
	int count=0;
	while(c!=0)
	{
		count=count+(c&1);
		c>>=1;
	}
	return count;
}*/
int flipNumber(int a,int b)
{
	if(a==b)
	return 0;
	int c=a^b;
	int count=0;
	while(c!=0)
	{
		c=c&(c-1);
		count++;
	}
	return count;
}
int main()
{
	cout<<flipNumber(29,15);
	return 0;
}
