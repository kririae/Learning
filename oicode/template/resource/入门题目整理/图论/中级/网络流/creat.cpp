#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define N 5005
using namespace std;
const int INF=1001001;const int RD=0;const int CD=1;
int n,S,T;
struct edge{
	int from,to,cap,flow,cost;
	edge(int from_,int to_,int cap_,int flow_,int cost_){
		from=from_;to=to_;cap=cap_;flow=flow_;cost=cost_;
	}
};
vector<edge> e;int len;
vector<int> node[N];
vector<int> tome[N];
int lens[N];//由于是网络流所以正向弧数量等于反向弧 

void addedge(int from,int to,int cap,int flow,int cost){
	e.push_back(edge(from,to,cap,flow,cost));
	node[from].push_back(len++);
	tome[to].push_back(len-1);
	e.push_back(edge(to,from,0,-flow,-cost));
	node[to].push_back(len++);
	tome[from].push_back(len-1);
}

queue<int> x;bool inq[N];int dis[N];bool vis[N];//请初始化 
void SPFAG(){//SPFA改 
	while(!x.empty()){
		int u=x.front();x.pop();inq[u]=false;
		for(int i=0;i<lens[u];i++){//优化自己 
			edge& ed=e[tome[u][i]];
			if(ed.flow>=ed.cap||vis[ed.from]||inq[ed.from]) continue;
			if(dis[ed.from]+ed.cost<dis[u])
				dis[u]=dis[ed.from]+ed.cost;
		}
		for(int i=0;i<lens[u];i++){//优化周围 
			edge& ed=e[node[u][i]];
			if(ed.flow>=ed.cap||inq[ed.to]) continue;
			if(dis[ed.to]>dis[u]+ed.cost){
				dis[ed.to]=dis[u]+ed.cost;
				inq[ed.to]=true;
				x.push(ed.to);
			}
		}
	}
}
int mincost,maxflow;
int DFS(int u,int a){
	if(u==T){
		mincost+=a*dis[T];
		maxflow-=a;
		return a;
	}
	vis[u]=true;
	x.push(u);inq[u]=true;
	int ret=0;
	for(int i=0;i<lens[u];i++){//优化周围 
		edge& ed=e[node[u][i]];
		if(dis[ed.to]!=dis[u]+ed.cost||vis[ed.to]||ed.flow>=ed.cap) continue;
		int f=DFS(ed.to,min(a,ed.cap-ed.flow));
		if(f){
			a-=f;ret+=f;
			ed.flow+=f;
			e[node[u][i]^1].flow-=f;
		}
	}
	return ret;
}
bool adjust(){
	for(int i=0;i<=n;i++)
		if(vis[i])	dis[i]=INF;
	vis[T]=true;dis[T]=INF;dis[S]=0;
	SPFAG();
	if(dis[T]==INF) return false;
	return true;
}
int WKL(int from,int to,int maxflow_){
	//初始化 
	S=from;T=to;
	for(int i=0;i<=n;i++){
		dis[i]=INF;inq[i]=false;
	}
	dis[S]=0;dis[T]=0;
	x.push(S);inq[S]=true;
	SPFAG();
	mincost=0;maxflow=maxflow_;
	do{
		memset(vis,false,sizeof(vis));
		DFS(S,maxflow);
	}while(maxflow&&adjust());
	if(maxflow==0){
		return mincost;
	}else{
		return 1;
	}
}
int n2;
int tocoding(int m1,int n1,int side){//m-行 n-列  side-分裂的点 
	return (m1-1)*n2+n1+side*n2*n2;
}
int map[55][55];
int k;
void build(){
	for(int i=1;i<=n2;i++){
		for(int j=1;j<=n2;j++){
			addedge(tocoding(i,j,RD),tocoding(i,j,CD),1,0,-map[i][j]);
			addedge(tocoding(i,j,RD),tocoding(i,j,CD),15,0,0);
			if(j+1<=n2)
				addedge(tocoding(i,j,CD),tocoding(i,j+1,RD),15,0,0);
			if(i+1<=n2)
				addedge(tocoding(i,j,CD),tocoding(i+1,j,RD),15,0,0);
		}
	}
	n=tocoding(n2,n2,CD);
	for(int i=1;i<=n;i++){
		lens[i]=node[i].size();
	}
}

int main(){
	scanf("%d%d",&n2,&k);
	int p=0;
	for(int i=1;i<=n2;i++){//行 
		for(int j=1;j<=n2;j++){//列 
			scanf("%d",&map[i][j]);
		}
	}
	//building
	build();int maxflow=0;
	int ans=WKL(tocoding(1,1,RD),tocoding(n2,n2,CD),k);
	printf("%d",-ans);
	return 0;
} 
