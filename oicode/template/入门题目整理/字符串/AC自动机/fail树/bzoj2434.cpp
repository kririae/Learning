/*
正解什么的看不懂怎么办呀。。。
搬运：首先有一个朴素算法就是找到第y个单词在trie树上的路径
然后沿着每一个点的fail指针走，如果找到x就加1（想想fail指针建立的过程）。
由此可以运用逆向思维，以x为根的子树沿着fail指针倒着走能找到多少个y路径上的点
就说明x在y上出现过几次。每次都dfs找一遍，这样可以得到70分。
可以提前dfs出整个fail树上每个节点最先到达的时间和最后到达时间，
因为是dfs所以开始时间——结束时间内都是在同一颗子树上，可以用树状数组去维护，AC。
还有一些细节，在建图时一边读入一遍就建立tire（AC自动机），遇到P就标记，遇到B就回退一步
（到当前节点的父亲节点），遇到小写字母就建立tire树。同时这是一个离线算法，
将询问做成一个边表就可以一次处理多个，处理时遇到P就在x开始时间——x结束时间内求有多少个点，
遇到B就退回父亲并在当前节点的开始时间处开始删除1，遇到小写字母就在当前节点开始时间处加1。
因为如果每次没有B，那比x先插入的点一定不会到x的子树中（len（后面的串）〉=len（前面））
，如果有B子树中比x考前的点也已通过删除删掉了，所以x开始时间——x结束时间求和就是答案。

其实我只看懂了正解中“x为根的子树沿着fail指针倒着走能找到多少个y路径上的点”这一部分
fail树上的DFS好像也可以，不就是查询y路径上的点有几个的DFS序在start[x]-end[x]中嘛
正解看不懂我们有主席树嘛
在trie上建个主席树咋的
不就是查询路径上有几个点的start[x]<=start[i]<=end[x]
主席树裸题
*/
#include<cstdio>
#include<queue>
#include<iostream>
#define N 100005
using namespace std;
int n,m,ac_root;
//------------------
struct AC{
    int fail,fa;
    int ne[27];
    int intime,outtime;
    int root;
}ac[N];
int ac_cnt;
int name2ac[N];
void getfail(){
    queue<int> q;
    ac[ac_root].fail=0;
    for(int i=1;i<=26;i++){
        if(ac[ac_root].ne[i]!=0) ac[ac[ac_root].ne[i]].fail=ac_root,q.push(ac[ac_root].ne[i]);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=1;i<=26;i++){
            if(ac[u].ne[i]!=0){
                int p=ac[u].fail;
                while(p!=0&&ac[p].ne[i]==0) p=ac[p].fail;
                if(p==0) ac[ac[u].ne[i]].fail=ac_root;
                else ac[ac[u].ne[i]].fail=ac[p].ne[i];
                q.push(ac[u].ne[i]);
            }
        }
    }
}
//------------------
vector<int> fail_tree[N];
int mtimer;
void buildfail(){
    for(int i=1;i<=ac_cnt;i++){
        fail_tree[ac[i].fail].push_back(i);
    }
}
void DFS(int u){
    ac[u].intime=++mtimer;
    for(int i=0,len=fail_tree[u].size();i<len;i++){
        DFS(fail_tree[u][i]);
    }
    ac[u].outtime=++mtimer;
}
//------------------
struct xds{
    int son[2],size;
}chair[N*20];
int xds_cnt;
const int L=0,R=1;
void insert(int &k,int l,int r,int v){
    int t=++xds_cnt;chair[t].son[L]=chair[k].son[L];chair[t].son[R]=chair[k].son[R];chair[t].size=chair[k].size+1;k=t;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(mid<v) insert(chair[t].son[R],mid+1,r,v);
    else insert(chair[t].son[L],l,mid,v);
}
int query(int k,int l,int r,int low,int hi){//[low,hi]
    if(l==low&&r==hi){
        return chair[k].size;
    }
    int mid=(l+r)>>1;
    if(mid<low) return query(chair[k].son[R],mid+1,r,low,hi);
    else if(hi<=mid) return query(chair[k].son[L],l,mid,low,hi);
    else return query(chair[k].son[L],l,mid,low,mid)+query(chair[k].son[R],mid+1,r,mid+1,hi);
}
void buildchartree(int u,int ch_root){
    ac[u].root=ch_root;
    insert(ac[u].root,1,N<<1,ac[u].intime);
    for(int i=1;i<=26;i++){
        if(ac[u].ne[i]!=0) buildchartree(ac[u].ne[i],ac[u].root);
    }
}
//----------------------
void init(){
    char c;bool fl=true;int p=1;ac_cnt=ac_root=1;
    ac[p].fa=p;int namecnt=0;
    while(fl){
        c=getchar();
        if(c<='z'&&c>='a'){
            ac[p].ne[c-'a'+1]=++ac_cnt;
            ac[ac_cnt].fa=p;p=ac_cnt;
        }else if(c=='P'){
            name2ac[++namecnt]=p;
        }else if(c=='B'){
            p=ac[p].fa;
        }else{
            fl=false;
        }
    }
}
//--------------------
void asks(){
    int x,y;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        x=name2ac[x];y=name2ac[y];
        int ret=query(ac[y].root,1,N<<1,ac[x].intime,ac[x].outtime);
        printf("%d\n",ret);
    }
}
//------------------
int main(){
    init();
    getfail();
    buildfail();
    DFS(ac_root);
    buildchartree(ac_root,0);
    asks();
    return 0;
}
