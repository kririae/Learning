#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int NN=1000+5;
const int MM=27;
struct ACzdj{
	int ch[NN][MM];
	int val[NN];
	int f[NN];
	int size;
	int root;
	int transform(char &h){
		return h-'a';
	}
	ACzdj(){
		memset(ch,0,sizeof(ch));
		memset(f,0,sizeof(f));
		memset(val,0,sizeof(val));
		//初始点0 
		size=1;root=0;
	}
	void addword(char* s,int key){//key != 0
		int len=strlen(s);
		int p=root;
		for(int i=0;i<len;i++){
			int d=transform(s[i]);
			if(ch[p][d]){
				p=ch[p][d];
			}else{
				ch[p][d]=size++;
				p=ch[p][d];
			}
			if(i==len-1){
				val[p]=key;
			}
		}
	}
	void prefail(){//失配边与转移一视同仁 
		queue<int> x;
		for(int i=0;i<MM;i++){//第一圈 
			if(ch[root][i]){
				x.push(ch[root][i]);
			}
		}
		while(!x.empty()){
			int u=x.front();x.pop();
			/*千万别掉了这句 不然被hack*/if(val[f[u]]!=0) f[u]=val[f[u]]; 
			for(int i=0;i<MM;i++){
				int v=ch[u][i];
				if(v==0){//失配  空 
					ch[u][i]=ch[f[u]][i];continue;
				}
				f[v]=ch[f[u]][i];
				x.push(v);
			}
		}
	}
	
	int find(char *s){//返回所有模版中第一次匹配 
		int sl=strlen(s);
		int p=root;
		for(int i=0;i<sl;i++){
			int d=transform(s[i]);
			p=ch[p][d];
			if(val[p]){
				return val[p];
			}
		}
		return 0;
	}
};
/*
hack:
2
aca 100
c 10

*/

int main(){
	ACzdj ac;
	int n;
	scanf("%d",&n);
	char p[100];
	for(int j,i=1;i<=n;i++){
		scanf("%s",p);
		scanf("%d",&j);
		ac.addword(p,j);
	}
	ac.prefail();
	printf("%d",ac.find("ac"));
	return 0;
}
