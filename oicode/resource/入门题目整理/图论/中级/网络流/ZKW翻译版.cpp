/*
ZKW ∑≠“Î∞Ê 
*/
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define N 105
using namespace std;
const int INF=0x70000000;
int n;
struct edge{
	int from,to,cap,flow,cost;
	edge(int from_,int to_,int cap_,int flow_,int cost_){
		from=from_;to=to_;cap=cap_;flow=flow_;cost=cost_;
	}
};
vector<edge> e;int len;
vector<int> node[N];
int lens[N];
int dis[N];
void addedge(int from,int to,int cap,int flow,int cost){
	e.push_back(edge(from,to,cap,flow,cost));
	node[from].push_back(len++);
	e.push_back(edge(to,from,cap,-flow,-cost));
	node[to].push_back(len++);
}
int vis[N];int cur[N];
void SPFA(int start,int end){
    for(int i=0;i<=n;i++)
        vis[i]=false,dis[i]=INF;
    queue<int> Q;
    Q.push(start);dis[start]=0;vis[start] = true;
    while(!Q.empty()){
    	int u=Q.front();Q.pop();  
        vis[u]=false;  
        for(int i=0;i<lens[u];i++){
			edge& ed=e[node[u][i]];  
        	if(ed.cap<=ed.flow||dis[ed.to]<=dis[u]+ed.cost) continue;  
            dis[ed.to]=dis[u]+ed.cost;
            if(!vis[ed.to]){
				vis[ed.to]=true;
				Q.push(ed.to);
            }
        }
    }
	for(int i=0;i<=n;i++)
		dis[i]=dis[end]-dis[i];
}
int S,T;
int mincost;
bool adjust(){
	int xmin=INF;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(int j=0;j<lens[i];j++){
			edge& ed=e[node[i][j]];
			if(vis[ed.to]||ed.cap<=ed.flow) continue;
			xmin=min(xmin,dis[ed.to]+ed.cost-dis[i]);
		}
	}
	if(xmin==INF) return false;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			dis[i]+=xmin;vis[i]=false;
		}
	}
	memset(cur,0,sizeof(cur));
}
int augment(int u,int a,int &maxflow){
	if(u==T||a==0){
		mincost+=a*dis[S],maxflow+=a;
		return a;
	}
	vis[u]=true;
	for(int i=cur[u];i<lens[u];i++){
		edge& ed=e[node[u][i]];
		if(ed.cap<=ed.flow||vis[ed.to]||dis[u]!=dis[ed.to]+ed.cost)
			continue;
		int f=augment(ed.to,min(ed.cap-ed.flow,a),maxflow);
		if(f){
			a-=f;
			ed.flow+=f;
			e[node[u][i]^1].flow-=f;
			return f;
		}
	}
	return 0;
}
int ZKW(int St,int En,int flow){
	for(int i=1;i<=n;i++)
		lens[i]=node[i].size();
	SPFA(St,En);mincost=0;S=St;T=En;
	memset(vis,false,sizeof(vis));
	do{
		while(augment(S,flow,flow)){
			memset(vis,false,sizeof(vis));
		}
	}while(flow&&adjust());
	if(flow>0){
		return -1;
	}
	return mincost;
}
int main(){
	
	return 0;
}
