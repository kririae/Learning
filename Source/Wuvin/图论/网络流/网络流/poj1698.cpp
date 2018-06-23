#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 405
#define INF 1005
using namespace std;
//----------------
struct edge{
	int flow,t,next;
}e[30005];int cnt;
int head[N];
void addedge(int f,int t,int fl){
	e[++cnt]=(edge){fl,t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){0,f,head[t]};head[t]=cnt;
}
//----------------
int S,T;
int dis[N];
int cur[N];
bool BFS(){
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	queue<int> que;
	que.push(S);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(int i=head[u];i;i=e[i].next){
			if(e[i].flow!=0&&dis[e[i].t]==0x3f3f3f3f){
				dis[e[i].t]=dis[u]+1;
				que.push(e[i].t);
			}
		}
	}
	return dis[T]!=0x3f3f3f3f;
}
int DFS(int u,int a){
	if(u==T||a==0) return a;
	int ret=0;
	for(int &i=cur[u];i;i=e[i].next){
		if(e[i].flow==0||dis[e[i].t]!=dis[u]+1) continue;
		int f=DFS(e[i].t,a<e[i].flow? a:e[i].flow);
		if(f){
			e[i].flow-=f;
			e[i^1].flow+=f;
			ret+=f;
			a-=f;
			if(a==0) return ret;
		}
	}
	return ret;
}
int Dinic(int S1,int T1){
	S=S1,T=T1;
	int ret=0;
	while(BFS()){
		for(int i=0;i<N;i++) cur[i]=head[i];
		ret+=DFS(S1,INF);
	}
	return ret;
}
//----------------
int n;
int on[22][10];
int d[22],t[22];
void init(){
	cnt=1;memset(head,0,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=7;j++) scanf("%d",&on[i][j]);
		scanf("%d%d",&d[i],&t[i]);
	}
}
#define day(x,y) (n+(x)*7+(y)-7)
int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		init();S=0,T=N-1;int all=0;
		for(int i=1;i<=n;i++) addedge(S,i,d[i]),all+=d[i];
		for(int i=1;i<=7;i++) for(int j=1;j<=50;j++) addedge(day(j,i),T,1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=t[i];j++)
				for(int k=1;k<=7;k++){
					if(on[i][k]){
						addedge(i,day(j,k),1);
					}
				}
		}
		all-=Dinic(S,T);
		if(all==0) puts("Yes");else puts("No");
	}
	return 0;
}
