#include<cstdio>
#include<algorithm>
using namespace std;
const int N=70010,M=N*20;
int n,m,i,g[N],v[N<<1],nxt[N<<1],ed,cur,ans[N];
int size[N],f[N],d[N],son[N],top[N];
int fa[N],dep[N],A[N],B[N];
int G[262150],V[M],W[M],NXT[M],ED;
struct E{int t,x,y;E(){}E(int _t,int _x,int _y){t=_t,x=_x,y=_y;}}q[N<<2];
void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
void dfs(int x){
  size[x]=1;
  for(int i=g[x];i;i=nxt[i])if(v[i]!=f[x]){
    f[v[i]]=x,d[v[i]]=d[x]+1;
    dfs(v[i]),size[x]+=size[v[i]];
    if(size[v[i]]>size[son[x]])son[x]=v[i];
  }
}
void dfs2(int x,int y){
  top[x]=y;
  if(son[x])dfs2(son[x],y);
  for(int i=g[x];i;i=nxt[i])if(v[i]!=son[x]&&v[i]!=f[x])dfs2(v[i],v[i]);
}
int lca(int x,int y){
  for(;top[x]!=top[y];x=f[top[x]])if(d[top[x]]<d[top[y]])swap(x,y);
  return d[x]<d[y]?x:y;
}
int dis(int x,int y){return d[x]+d[y]-2*d[lca(x,y)];}
int F(int x){return fa[x]==x?x:F(fa[x]);}
void merge(int x,int y,int&ret){
  x=F(x),y=F(y);
  int u,v,t=-1,tmp;
  tmp=dis(A[x],B[x]);
  if(tmp>t)t=tmp,u=A[x],v=B[x];
  tmp=dis(A[x],A[y]);
  if(tmp>t)t=tmp,u=A[x],v=A[y];
  tmp=dis(A[x],B[y]);
  if(tmp>t)t=tmp,u=A[x],v=B[y];
  tmp=dis(B[x],A[y]);
  if(tmp>t)t=tmp,u=B[x],v=A[y];
  tmp=dis(B[x],B[y]);
  if(tmp>t)t=tmp,u=B[x],v=B[y];
  tmp=dis(A[y],B[y]);
  if(tmp>t)t=tmp,u=A[y],v=B[y];
  if(ret<t)ret=t;
  if(dep[x]==dep[y]){
    dep[x]++;
    q[++cur]=E(0,x,0);
  }
  if(dep[x]<dep[y])swap(x,y);
  q[++cur]=E(1,y,0);
  q[++cur]=E(2,x,A[x]);
  q[++cur]=E(3,x,B[x]);
  fa[y]=x,A[x]=u,B[x]=v;
}
void retrace(int t){
  while(cur>t){
    if(!q[cur].t)dep[q[cur].x]--;
    if(q[cur].t==1)fa[q[cur].x]=q[cur].x;
    if(q[cur].t==2)A[q[cur].x]=q[cur].y;
    if(q[cur].t==3)B[q[cur].x]=q[cur].y;
    cur--;
  }
}
void ins(int x,int a,int b,int c,int d,int p,int q){
  if(c<=a&&b<=d){
    V[++ED]=p;
    W[ED]=q;
    NXT[ED]=G[x];
    G[x]=ED;
    return;
  }
  int mid=(a+b)>>1;
  if(c<=mid)ins(x<<1,a,mid,c,d,p,q);
  if(d>mid)ins(x<<1|1,mid+1,b,c,d,p,q);
}
void solve(int x,int a,int b,int ret){
  int pos=cur;
  for(int i=G[x];i;i=NXT[i])merge(V[i],W[i],ret);
  if(a==b){
    ans[a]=ret;
    retrace(pos);
    return;
  }
  int mid=(a+b)>>1;
  solve(x<<1,a,mid,ret);
  solve(x<<1|1,mid+1,b,ret);
  retrace(pos);
}
int main(){
  freopen("speed.in","r",stdin);freopen("speed.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<n;i++){
    int x,y,l,r;
    scanf("%d%d%d%d",&x,&y,&l,&r);
    add(x,y),add(y,x);
    ins(1,1,n,l,r,x,y);
  }
  dfs(1);dfs2(1,1);
  for(i=1;i<=n;i++)fa[i]=A[i]=B[i]=i;
  solve(1,1,n,0);
  while(m--)scanf("%d",&i),printf("%d\n",ans[i]);
  fclose(stdin);fclose(stdout);
  return 0;
}