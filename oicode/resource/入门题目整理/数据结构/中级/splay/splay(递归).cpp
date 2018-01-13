/*
第一个splay
*/ 
#include<cstdio>
#include<iostream> 
#define N 100005
using namespace std;
const int L=0,R=1;
int root,cnt;
int son[N][2],val[N],fa[N],size[N];
inline void update(int k){
    size[k]=size[son[k][L]]+size[son[k][R]]+1;
}
//递归旋转就是好写 
inline void dx(int &k,int side){
	int t=son[k][side];son[k][side]=son[t][side^1];
	fa[son[k][side]]=k;son[t][side^1]=k;fa[t]=fa[k];fa[k]=t;
	update(k);update(t);k=t;
} 
inline void sx(int &k,int side){
	int y=son[k][side],x=son[y][side];
	son[y][side]=son[x][side^1];fa[son[y][side]]=y;
	son[k][side]=son[y][side^1];fa[son[k][side]]=k;
	son[x][side^1]=y;fa[y]=x;fa[x]=fa[k];
	son[y][side^1]=k;fa[k]=y;
	update(k);update(y);update(x);k=x; 
}
bool insert(int &k,int val_,int from,int fx){//让儿子返回是否要双旋 
	if(k==0){
		k=++cnt;val[k]=val_;son[k][L]=son[k][R]=0;size[k]=1;fa[k]=from;return false;
	}else{
		size[k]++;int side=val_<val[k]? L:R;
		bool xz=insert(son[k][side],val_,k,side);
		if(xz)	sx(k,side);
		else if(fx==side) return true;
		else dx(k,side);
		return false;
	}
}
bool splay(int &k,int val_,int fx){//如果非要单独splay就这样
	//do sth 
	int side=val_<val[k]? L:R;
	if(son[k][side]==0) return false;
	bool xz=splay(son[k][side],val_,side);
	if(xz)	sx(k,side);
	else if(fx==side) return true;
	else dx(k,side);
	return false;
}
int rank_kth(int k,int th){// 
	if(th==size[son[k][L]]+1) return val[k];
	else if(th>size[son[k][L]]+1) return rank_kth(son[k][R],th-size[son[k][L]]-1);
	else return rank_kth(son[k][L],th); 
}
int val_kth(int k,int va){
	if(va==val[k]) return size[son[k][L]]+1;
	else if(va>val[k]) return 1+size[son[k][L]]+val_kth(son[k][R],va);
	else return val_kth(son[k][L],va);
}
int n,m,ans;
int main(){
    root=0;cnt=0;ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int t;scanf("%d",&t);
    	if(i==1) ans+=t,insert(root,t,0,3);
    	else{
    		insert(root,t,0,3);
    		int rank=val_kth(root,t);
    		int ret=0x3f3f3f3f;
    		if(rank!=1){
    			ret=min(ret,t-rank_kth(root,rank-1));
			}
			if(rank!=i){
				ret=min(ret,rank_kth(root,rank+1)-t);
			}
			ans+=ret;
		}
	}
	printf("%d",ans);
    return 0;
}
