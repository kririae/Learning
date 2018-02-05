#include<cstdio>
int n,m,i,j,k,x,y,ans;char a[310],b[310];
int main(){
  freopen("master.in","r",stdin);freopen("master.out","w",stdout);
  scanf("%d%d%s%s",&n,&m,a+1,b+1);
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)
    for(x=i,y=j,k=0;x<=n&&y<=n;x++,y++){
      if(a[x]!=b[y]){
        k++;
        if(k>m)break;
      }
      if(ans<x-i+1)ans=x-i+1;
    }
  printf("%d",ans);
  fclose(stdin);fclose(stdout);
  return 0;
}