#include<cstdio>
#include<vector>
using namespace std;
const int INF=999999;
/*-------正常图模板-------*/
struct edge{
	int from,to,dis;edge(int fr,int t,int di):from(fr),to(t),dis(di){}
};
vector<edge> e;int e_len;
vector<int> node[10005];
void addedge(int from,int to,int len){//单向
	e.push_back(edge(from,to,len));node[from].push_back(e_len++);
}
/*-------------拓扑板（未反置，有bug）-----------*/
int tp[10005];int len_tp=1;

int vis[10005];
void DFS1(int u){//访问所有指向自己的点，然后把他们删掉，最后删自己；
	vis[u]=1;
	for(int i=0,len=node[u].size();i<len;i++){
		edge& ed=e[node[u][i]];
		if(vis[ed.to]==0) DFS1(ed.to);
	}
	tp[len_tp++]=u;
}
/*-------------下面是判断连通块-----------------*/
int lt[10005];int cnt_lt=1;
void DFS2(int u,int num){
	lt[u]=num;
	for(int i=0,len=node[u].size();i<len;i++){
		edge& ed=e[node[u][i]];
		if(lt[ed.to]==0) DFS2(ed.to,num);
	}
}
//--------------------------------------------------
int n,m;
void init(){
	scanf("%d%d",&n,&m);
	for(int f,t,i=1;i<=m;i++){
		scanf("%d%d",&f,&t);
		addedge(f,t,0);//沿着箭头反着走后又会再次反向实用，所以干脆反着算了
	}
	
}

int ele[10005];//标号为连通分量
int du[10005];
int all=0;
int main(){
	init();
	for(int i=1;i<=n;i++){//生成反向拓扑序
		if(vis[i]==0)
			DFS1(i);
	}
	for(int i=1;i<=n;i++){
		if(lt[tp[i]]==0){
			DFS2(tp[i],cnt_lt++);
		}
	}
	
	for(int i=1;i<=n;i++){
		printf("%d ",lt[i]);
	} 
	return 0;
}
