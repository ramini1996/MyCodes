#include<bits/stdc++.h>
using namespace std;

int search(string strings[],string s,int first,int last)
{
	if(first>last)
	return -1;
	int mid=(first+last)/2;
	if((strings[mid]).empty())
	{
		int left=mid-1;
		int right=mid+1;
		while(left>=first && right<=last)
		{
			if((strings[left]).empty()!=1)
			{
				mid=left;
				break;
			}
			else if((strings[right]).empty()!=1)
			{
				mid=right;
				break;
			}
			left--;
			right++;
		}
	}
	if((strings[mid]).compare(s)==0)
	return mid;
	else if((strings[mid]).compare(s)<0)
	search(strings,s,mid+1,last);
	else if((strings[mid]).compare(s)>0)
	search(strings,s,first,mid-1);
}
int main()
{
	string strings[]={"at","","","","ball","","","car","","","dad","",""};
	string c="ball";
	int n=13;
	cout<<search(strings,c,0,n-1);
	return 0;
	
}
