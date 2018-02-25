#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 2305
using namespace std;
const int INF=99999999;
struct edge{
	int from,to,flow;//flow-可用流量  返向弧flow=0 
	edge(int from_,int to_,int flow_){from=from_;to=to_;flow=flow_;}
};
vector<edge> e;int e_len=0;
vector<int> node[N];
void addedge(int from,int to,int flow){
	e.push_back(edge(from,to,flow));
	node[from].push_back(e_len++);
	e.push_back(edge(to,from,0));
	node[to].push_back(e_len++);
}
int S,T;
int dis[N];//分层图 
bool BFS(){//分层 
	memset(dis,0,sizeof(dis));
	queue<int> x;
	dis[S]=1;
	x.push(S);
	while(!x.empty()){
		int u=x.front();x.pop();
		for(int i=0,len=node[u].size();i<len;i++){
			edge& ed=e[node[u][i]];
			if(dis[ed.to]!=0||ed.flow==0) continue;
			dis[ed.to]=dis[u]+1;
			x.push(ed.to);
		}
	}
	if(dis[T]==0) return false;
	return true;
}
int cur[N];
int DFS(int u,int a){//多路增广  a-可行流 
	if(u==T||a==0) return a;
	int flow=0;
	for(int &i=cur[u],len=node[u].size();i<len;i++){//pay attention to &i 
		edge& ed=e[node[u][i]];
		if(dis[ed.to]!=dis[u]+1||ed.flow==0) continue;
		int f=DFS(ed.to,min(a,ed.flow));
		if(f){
			a-=f;flow+=f;
			ed.flow-=f;e[node[u][i]^1].flow+=f;
			if(a==0) return flow;
		}
	}
	return flow;
}
int Dinic(){
	int maxflow=0;
	while(BFS()){
		memset(cur,0,sizeof(cur));
		maxflow+=DFS(S,INF);
	}
	return maxflow;
}
//----------------------
/*
黑白染色最小割 
*/
int xx[5]={0,0,0,-1,1};
int yy[5]={0,1,-1,0,0};
int n,m;
inline int c(int x,int y){
	int ret=(x-1)+(y-1)*n+3;
	return ret;
}
char map[50][50];
int ans=0;
void work(int ca){
	scanf("%d%d",&n,&m);S=0;T=1;
	for(int i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for(int i=1;i<=n;i++){//统一 E . 
		for(int j=1;j<=m;j++){
			if(map[i][j]=='E'||map[i][j]=='.'){
				int s=(i+j)&1;
				for(int k=1;k<=4;k++){
					if((map[i+xx[k]][j+yy[k]]=='E'||map[i+xx[k]][j+yy[k]]=='.')&&(s!=0)){
						addedge(c(i,j),c(i+xx[k],j+yy[k]),2);
					}
				}
				int v=(map[i][j]=='E')? 4:10;
				if(s) addedge(S,c(i,j),v);
				else addedge(c(i,j),T,v);
				ans+=4;
			}
		} 
	}
	ans-=Dinic();
	printf("Case %d: %d\n",ca,ans);
}
int T2;
int main(){
	scanf("%d",&T2);
	for(int tt=1;tt<=T2;tt++){
		ans=0;e_len=0;e.clear();
		memset(map,0,sizeof(map));int b=c(n,m);
		for(int i=0;i<=b;i++){
			node[i].clear();
		}
		work(tt);
	}
	return 0;
}
