#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn=30;
int a[maxn],n; double ans;

void dfs(int dep,int pre,int type,int64 sum,int seq_cnt,int cnt){
	if(dep==n+1){
		if(cnt) ans=max(ans,1.0*sum/seq_cnt);
		return;
	}
	if(type==0){
		if(a[dep]<=pre)
			dfs(dep+1,a[dep],type^1,sum+a[dep],seq_cnt+1,cnt+1);
		else dfs(dep+1,a[dep],type,sum+a[dep],seq_cnt,cnt+1); 
	}
	else{
		if(a[dep]>=pre)
			dfs(dep+1,a[dep],type^1,sum+a[dep],seq_cnt+1,cnt+1);
		else dfs(dep+1,a[dep],type,sum+a[dep],seq_cnt,cnt+1);
	}
	dfs(dep+1,pre,type,sum,seq_cnt,cnt);
}

int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	scanf("%d",&n),ans=0.0;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	dfs(1,-1,0,0,1,0);
	printf("%.3f\n",ans);
	return 0;
}