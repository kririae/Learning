/*
正解splay
其实如果没有旋转操作的话什么都能上。
无非就是要支持删除和kth插入。
由于splay的rank是体现在结构上的，所以不用重编号。
Treap配重编号也是可以做的。
当然部分重构级xds也可以哦，
部分重构的xds的时间复杂度分析同替罪羊的分析。
什么数状数组也就算了吧。
链表暴力会死的。
块状链表的分块还是不错的，不过只有四秒。。。 
*/ 
#include<cstdio> 
#include<iostream>
#define N 100005
using namespace std;
int n,m,cnt,root;
const int L=0,R=1;
int hash[N];//编号to splay
int name[N]; 
struct node{
	int son[2],fa,size;
}a[N];
inline void update(int x){
	if(x==0) return;
	a[x].size=a[a[x].son[L]].size+a[a[x].son[R]].size+1;
}
inline void rotate(const int &x,int &k){
	int y=a[x].fa,z=a[y].fa;
    int s=(a[y].son[R]==x);
    a[y].son[s]=a[x].son[s^1];a[a[y].son[s]].fa=y;a[x].son[s^1]=y;a[x].fa=a[y].fa;a[y].fa=x;
    if(y==k) k=x;else a[z].son[a[z].son[R]==y]=x;
    update(y);
}
inline void splay(int x,int &k){
	int y,z;
	while(x!=k){
		y=a[x].fa;z=a[y].fa;
		if(y!=k){
			if((a[y].son[R]==x)^(a[z].son[R]==y)) rotate(x,k);
			else rotate(y,k);
		}
		rotate(x,k);
	}
	update(x);
}
inline int kth(int k,int x){
	while(1){
		int t=a[a[k].son[L]].size+1;
		if(t==x) return k;
		else if(t<x){x-=t;k=a[k].son[R];continue;}
		else{k=a[k].son[L];continue;}
	}
}
inline int rank(int x){
	int ret=1+a[a[x].son[L]].size;
	while(x!=root){
		if(a[a[x].fa].son[R]==x) ret+=a[a[x].fa].size-a[x].size;
		x=a[x].fa;
	}
	return ret;
}
inline void del(int k){
	int t1=rank(k);
	int pr=kth(root,t1-1);
	int ne=kth(root,t1+1);
	splay(pr,root);
	splay(ne,a[root].son[R]);
	a[a[root].son[R]].son[L]=0;
	a[k].fa=0;
	a[root].size--;
	a[a[root].son[R]].size--;
}
void insert(int s,int ran){
	int pr=kth(root,ran);
	int ne=kth(root,ran+1);
	splay(pr,root);
	splay(ne,a[root].son[R]);
	a[a[root].son[R]].son[L]=s;
	a[s].fa=a[root].son[R];
	a[a[root].son[R]].size++;
	a[root].size++;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);hash[t]=i+1;name[i+1]=t;
	}
	for(int i=1;i<=n+2;i++){
		a[i].son[L]=i-1;a[i].fa=i+1;a[i].size=i;
	}
	root=n+2;a[root].fa=0;
	splay(1,root);
	for(int i=1;i<=m;i++){
		char buf[10];int s,t;
		scanf("%s",buf);
		if(buf[0]=='A'){
			scanf("%d",&s); 
			int t=hash[s];
			printf("%d\n",rank(t)-2);
		}else if(buf[0]=='T'){
			scanf("%d",&s);
			s=hash[s];
			del(s);insert(s,1);
		}else if(buf[0]=='I'){
			scanf("%d%d",&s,&t);
			s=hash[s];
			int t2=rank(s);
			del(s);insert(s,t+t2-1);
		}else if(buf[0]=='B'){
			scanf("%d",&s);
			s=hash[s];
			del(s);
			insert(s,n);
		}else if(buf[0]=='Q'){
			scanf("%d",&t);
			printf("%d\n",name[kth(root,t+1)]);
		}
	}
	return 0;
}
