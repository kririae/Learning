#include<cstdio>
#include<iostream>
#include<cstring>
#define N 1000005
#define LL long long
using namespace std;
char s[N];
int n;LL k;
const int P=19930726;
struct hwzdj{
	int len,fail;
	int ne[28];
	int times;
}hw[N+26];
int cnt;
void build(){
	cnt=2;hw[1].len=-1;hw[1].fail=1;hw[2].len=0;hw[2].fail=1;int p=1;
	for(int i=1;i<=26;i++){hw[1].ne[i]=++cnt;hw[cnt].len=1;hw[cnt].fail=2;}
	for(int i=1;i<=n;i++){
		while(s[i]!=s[i-hw[p].len-1]) p=hw[p].fail;
		if(hw[p].ne[s[i]]){p=hw[p].ne[s[i]];hw[p].times++;continue;}
		int k=hw[p].ne[s[i]]=++cnt;hw[k].times++;hw[k].len=hw[p].len+2;p=hw[p].fail;
		while(s[i]!=s[i-hw[p].len-1]) p=hw[p].fail;
		hw[k].fail=hw[p].ne[s[i]];
		p=k;
	}
}
int js[N];
LL ans;
inline LL ksm(int a,int x){
	LL ret=1;
	for(int i=1<<30;i;i>>=1)ret=ret*ret*(LL)((x&i)? a:1)%P;
	return ret%P;
}
void count(){
	LL buf=0,maxn=0;
	for(int i=cnt;i>=3;i--){
		if(!(hw[i].len&1)){
			hw[hw[i].fail].times+=hw[i].times;
		}else{
			buf+=hw[i].times,maxn=maxn<hw[i].len? hw[i].len:maxn;
			js[hw[i].len]+=hw[i].times,hw[hw[i].fail].times+=hw[i].times;
		}
	}
	ans=1;
	if(k>buf) {printf("-1\n");return;}
	for(int i=maxn;i>0;i--){
		if((!js[i])||k<=0) continue;
		ans*=ksm(i,js[i]<k?js[i]:k);ans%=P;k-=js[i];
	}
	printf("%I64d\n",ans);
}
int main(){
	scanf("%d%I64d",&n,&k);
	scanf("%s",s+1);
	n=strlen(s+1);for(int i=1;i<=n;i++) s[i]-='a'-1;
	build();
	count();
	return 0;
}
