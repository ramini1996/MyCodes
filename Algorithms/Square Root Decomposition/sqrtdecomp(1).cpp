#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={1,5,2,4,6,1,3,5,7,10};//example array
	int n=sizeof(a)/sizeof(a[0]);
	int BLOCK_SIZE=ceil(sqrt(n));
	int BLOCKS=ceil(sqrt(n));//handles if n is not a perfect square
	int b[BLOCKS]={0};//ith element stores the sum of ith block
	int i;
	for(i=0;i<n;i++)
	b[i/BLOCK_SIZE]+=a[i];
	
	int q;//number of queries
	scanf("%d",&q);
	while(q--)
	{
		int qno;
		scanf("%d",&qno);//1 for update and 2 for query
		if(qno==1)
		{
			int index,val;
			scanf("%d%d",&index,&val);//a[index]=val
			b[index/BLOCK_SIZE]=b[index/BLOCK_SIZE]-a[index]+val;
			a[index]=val;
		}
		else if(qno==2)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int s=l/BLOCK_SIZE;
			int e=r/BLOCK_SIZE;//block numbers of start and end index
			int sum=0;
			if(s==e)
			{
				for(i=l;i<=r;i++)
				sum+=a[i];
			}
			else
			{
				for(i=s+1;i<=e-1;i++)
				sum+=b[i];
				for(i=l;i<(s+1)*BLOCK_SIZE;i++)
				sum+=a[i];
				for(i=e*BLOCK_SIZE;i<=r;i++)
				sum+=a[i];
			}
			printf("%d\n",sum);
		}
	}
	return 0;	
}
