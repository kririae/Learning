#include<cstdio>
#include<cmath>
#define N 100005
#define LL long long
/*
终于有道我做得起的分块了。
前两道跪得太厉害了。
对于每个块，维护总和，最大前缀。 
好像我有不会了，怎么办，先颓一会再说
好吧解法鬼畜，我又跪了 
*/
using namespace std;
int fr[1005],to[1005];//块
int maxn[1005];
LL sum[1005];
LL add[1005];//lazy标记 
int a[N];
int n,m,f,p;//p块的个数 
void build(int k){//建立第k块 
	maxn[k]=sum[k]=0;
	for(int i=fr[k];i<=to[k];i++){
		sum[k]+=a[i];if(a[i]>maxn) maxn=a[i];
	}
	maxn[k]+=add[k];
	sum[k]+=(to[k]-fr[k]+1)*add[k];
}
inline void interval_add(int from,int to_,int c){
	for(int i=1;i<=p;i++){
		if(fr[i]>=from&&to[i]<=to_){
			sum[i]+=(to[i]-fr[i]+1)*c;
			add[i]+=c;
			maxn[i]+=c; 
		}else if(fr[i]>to_){
			break;
		}else if(to[i]<from){
			continue;
		}else{//暴力 
			for(int j=max(from,fr[i]);j<=min(to[i],to_)){
				a[i]+=c;
			}
			build(i);
		}
	}
}
LL query(int from,int to_){
	int ret=0;
	for(int i=1;i<=p;i++)
}

int main(){
	scanf("%d",&n);f=sqrt(n)+0.001;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1,p=1;i<=n;i+=f,p++){
		fr[x]=i;en[x]=min(n,i+f-1);
	}
	for(int i=1;i<=p;i++){
		build(i);
	}
	scanf("%d",&m);
	for(int i=1,ins;i<=m;i++){
		scanf("%d",&ins);
		if(ins==0){
			int f,t,c;
			scanf("%d%d%d",&f,&t,&c);
			interval_add(f,t,c);
		}else{
			int f,t;
			scanf("%d%d",&f,&t);
			printf("%lld\n",query(f,t));
		}
	}
	return 0;
} 
