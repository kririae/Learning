#include<cstdio>
#include<algorithm>
const int N=205;
int n,m,i,a[N],cnt,b[1000000],f[N];
void add(int n){for(int i=1;i<=n/i;i++)if(n%i==0)b[++cnt]=i,b[++cnt]=n/i;}
int cal(int d){
  int t=0;
  for(int i=1;i<=m;i++)if(a[i]%d==0)t++;
  return t;
}
int main(){
  freopen("div.in","r",stdin);freopen("div.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++)scanf("%d",&a[i]),add(a[i]);
  std::sort(b+1,b+cnt+1);
  for(i=1;i<=cnt;i++)if(b[i]<=n&&b[i]!=b[i-1])f[cal(b[i])]++;
  f[0]=n;
  for(i=1;i<=m;i++)f[0]-=f[i];
  for(i=0;i<=m;i++)printf("%d\n",f[i]);
  fclose(stdin);fclose(stdout);
  return 0;
}