#include<bits/stdc++.h>
using namespace std;

int fibRecursive(int n)
{
	if(n<0)return 0;
	else if(n==0)return 1;
	return fibRecursive(n-1)+fibRecursive(n-2)+fibRecursive(n-3);
}


int fib(int n,int memo[])
{
	if(n<0)return 0;
	else if(n==0)return 1;
	
	if(memo[n]==0)
	{
		memo[n]=fib(n-1,memo)+fib(n-2,memo)+fib(n-3,memo);
	}
	return memo[n];
}

int fib(int n)
{
	int memo[n+1];
	memset(memo,0,sizeof(memo));
	return fib(n,memo);
}

int main()
{
	int n;
	scanf("%d",&n);
	cout<<fib(n);	
	//cout<<fibRecursive(n);
	return 0;
}
