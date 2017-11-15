#include<bits/stdc++.h>
using namespace std;
bool isPerm(char str1[],char str2[])
{
	if(strlen(str1)!=strlen(str2))return false;
	int n=strlen(str1);
	int a1[26]={0};
	int a2[26]={0};
	for(int i=0;i<n;i++)
	{
		a1[str1[i]-'a']++;
		a2[str2[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(a1[i]!=a2[i])
		return false;
	}
	return true;	
}
int main()
{
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	if(isPerm(str1,str2))
	cout<<"Permutation";
	else
	cout<<"Not a permutation";
	return 0;
}


