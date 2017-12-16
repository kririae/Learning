/*建议上codevs交
此题卡精度TAT
eps 1e-8 90
eps 1e-10 70*/
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#define eps 1e-7
#define DB long double
using namespace std;
vector<int> node[505];
void addedge(int f,int t){
    node[f].push_back(t);
}
DB ma[505][505];//解期望经过次数 
int n,m;
void gauss(){
    int now=0;
    for(int i=1;i<=n;i++){
        for(now=i;ma[now][i]<eps&&ma[now][i]>-eps;now++);
        if(now!=i)for(int j=0;j<=n;j++) swap(ma[now][j],ma[i][j]);
        DB p=ma[now][i];for(int j=0;j<=n;j++) ma[now][j]/=p;
        for(int j=1;j<=n;j++){
            if(j==now||(ma[j][i]<eps&&ma[j][i]>-eps))continue;p=ma[j][i];
            for(int k=0;k<=n;k++) ma[j][k]-=p*ma[now][k];
        }
    }
}
int fr[250005],to[250005];DB px[250005],psb[250005];
int main(){
    cin>>n>>m;
    for(int i=1,f,t;i<=m;i++){
		scanf("%d%d",&fr[i],&to[i]);
		if(fr[i]!=n) addedge(fr[i],to[i]);
		if(to[i]!=n) addedge(to[i],fr[i]);
	}
    for(int i=1;i<n;i++){
        ma[i][i]=-1;
        for(int j=node[i].size()-1,t=j+1;j>=0;j--){
            ma[node[i][j]][i]=1.0/t;
        }
        psb[i]=1.0/node[i].size();
    }
    ma[n][n]=-1;ma[n][0]=1;ma[1][0]=1;
    gauss();
    for(int i=1;i<=m;i++) px[i]=-(ma[fr[i]][0]*psb[fr[i]]+ma[to[i]][0]*psb[to[i]]);
    sort(px+1,px+m+1);
    double ans=0;
    for(int i=1;i<=m;i++) ans+=px[i]*(m-i+1);
    printf("%.3lf",ans);
    return 0;
}
