/*
这真是一道奇怪的题
首先支持换根操作的有LCT和ETT
支持查询子树操作的有ETT和DFS序
支持修改的有DFS序和LCT
ETT会被菊花图的修改虐爆
所以（不会toptree）我就在纠结到底该用那个
想了想DFS序貌似分类讨论下还是可以的。
先以1为根建立DFS
如果查询的点不在1-newroot的路径上那么 子树不变
如果在就是查询的补集，补集会在DFS中是两个区间。
(这个动作容易被菊花图卡爆，但不怕，我们可以二分【先不二分试一下】【lower_bound】)
所以就解决了。
现在考虑LCT怎么改，貌似必须改成Toptree（其实也就是补全节点） 
hh.......我投子
ETT的修改呢 好像也是可以的，可以通过类似于Toptree或边分治的加点做法
在点数*2的代价下完成一个点最多只有三个度的修改
o(^▽^)o，perfect
先写DFS 
这个方法太perfect了，ψ(^w^)ψ我要怎么卡掉DFS序呢？
支持删除合并？看我splay动态维护|(^_^)|
不过这个貌似可以把ETT搞死，不过记录度数维护一下应该死不了 
 换根+lca，这个貌似只有LCT可活
换根+lca+修改+子树最小值+merge split-______-太邪恶了 
这时貌似只有Toptree能用了
不过保留原树后DFS序+倍增lca能解决不分裂的问题
分裂和子树成为了最大的矛盾点
就留在这里吧，挖个坑===\     /====
                hole→ =\___/= 
                
良心样例一下就过了 
*/ 
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define N 100005 
using namespace std;
int xdscnt,root;int d[N*2];//dfs
//---------xds----------------
const int L=0,R=1,INF=0x3f3f3f3f;
struct xds{
	int fr,to,min,son[2];
}x[1800005];
inline void update(int k){
	if(k==0||x[k].fr==x[k].to) return;
	x[k].min=min(x[x[k].son[L]].min,x[x[k].son[R]].min);
}
void build(int &k,int fr,int to){
	k=++xdscnt;x[k].fr=fr;x[k].to=to;
	if(fr==to){x[k].min=d[fr];return;}
	int mid=(fr+to)>>1;
	build(x[k].son[L],fr,mid);
	build(x[k].son[R],mid+1,to);
	update(k);
}
void change(int k,int xx,int y){
	if(x[k].fr==x[k].to){
		x[k].min=y;d[x[k].fr]=y;return;
	}
	int mid=(x[k].fr+x[k].to)>>1;
	if(mid<xx) change(x[k].son[R],xx,y);
	else change(x[k].son[L],xx,y);
	update(k);
}
int query(int k,int fr,int to){
	if(fr>to) return -INF;
	if(x[k].fr==fr&&x[k].to==to){
		return x[k].min;
	}
	int mid=(x[k].fr+x[k].to)>>1;
	if(fr>mid) return query(x[k].son[R],fr,to);
	else if(to<=mid) return query(x[k].son[L],fr,to);
	else return min(query(x[k].son[L],fr,mid),query(x[k].son[R],mid+1,to));
}
//-------------------------
struct node{
	int st,en,val;
	vector<int> x;
}a[N];
int n,m,cnt,troot,newroot;
void DFS(int u){
	a[u].st=++cnt;
	d[cnt]=a[u].val;
	for(int i=0,len=a[u].x.size();i<len;i++){
		DFS(a[u].x[i]);
	}
	a[u].en=++cnt;
	d[cnt]=a[u].val;
}
inline bool cmp1(const int &aa,const int &bb){
	return a[aa].en<a[bb].en;
}
//--------------------------
int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1,f,v;i<=n;i++){
		scanf("%d%d",&f,&v);
		a[i].val=v;
		if(f!=0){
			a[f].x.push_back(i);
		}else troot=i;
	}
	DFS(troot);newroot=troot;
	build(root,1,n<<1);
	for(int i=1;i<=m;i++){
		char s[3];
		int xx,yy;
		scanf("%s",&s);
		if(s[0]=='V'){
			scanf("%d%d",&xx,&yy);
			change(root,a[xx].st,yy);
			change(root,a[xx].en,yy);
		}else if(s[0]=='E'){
			scanf("%d",&xx);
			newroot=xx;
		}else if(s[0]=='Q'){
			scanf("%d",&xx);int ans=0;
			if(xx==newroot){
				ans=query(root,1,n<<1);
			}else if(a[xx].st<a[newroot].st&&a[xx].en>a[newroot].en){
				vector<int>::iterator itr=lower_bound(a[xx].x.begin(),a[xx].x.end(),newroot,cmp1);
				xx=*itr;
				ans=min(query(root,1,a[xx].st-1),query(root,a[xx].en+1,n<<1));
			}else{
				ans=query(root,a[xx].st,a[xx].en);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
} 
