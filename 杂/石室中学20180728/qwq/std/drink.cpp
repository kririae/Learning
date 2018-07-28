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
using namespace std;

int n,m,s[5005];LL sum,mi;
struct Node{
	LL l,r,in,sum;
}x[55],ans;

void Merge(int v) {
	Node ret={0,0,0,0};
	ret.l=max(ans.l,ans.sum+x[v].l);
	ret.r=max(x[v].r,x[v].sum+ans.r);
	ret.sum+=x[v].sum;
	ret.in=max(max(ans.in,x[v].in),ans.r+x[v].l);
	ans=ret;
}

int main() {
	
	freopen("drink.in","r",stdin);
	freopen("drink.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int k,i=1;i<=n;i++) {
		scanf("%d",&k);
		x[i].l=x[i].r=x[i].in=0;
		sum=mi=0;
		for(int j=1;j<=k;j++) scanf("%d",&s[j]);
		for(int j=1;j<=k;j++) {
			sum+=s[j];mi=min(mi,sum);
			x[i].l=max(x[i].l,sum);
			x[i].in=max(x[i].in,sum-mi);
		}
		x[i].sum=sum;sum=0;
		for(int j=k;j;j--) {
			sum+=s[j];
			x[i].r=max(x[i].r,sum);
		}
	}
	for(int k,i=1;i<=m;i++) {
		scanf("%d",&k);
		Merge(k);
	}
	printf("%lld\n",ans.in);
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
   
