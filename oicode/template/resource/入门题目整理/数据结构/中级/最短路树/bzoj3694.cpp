/*
看hzwer说这题可以链剖+线段树
但貌似可以更简单。
以下称不经过1到n的最短路树的最后一条边的路径叫“path2” 
每个点的 path2要么来自自己的子树中，要么来自连向该点的
一条非树边(else path)。
path2[a]=min(path2[son[a][i]]+dis[a][i],else path+else point);
注意非树边可能连向子孙 

好吧我承认这个方法是错的。
完美死在良心的样例
5 9
3 1 3 1
1 4 2 1 
2 1 6 0
2 3 4 0
5 2 3 0
3 2 2 1
5 3 1 1
3 5 2 0
4 5 4 0 
*/ 
#include<cstdio>
#include<iostream>
#include<vector>
#define N 4000
#define M 100000 
#define INF 0x7ff00000;
using namespace std;
struct edge{int fr,to,dis,ontree;};
edge e[M];int e_len;
vector<int> node[N];
inline void addedge(int fr,int to,int dis,int ontree){
	e[e_len]=(edge){fr,to,dis,ontree};node[fr].push_back(e_len++);
	e[e_len]=(edge){to,fr,dis,ontree};node[to].push_back(e_len++); 
}
//^^^^^^^^^^^^^愉快的分割线^^^^^^^^^^^^^^^^^^^^^
int n,m;
int dis[N],dis2[N],lca[N][14],deep[N];
bool intree(int fa,int so){
	int p=deep[so]-deep[fa];
	if(p<0) return false;
	for(int i=0;i<=13;i++){
		if((1<<i)&p) so=lca[so][i];
	}
	return fa==so;
}
void DFS1(int u,int from,int diss,int deeps){
	dis[u]=diss;dis2[u]=INF;int f=0;lca[u][0]=from;deep[u]=deeps;
	for(int i=1;(1<<i)<=deeps;i++) lca[u][i]=lca[lca[u][i-1]][i-1];
	for(int i=0,len=node[u].size();i<len;i++){
		edge &d=e[node[u][i]];
		if(d.to==from&&d.ontree==1){f=i;continue;}
		if(d.ontree==1) DFS1(d.to,u,diss+d.dis,deeps+1);
	}
	swap(node[u][0],node[u][f]);
}
void DFS2(int u){
	for(int i=1,len=node[u].size();i<len;i++){
		edge &d=e[node[u][i]];
		if(d.ontree==1) DFS2(d.to);
	}
	for(int i=1,len=node[u].size();i<len;i++){
		edge &d=e[node[u][i]];
		if(intree(u,d.to))	dis2[u]=min(dis2[u],dis2[d.to]+dis[d.to]-dis[u]);
		else dis2[u]=min(dis2[u],dis[d.to]+d.dis);
	}
}
void init(){
	addedge(0,1,0,0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		addedge(a,b,c,d);
	}
}
int main(){
	init();
	DFS1(1,0,0,0);
	DFS2(1);
	for(int i=2;i<=n;i++) printf("%d ",dis2[i]);
	return 0;
}
