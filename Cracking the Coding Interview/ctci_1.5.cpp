#include<bits/stdc++.h>
using namespace std;
bool oneAway(char s1[],char s2[])
{
	int n1=strlen(s1);
	int n2=strlen(s2);
	int count=0;
	if(n1==n2)
	{
		for(int i=0;i<n1;i++)
		{
			if(s1[i]!=s2[i])
			count++;
			if(count>1)return false;
		}
		return true;
	}
	else
	{
		if(n1-n2>1 || n2-n1>1)
		return false;
		if(n1>n2)
		{
			for(int i=0;i<n2;i++)
			{
				if(s2[i]!=s1[i] && s2[i]!=s1[i+1])
				return false;
			}
			return true;
		}
		else if(n2>n1)
		{
			for(int i=0;i<n1;i++)
			{
				if(s1[i]!=s2[i] && s1[i]!=s2[i+1])
				return false;
			}
			return true;
		}
	}
}

int main()
{
	char s1[100],s2[100];
	gets(s1);gets(s2);
	if(oneAway(s1,s2))
	printf("true");
	else
	printf("false");
	return 0;	
}

