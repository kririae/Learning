#include<bits/stdc++.h>
#define N 66005
using namespace std;
const int INF=9999999;
struct edge{
	int from,to,flow;//flow-可用流量  返向弧flow=0 
	//edge(int from_,int to_,int flow_){from=from_;to=to_;flow=flow_;}
	//edge(){}
};
struct Vec{
	edge edg[1000005];
	int V_len;
	Vec(){
		V_len=0;
	}
	void push_back(int from,int to,int flow){
		edg[V_len].flow=flow;edg[V_len].from=from;edg[V_len].to=to;V_len++;
	}
	edge& operator [](const int i){
		return edg[i];
	}
};Vec e;int e_len=0;
vector<int> node[N];
void addedge(int from,int to,int flow){
	e.push_back(from,to,flow);
	node[from].push_back(e_len++);
	e.push_back(to,from,0);
	node[to].push_back(e_len++);
}
int S,T;
int dis[N];//分层图 
bool BFS(){//分层 
	memset(dis,0,sizeof(int)*(T+2));
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
	for(int &i=cur[u],len=node[u].size();i<len;i++){
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
		memset(cur,0,sizeof(int)*(T+2));
		maxflow+=DFS(S,INF);
	}
	return maxflow;
}
int x,y,z,d;
int c(int x1,int y1,int z1){
	if(z1==0)return 0;
	return (z1-1)*x*y+(x1-1)*y+y1;
}

int w[43][43][43];//不和谐度
int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int main(){
	//scanf("%d%d%d%d",&x,&y,&z,&d);//长宽高delta
	x=read();y=read();z=read();d=read();
	T=x*y*z+1;S=0;
	for(int i=1;i<=z;i++){
		for(int j=1;j<=x;j++){
			for(int k=1;k<=y;k++){
				w[j][k][i]=read();
			}
		}
	}
	//(x,y,z)->(x,y,z+1)对应(x,y,z)的点值
	for(int i=1;i<=z;i++){
		for(int j=1;j<=x;j++){
			for(int k=1;k<=y;k++){
				addedge(c(j,k,i-1),c(j,k,i),w[j][k][i]);
			}
		}
	}
	for(int j=1;j<=x;j++){
		for(int k=1;k<=y;k++){
			//addedge(S,c(j,k,1),INF);
			addedge(c(j,k,z),T,INF);
		}
	}
	for(int i=1;i<=z;i++){
		if(i+d>z) continue;
		for(int j=1;j<=x;j++){
			for(int k=1;k<=y;k++){
				if(j+1<=x){
					addedge(c(j+1,k,i+d),c(j,k,i),INF);
				}
				if(j-1>=1){
					addedge(c(j-1,k,i+d),c(j,k,i),INF);
				}
				if(k+1<=y){
					addedge(c(j,k+1,i+d),c(j,k,i),INF);
				}
				if(k-1>=1){
					addedge(c(j,k-1,i+d),c(j,k,i),INF);
				}
			}
		}
	}
	int ans=Dinic();
	printf("%d\n",ans);
	return 0;
} 
