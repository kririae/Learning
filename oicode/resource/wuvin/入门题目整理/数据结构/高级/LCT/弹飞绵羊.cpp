#include<cstdio>
#include<iostream>
#define N 200005
#define ls a[t.son[L]]
#define rs a[t.son[R]]
using namespace std;
//bzoj2010
inline int read(){
    int x=0;char c=getchar();int f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();return x*f;
}
const int L=0,R=1;
//----------------------------
int size=0;
struct node{//一定要这样开空间啊，不然慢一倍啊 
    int son[2],fa,size;//splay
    int tree_fa,hson; 
}a[N];
inline void update(const int &k){
    if(k==0) return;node& t=a[k];
    t.size=ls.size+rs.size+1;
}
inline void rotate(const int &x,int &k){
    int y=a[x].fa,z=a[y].fa;//pushdown(y);pushdown(x);
    int s=(a[y].son[R]==x);
    a[y].son[s]=a[x].son[s^1];a[a[y].son[s]].fa=y;a[x].son[s^1]=y;a[x].fa=a[y].fa;a[y].fa=x;
    if(y==k) k=x;else a[z].son[a[z].son[R]==y]=x;
    update(y);
}
inline void splay(const int &x,int k){//没有全局root 
    int fx[3];fx[1]=x;//0-y 1-x 2-z
    while(x!=k){
        fx[0]=a[fx[1]].fa;fx[2]=a[fx[0]].fa;
        if(fx[0]!=k)  rotate(fx[(a[fx[0]].son[L]==fx[1])^(a[fx[2]].son[L]==fx[0])],k);
        rotate(fx[1],k);
    }
    update(x);
}
inline int getmin(int k){//找出k的子树中最小的 
    while(a[k].son[L]!=0){
        k=a[k].son[L];
    }
    return k;
}
inline int get_root(int k){
    while(a[k].fa!=0){
        k=a[k].fa;
    }
    return k;
}
inline void cut_right(int k){
    int t=get_root(k);splay(k,t);
    a[a[k].son[R]].fa=0;a[k].son[R]=0;update(k);
}
inline int insert_min(int k,int buf){ 
    int end=k;
    while(a[k].son[L]!=0){a[k].size++;k=a[k].son[L];}
    a[k].size++;a[k].son[L]=buf;
    a[buf].fa=k;a[buf].size=1;
    splay(buf,end);
    return k;
}
void build(int size_){
    size=size_;
    for(int i=1;i<=size;i++){
        a[a[i].tree_fa].hson=i;
    }
    for(int i=1;i<=size;i++){
        if(a[i].hson==0) a[i].size=1;
        else insert_min(a[i].hson,i);
    }
}
inline void access(int k){
    cut_right(k);int roo=k;
    k=getmin(roo);
    while(k!=size){
        int t=a[k].tree_fa;a[t].hson=k;
        cut_right(t);a[t].son[R]=roo;a[roo].fa=t;
        update(t);roo=t;k=getmin(roo);
    }
}
int n,m;
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i].tree_fa=min(read()+i,n+1);
    }
    build(n+1);
    m=read();
    for(int i=1;i<=m;i++){
        if(read()==1){
            int t=read()+1; 
            access(t);splay(n+1,get_root(n+1));
            int ans=a[n+1].size;
            printf("%d\n",ans-1);
        }else{
            int t=read()+1,v=read();
            if(a[a[t].tree_fa].hson==t) cut_right(a[t].tree_fa);
            a[t].tree_fa=min(t+v,n+1);
        }
    }
    return 0;
} 
