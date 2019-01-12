#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

int low(int x){//lowbit
	return x & (-x);
}

long long bit[N];//树状数组
long long ini[N];//原数组 
//区间加
void add(int k,int val){//[1,k] += val
	for(;k!=0;k-=low(k)) bit[k]+=val;
} 

//单点查询 
long long query(int k){// [k] = ?
	if(k==0) return 0;
	long long ret=ini[k];
	for(;k<N;k+=low(k)) ret+=bit[k];
	return ret;
}

int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&ini[i]),ini[i]+=ini[i-1];
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){//修改 [l,n] += r
			add(n,r);
			add(l-1,-r);
		}else{
			printf("%lld\n",query(r)-query(l-1) );
		}
	}
	return 0;
}











