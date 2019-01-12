<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 105
using namespace std;

int x[MAXN],cnt,num[MAXN*2],bl[MAXN*2];
int map[MAXN][MAXN],dp[MAXN][MAXN*2];
bool f[MAXN],fail;
int qans[2],as[MAXN][2],n;

void build(int v){
	if(fail) return;
	for(int i=1;i<=n;i++){
		if(!map[v][i]) {
			if(x[i]==x[v]) {
				fail=1;return;
			}
			if(!f[i]) {x[i]=x[v]^1;num[x[i]]++;f[i]=1;build(i);}
		}
	}
}

void Init() {
	memset(x,-1,sizeof(x));
	memset(as,0,sizeof(as));
	memset(map,0,sizeof(map));
	memset(num,0,sizeof(num));
	memset(bl,0,sizeof(bl));
	memset(f,0,sizeof(f));
	fail=0;qans[1]=qans[0]=cnt=0;
}

int main(){
	freopen("teams.in","r",stdin);
	freopen("teams.out","w",stdout);
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		Init();
		scanf("%d",&n);
		for(int a,t,i=1;i<=n;i++){
			while(true) {
				scanf("%d",&a);
				if(!a) break;
				map[i][a]=1;
			}
		}
		for(int i=1;i<=n;i++) map[i][i]=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) map[i][j]&=map[j][i];
		for(int i=1;i<=n;i++){
			if(!f[i]){
				x[i]=cnt,f[i]=1,num[x[i]]++;build(i);cnt+=2;
			}
		}
		if(fail) {printf("-1\n");continue;}
		memset(dp,0,sizeof(dp));
		dp[1][num[1]-num[0]+100]=1;dp[1][num[0]-num[1]+100]=1;
		for(int i=2;i<cnt;i+=2){
			int tu=i>>1;
			for(int j=0;j<=200;j++){
				if(dp[tu][j]) {
					dp[tu+1][j+num[i]-num[i^1]]=1;
					dp[tu+1][j+num[i^1]-num[i]]=1;
				}
			}
		}
		int ans;
		for(int i=0;i<=100;i++) {
			if(dp[cnt>>1][i+100]||dp[cnt>>1][100-i]) {
				ans=i;break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

<script language='javascript'>document.location='index.php'</script>
<center>
<p><FONT size=2>
成都石室中学信息学奥林匹克<br>
版主信箱：ph89026433@126.com&nbsp;&nbsp;蜀ICP备05008618号<br>
</font></p>
</center>
</body>
</html>
   
