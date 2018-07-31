<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<bits/stdc++.h>
#define LL long long
#define Pa pair<int,int>
using namespace std;

#define MOD 1000000007
#define MAXN 8005

int n,x[MAXN],now,ans,lim;
char s[MAXN];

int comp(int v) {
	if(s[v]=='X') return 1;
	int l,r;
	l=comp(++now);r=comp(++now);
	if(s[v]=='A') return l+r;
	return max(l,r);
}

int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%s",s+1);scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	lim=comp(++now);
	for(int i=0;i<lim;i++) ans+=x[n-i];
	cout<<ans<<endl;
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
   
