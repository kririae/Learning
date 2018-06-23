#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 225
#define INF 1005
using namespace std;
//----------------
struct edge{
	int flow,t,next;
}e[80005];int cnt;
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
//------------------------
void reset(){
	for(int i=2;i<=cnt;i++){
		if(!(i&1)){
			e[i].flow+=e[i^1].flow;
			e[i^1].flow=0;
		}
	}
}
int n;
double d;
int pl[N][2];
int pen[N],mi[N];
void init(){
	memset(head,0,sizeof(head));
	scanf("%d%lf",&n,&d);cnt=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&pl[i][0],&pl[i][1],&pen[i],&mi[i]);
	}
}
int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		init();S=0;int all=0;
		for(int i=1;i<=n;i++){
			addedge(i<<1,(i<<1)^1,mi[i]);
			addedge(S,i<<1,pen[i]);all+=pen[i];
		}
		for(int i=1,t,t2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((t=pl[i][0]-pl[j][0])*t+(t2=pl[i][1]-pl[j][1])*t2<d*d+1e-8){
					addedge((i<<1)^1,j<<1,INF);
					addedge((j<<1)^1,j<<1,INF);
				}
			}
		}
		int t3=0;
		for(int i=1;i<=n;i++){
			reset();
			if(Dinic(S,i<<1)==all) t3=1,printf("%d ",i-1);
		}
		if(!t3) puts("-1");
		else puts("");
	}
	return 0;
}
