#include<cstdio>
#include<vector>
#define LL long long
using namespace std;
struct edge{
	int f,t;LL dis;
};
edge e[1000015];int e_len;
struct node{
	int father;
	vector<int> sons;
	LL dp;//把该子树所有叶节点调整到同步所需的最小代价 
	LL time;//子树的时间 
}tree[500005];
/* 
inline int read(){
	char c;int ret=0;
	do{
		c=getchar();
		if('0'<=c&&c<='9') ret=ret*10+c-'0';
	}while(c!=' '&&c!='\n');
	return ret;
}*/ 

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void addedge(int from,int to,LL dis){
	e[e_len].dis=dis;e[e_len].f=from;e[e_len].t=to;
	tree[from].sons.push_back(e_len++);
	e[e_len].dis=dis;e[e_len].f=to;e[e_len].t=from;
	tree[to].sons.push_back(e_len++);
}
int n,root;
LL DFS(int u,int fr,LL dis){
	if(tree[u].sons.size()==1){//leaves
		tree[u].time=dis;
		return 0;
	}
	LL allt=0;int len=tree[u].sons.size();
	for(int i=0;i<len;i++){
		edge& ed=e[tree[u].sons[i]];
		if(ed.t!=fr){
			tree[u].dp+=DFS(ed.t,u,dis+ed.dis);
			if(tree[ed.t].time>tree[u].time){
				tree[u].time=tree[ed.t].time;
			}
			allt+=tree[ed.t].time;
		}
	}
	tree[u].dp+=(len-1)*tree[u].time-allt;
	return tree[u].dp;
}
int main(){
	n=read();
	root=read();
	for(int f,t,d,i=1;i<n;i++){
		f=read();t=read();d=read();
		addedge(f,t,d);
	}
	addedge(0,root,0); 
	LL ans=DFS(root,0,0);//初始化和动规 
	//ans+=tree[root].time;//root 没有father 
	printf("%lld",ans);
	return 0;
} 
