#include<bits/stdc++.h>
using namespace std;

string printBinary(double d)
{
	string c;
	c=c+".";
	while(d>0)
	{
		d=d*2;
		if(d>=1)
		{
			c=c+"1";
			d-=1;
		}
		else
		{
			c=c+"0";
		}
		if(c.length()==33)
		{
			return "ERROR"
		}
	}
	return c;
}
int main()
{
	cout<<printBinary(0.703125);
	return 0;
}
