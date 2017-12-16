#include<bits/stdc++.h>
using namespace std;
//////////////WARNING WARNING WARNING THERE ARE PLENTY GROUPS OF DATAS 
/*-------正常图模板-------*/
const int INF=999999;
struct edge{
	int from,to,dis;edge(int fr,int t,int di):from(fr),to(t),dis(di){}
};
vector<edge> e;int e_len;
vector<int> node[16005];
void addedge(int from,int to,int len){//单向 有反向图 
	e.push_back(edge(from,to,len));node[from].push_back(e_len++);
}
/*---------------------*/
int n,m;
int online[16005];//0-null 1-red 2-bule 3-both are ok 
int buf[16005];int cnt=0; 
///////////////////////2-SAT
bool DFS(int u){
	online[u]=1;online[u^1]=2;buf[cnt++]=u;buf[cnt++]=u^1; 
	for(int i=0,len=node[u].size();i<len;i++){
		edge& ed=e[node[u][i]];
		if(online[ed.to]==0){
			if(!DFS(ed.to)) return false;
		}else if(online[ed.to]==2){
			return false;
		}
	}
	return true; 
}
void recover(){
	while(cnt--){
		online[buf[cnt]]=0;
	}
}
int main(){
		scanf("%d%d",&n,&m);
		for(int f,t,i=1;i<=m;i++){
			char a,b;
			cin>>f>>a>>t>>b;
			if(a=='Y') a=2;
			else a=1;
			if(b=='Y') b=2;
			else b=1;
			f=f*2-a;t=t*2-b;
			addedge(f^1,t,0);//必须共存
			addedge(t^1,f,0);//反向弧
		}
		bool fl=true;
		for(int i=0;i<2*n;i++){
			if(online[i]==0){
				cnt=0;
				if(DFS(i)){
					recover();
					if(DFS(i^1)){
						recover();
						online[i]=online[i^1]=3;
					}else{
						recover();
						DFS(i);
					}
				}else{
					if(DFS(i^1)){
					}else{
						printf("IMPOSSIBLE\n");fl=false;break;
					}
				}
				
				
			}
		}
		if(!fl) return 0;
		for(int i=0;i<n;i++){
			if(online[i*2]==1){
				printf("Y");	
			}else if(online[i*2]==2){
				printf("N");
			}else{
				printf("?");
			}
		}
	return 0;
}
