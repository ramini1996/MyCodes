#include<bits/stdc++.h>
using namespace std;
bool isUnique(char str[])
{
	if(strlen(str)>128)return false;
	bool char_set[128]={false};
	for(int i=0;i<strlen(str);i++)
	{
		if(char_set[str[i]])
		{
			return false;
		}
		char_set[str[i]]=true;
	}
	return true;
}
int main()
{
	
	char str[1000];
	scanf("%s",str);
	if(isUnique(str))
	printf("Unique");
	else
	printf("Not Unique");
	return 0;
}
