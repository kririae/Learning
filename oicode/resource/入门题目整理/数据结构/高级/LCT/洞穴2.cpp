#include<bits/stdc++.h>
#define N 100005
using namespace std;
//树上父亲不用保留
//重链的父亲时前驱，轻边上的是fa
//不用维护size 
//------LCT------
const int L=0,R=1;
struct LCT{
    int son[2],fa;
    int rv;
}a[N];
#define rs(k) a[k].son[R]
#define ls(k) a[k].son[L]
void pushdown(int k){
    if(a[k].rv!=0){
        a[k].rv=0;swap(ls(k),rs(k));
        a[ls(k)].rv^=1;a[rs(k)].rv^=1;
    }
}
inline void rotate(int k,int &aim){
    int y=a[k].fa,z=a[y].fa;
    int s=a[y].son[R]==k;
    a[k].fa=z;
    a[y].son[s]=a[k].son[s^1];a[k].son[s^1]=y;
    a[a[y].son[s]].fa=y;a[a[k].son[s^1]].fa=k;
    if(y==aim) aim=k;//update(y);
    else a[z].son[a[z].son[R]==y]=k;//don't forget
}
inline void splay(int k,int &aim){
    int to=aim,y,z;
    while(k!=to){
        y=a[k].fa;z=a[y].fa;
		pushdown(a[z].fa);pushdown(z);pushdown(y);pushdown(k);
        if(y!=to){
            if((rs(y)==k)^(rs(z)==y)) rotate(k,to);
            else rotate(y,to);
        }rotate(k,to);
    }
    aim=k;//update(k);
}
inline int getmn(int k){for(;pushdown(k),ls(k)!=0;k=ls(k));return k;}
inline void cut_right(int k){
    int u=k;for(;a[a[u].fa].son[L]==u||a[a[u].fa].son[R]==u;u=a[u].fa);
    splay(k,u);pushdown(k);rs(k)=0;//update(k);
}
inline int access(int k){
    cut_right(k);
    for(;;){
        splay(getmn(k),k);
        if(a[k].fa==0) return k;
        int u=a[k].fa;cut_right(u);rs(u)=k;k=u;//update(u);
    }
}

#define cut(u,v) (a[access(u)].rv^=1,cut_right(u),a[v].fa=0)
#define link(u,v) (a[access(v)].rv^=1,cut_right(v),a[v].fa=u)
//--------------
#define query(u,v) (access(u)==access(v))

int n,m;
char ins[20];
int main(){
    scanf("%d%d",&n,&m);//no build
    for(int i=1,x,y;i<=m;i++){
        scanf("%s%d%d",ins,&x,&y);
        if(ins[0]=='C') link(x,y);
        else if(ins[0]=='D') cut(x,y);
        else puts(query(x,y)? "Yes":"No");
    }
    return 0;
}
