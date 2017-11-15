#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string a,string b)
{
	int j;
	for(int i=0;i<a.length();i++)
	{
		for(j=0;j<b.length();j++)
		{
			if(b[j]!=a[i+j])
			break;
		}
		if(j==b.length())
		return true;
	}
	return false;
}

bool isRotation(string s1,string s2)
{
	if(s1.length()!=s2.length())
	return false;
	s2=s2+s2;
	if(isSubstring(s2,s1))
	return true;
	return false;
}
/*bool isRotation(string s1,string s2)
{
	int j;
	if(s1.length()!=s2.length())
	return false;
	char ch=s2[0];
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]==ch)
		{
			string c;
			for(j=i;j!=i-1;j=(j+1)%s1.length())
			{
				c=c+s1[j];	
			}
			c=c+s1[j];	
			if(isSubstring(s2,c))
			return true;
		}	
	}	
	return false;
}*/
int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	if(isRotation(s1,s2))
	cout<<"true";
	else
	cout<<"false";
	return 0;
}
