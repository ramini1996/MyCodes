#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str="Mr John Smith    ";
	int len;
	scanf("%d",&len);
	int end=len-1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==' ')
		{
			for(int j=end;j>=i+1;j--)
			{
				str[j+2]=str[j];
			}
			end+=2;
		}
		str[i]='%';
		str[i+1]='2';
		str[i+2]='0';
	}
	printf("%s",str);
	
	return 0;
}
