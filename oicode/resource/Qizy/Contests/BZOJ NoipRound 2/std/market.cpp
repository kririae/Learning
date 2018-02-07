#include<cstdio>
#include<algorithm>
using namespace std;
const int N=305,M=100010,inf=1000000010;
int n,m,lim,i,j,f[M],ans[M];
struct P{int t,c,v;}a[N];
struct Q{int t,m,p;}b[M];
bool cmpP(const P&a,const P&b){return a.t<b.t;}
bool cmpQ(const Q&a,const Q&b){return a.t<b.t;}
void add(int c,int v){
  for(int i=lim;i>=v;i--)f[i]=min(f[i],f[i-v]+c);
  for(int i=lim-1;~i;i--)f[i]=min(f[i],f[i+1]);
}
int ask(int x){
  int l=0,r=lim,mid,t;
  while(l<=r)if(f[mid=(l+r)>>1]<=x)l=(t=mid)+1;else r=mid-1;
  return t;
}
int main(){
  freopen("market.in","r",stdin);freopen("market.out","w",stdout);
  scanf("%d%d",&n,&m);lim=n*300;
  for(i=1;i<=n;i++)scanf("%d%d%d",&a[i].c,&a[i].v,&a[i].t);
  for(i=1;i<=m;i++)scanf("%d%d",&b[i].t,&b[i].m),b[i].p=i;
  sort(a+1,a+n+1,cmpP);
  sort(b+1,b+m+1,cmpQ);
  for(i=1;i<=lim;i++)f[i]=inf;
  for(i=j=1;i<=m;i++){
    while(j<=n&&a[j].t<=b[i].t)add(a[j].c,a[j].v),j++;
    ans[b[i].p]=ask(b[i].m);
  }
  for(i=1;i<=m;i++)printf("%d\n",ans[i]);
  fclose(stdin);fclose(stdout);
  return 0;
}