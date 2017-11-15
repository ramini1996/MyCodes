#include<bits/stdc++.h>
using namespace std;
#define Q 1000
#define BLOCK 4

struct node{
	int L,R,i;
}q[Q];
bool cmp(node x,node y){
	if(x.L/BLOCK!=y.L/BLOCK)
		return x.L/BLOCK<y.L/BLOCK;
	return x.R<y.R;
}
int main(){
	int ans[100];
	int a[]={2,4,7,8,9,5,3,2,1,4};
	int n=sizeof(a)/sizeof(a[0]);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&q[i].L,&q[i].R);
		q[i].i=i;	
	}
	
	sort(q,q+m,cmp);
	/*for(int i=0;i<m;i++)
    printf("%d %d %d",q[i].L,q[i].R,q[i].i);*/
	int i=0,j=0,sum=0;
	for(int k=0;k<m;k++){
		int L=q[k].L;
		int R=q[k].R;
		
		while(i<L){
			sum-=a[i];
			i++;
		}
		while(j<=R){
			sum+=a[j];
			j++;
		}
		while(i>L){
			sum+=a[i-1];
			i--;
		}
		while(j>R+1){
			sum-=a[j-1];
			j--;
		}
		ans[q[i].i]=sum;
	//	printf("%d///",sum);
	}
	cout<<endl;
	for(int i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
