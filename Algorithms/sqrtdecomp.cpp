#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int i;
	int a[]={1,5,2,4,6,1,3,5,7,10,5,7,11,24};
	int n=sizeof(a)/sizeof(a[0]);
	int BLOCK_SIZE=ceil(sqrt(n));
	int BLOCKS=ceil(sqrt(n));
	int b[BLOCKS]={0};
	
	for(i=0;i<n;i++)
	b[i/BLOCK_SIZE]+=a[i];
	
	int q;
	int sum;
	scanf("%d",&q);
	while(q--)
	{
		int qno;
		scanf("%d",&qno);
		if(qno==1)
		{
			int ind,val;
			scanf("%d%d",&ind,&val);
			b[ind/BLOCK_SIZE]=b[ind/BLOCK_SIZE]-a[ind]+val;
			a[ind]=val;
		}
		else if(qno==2)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int s=l/BLOCK_SIZE;
			int e=r/BLOCK_SIZE;
			sum=0;
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
