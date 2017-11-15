#include<bits/stdc+ +.h>
using namespace std;
int main()
{
	char str[100];
	gets(str);
	int n=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')n++;
	}
	int a[26]={0};
	int k;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>=65 && str[i]<=90)
		k=str[i]+32-'a';
		else
		k=str[i]-'a';
		a[k]++;
		a[k]%=2;
	}
	int count=0;
	int ans;
	for(int i=0;i<26;i++)
	{
		if(a[i]==1)count++;
	}
	if(n%2==0 && count>0)ans=0;
	else if(n%2==1 && count!=1)ans=0;
	else ans=1;
	if(ans)
	printf("True");
	else
	printf("False");
	return 0;
}
