#include<cstdio>
const int N=1300000,M=700010;
int n,m,i,x,y,cnt,g0[N],g1[N],v[M],nxt[M],ed,h,t,q[N],d[N];
void add(int*g,int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
void ext(int x,int w){
  if(d[x]>=0)return;
  d[q[++t]=x]=w;
  for(int i=g0[x];i;i=nxt[i])ext(v[i],w);
  if(x>=cnt)return;
  for(int i=0;i<20;i++)if(x>>i&1)ext(x^(1<<i),w);
}
int main(){
  freopen("walk.in","r",stdin);freopen("walk.out","w",stdout);
  scanf("%d%d",&n,&m);
  cnt=1<<20;
  for(i=1;i<=n;i++){
    scanf("%d",&x);
    add(g1,i+cnt,x);
    add(g0,x,i+cnt);
  }
  while(m--)scanf("%d%d",&x,&y),add(g1,x+cnt,y+cnt);
  for(h=i=1,t=0;i<=n+cnt;i++)d[i]=-1;
  ext(cnt+1,0);
  while(h<=t)for(i=g1[x=q[h++]];i;i=nxt[i])ext(v[i],d[x]+1);
  for(i=1;i<=n;i++)printf("%d\n",d[i+cnt]);
  fclose(stdin);fclose(stdout);
  return 0;
}