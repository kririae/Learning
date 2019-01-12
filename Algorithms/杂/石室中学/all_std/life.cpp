<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int T,A[MAXN][MAXN];
int n;

int dfn[MAXN],low[MAXN],tim,ins[MAXN],scc,stk[MAXN],top;

void tarjan(int v) {
	dfn[v]=++tim;low[v]=tim;
	stk[++top]=v;ins[v]=1;
	for(int i=1;i<=n;i++) {
		if(!A[v][i]) continue;
		if(!dfn[i]) {
			tarjan(i);low[v]=min(low[v],low[i]);
		}
		else if(ins[i]) low[v]=min(low[v],dfn[i]);
	}
	if(dfn[v]==low[v]) {
		while(ins[v]) ins[stk[top--]]=0;
		scc++;
	}
}

void Init() {
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	scc=tim=0;
}

int main() {
	
	freopen("life.in","r",stdin);
	freopen("life.out","w",stdout);
	
	scanf("%d",&T);
	while(T--) {
		Init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++) 
				scanf("%d",&A[i][j]);
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i);
		if(scc==1) puts("YES");
		else puts("NO");
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
   
