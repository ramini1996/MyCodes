#include<bits/stdc++.h>
using namespace std;

void sort(string arr[],int n)
{
	map<string,vector<string> > m;
	for(int i=0;i<n;i++)
	{
		string c=arr[i];
		sort(c.begin(),c.end());
		m[c].push_back(arr[i]);
	}
	map<string,vector<string> > :: iterator it;
	int k=0;
	for(it=m.begin();it!=m.end();it++)
	{
		for(int i=0;i<it->second.size();i++)
		arr[k++]=it->second[i];
	}
}
int main()
{
	//string arr[]={"harsha","akash","sujith","khaas","rshaha","sakha"};
	string arr[]={"cat","dog","tac","god","act"};
	int n=sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<endl;
	return 0;
}
