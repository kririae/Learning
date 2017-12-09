#include<cstdio>
#include<vector>
#include<stack>
/*
详见我的讲解
(我并没有看过任何模板)
wuvin.lofter.com
*/
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
/*-------连通分量错误板（codevs无压力过）-----------*/
int lt[10005];//储存各点连通分量的标号
int lt_cnt=1;
int vis[10005];
int round[10005];
int mint[10005]; 
int clk_cnt=1;//时钟
stack<int> x;
int DFS(int u,int rd){//缩点，返回可以到达的时间最小点
	vis[u]=clk_cnt++;
	round[u]=rd;
	mint[u]=vis[u];
	int ret=vis[u];
	x.push(u);
	for(int i=0,len=node[u].size();i<len;i++){
		edge &ed=e[node[u][i]];
		if(round[ed.to]!=0&&round[ed.to]!=rd) continue;
		//if(ed.to==from) continue; 这不是双向边
		if(vis[ed.to]!=0){
			ret=min(ret,mint[ed.to]);
		}else{
			int t=DFS(ed.to,rd);
			ret=min(ret,t);
		}
	}
	if(ret==vis[u]){
		int p=0;
		do{
			p=x.top();x.pop();
			lt[p]=lt_cnt;
		}while(p!=u);
		lt_cnt++;
	}
	mint[u]=ret;
	return ret;
}
/*------------------------------*/
int n,m;
void init(){
	scanf("%d%d",&n,&m);
	for(int f,t,i=1;i<=m;i++){
		scanf("%d%d",&f,&t);
		addedge(f,t,0);
	}
}

int ele[10005];//标号为连通分量
int du[10005];
int all=0;
int main(){
	init();
	for(int i=1;i<=n;i++){
		if(vis[i]==0)//别忘了！！！！！
			DFS(i,i);
	}
	
	 //输出调试 
	for(int i=1;i<=n;i++){
		printf("%d ",lt[i]);
	}
	//现在视为每条边是连通分量连向连通分量 
	//被所有的牛认为是受欢迎的牛只会存在于一个连通分量中
	//现在拓扑收缩只留下一个点(连通分量)
	all=lt_cnt-1;int ans=0;int num=0;
//还是检查边靠谱
	for(int i=0,len=e.size();i<len;i++){
		edge &ed=e[i];
		if(lt[ed.to]!=lt[ed.from]){
			du[lt[ed.from]]++;
		}
	}
	for(int i=1;i<=n;i++) ele[lt[i]]++;
	int ans2=0;
	for(int i=1;i<=all;i++){
		if(du[i]==0){
			num++;ans=i;
		}
		if(ele[i]>1){
			ans2++;
		}
	}
	printf("%d\n",ans2);
	if(num==1&&(ele[ans]>1)){
		for(int i=1;i<=n;i++){
			if(lt[i]==ans) printf("%d ",i);
		}
	}else{
		printf("-1\n");
	}
	return 0;
}
