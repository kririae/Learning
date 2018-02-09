#include<cstdio>
const int N=1510;
int cnt[65536],m,n,i,j,d[N];char g[N][N];long long ans;
int popcount(unsigned int x){return cnt[x>>16]+cnt[x&65535];}
struct BIT{
  unsigned int v[47];
  void set(int x){v[x>>5]|=1U<<(x&31);}
  void count(const BIT&b){for(int i=0;i<=m;i++)ans-=popcount(v[i]&b.v[i]);}
}f[N];
int main(){
  freopen("tour.in","r",stdin);freopen("tour.out","w",stdout);
  for(i=1;i<65536;i++)cnt[i]=cnt[i>>1]+(i&1);
  scanf("%d",&n);m=(n-1)>>5;
  for(i=0;i<n;i++){
    scanf("%s",g[i]);
    for(j=0;j<n;j++)if(g[i][j]=='1')f[i].set(j),d[i]++;
  }
  for(i=0;i<n;i++)for(j=0;j<i;j++)if(g[i][j]=='1')ans+=(d[i]-1)*(d[j]-1),f[i].count(f[j]);
  printf("%I64d",ans*2);
  fclose(stdin);fclose(stdout);
  return 0;
}