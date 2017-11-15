#include<bits/stdc++.h>
using namespace std;
int pairwiseSwap(int n)
{
	return ((n&0xaaaaaaaa)>>1)|((n&0x55555555)<<1);//>>>
}
int main()
{
	cout<<pairwiseSwap(10);
	return 0;
}
