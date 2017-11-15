#include<bits/stdc++.h>
using namespace std;
string compressString(string s)
{
	string c;
	int i=0;
	while(i<s.length())
	{
		char ch=s[i];
		c+=ch;
		int count=0;
		while(s[i]==ch)
		{
			count++;
			i++;
		}
		c=c+(to_string(count));
	}	
	if(c.length()<s.length())return c;
	else return s;
}

int main()
{
	string s;
	cin>>s;
	cout<<compressString(s);
	return 0;
}
