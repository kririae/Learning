/*
6级算法？傻逼最小费用流呵呵呵
有种最小链覆盖带权的即视感
模板练习 
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 405
#define INF 500
//------------------------
struct edge{
	int fr,to,flow,cost,next;
}e[N*N*3];int ecnt=1;
int head[N];int S,T;
void addedge(int f,int t,int flow,int cost){
	e[++ecnt]={f,t,flow,cost,head[f]};head[f]=ecnt;
	e[++ecnt]={t,f,0,-cost,head[t]};head[t]=ecnt;
}
//------------------------
int dis[N];queue<int> que;
int inque[N];
int from[N];
int SPFA(){
	memset(dis,0x3f,sizeof(dis));
	memset(inque,0,sizeof(inque));
	que.push(S);
	dis[S]=0;from[S]=0;
	while(!que.empty()){
		int u=que.front();que.pop();inque[u]=0;
		for(int i=head[u];i;i=e[i].next){
			if(e[i].flow<=0||dis[e[i].to]<=dis[u]+e[i].cost) continue;
			if(!inque[e[i].to]) que.push(e[i].to),inque[e[i].to]=1;
			from[e[i].to]=i;
			dis[e[i].to]=dis[u]+e[i].cost;
		}
	}
	if(dis[T]==0x3f3f3f3f) return INF*5;
	int t=INF,p=from[T];
	while(p!=0) t=min(e[p].flow,t),p=from[e[p].fr];
	p=from[T];
	while(p!=0) e[p].flow-=t,e[p^1].flow+=t,p=from[e[p].fr];
	return t*dis[T];
}
int MCMF(int flow){//忘了ZKW怎么写了，不过这种图ZKW会跑死吧 
	int cost=0;
	int t;
	while(t=SPFA()-INF*5){
		cost+=t+INF*5;
	}
	return cost;
}
//-----------------------
int n,ans;
struct th{
	int c,k;
	bool operator <(const th &b)const{
		if(c!=b.c) return c<b.c;
		else return k<b.k;
	}
}hz[N];
#define cal(i,s) ((i)+200*s)
int main(){
	S=401,T=402;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&hz[i].c,&hz[i].k);
	}
	sort(hz+1,hz+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(hz[i].c==hz[i-1].c&&hz[i].k==hz[i-1].k) continue;
		hz[++cnt]=hz[i];
	}
	n=cnt;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&hz[i].c>=hz[j].c&&hz[i].k>=hz[j].k)
				addedge(cal(i,0),cal(j,1),INF,0);
		}
	}
	for(int i=1;i<=n;i++){
		addedge(S,cal(i,0),1,0);
		addedge(cal(i,1),T,1,-hz[i].c*hz[i].k);ans+=hz[i].c*hz[i].k;
	}
	cout<<ans+MCMF(INF)<<endl;
	return 0;
}
