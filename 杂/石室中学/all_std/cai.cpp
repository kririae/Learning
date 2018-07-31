<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int val[10005];
int ai[10005];
int fa[10005];
int test(int k){
	memset(val,0,sizeof(val));int ret=0;
	for(int i=n;i>=1;i--){
		val[i]+=ai[i];
		if(val[i]<k){
			val[fa[i]]+=val[i];
		}else ret++;
	}
	return ret;
}
int main(){
	//freopen("cai.in","r",stdin);
	//freopen("cai.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&ai[1]);
	for(int i=2;i<=n;i++) scanf("%d%d",&fa[i],&ai[i]);
	int l=1,r=1000000000;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(test(mid)>=m){
			l=mid;
		}else r=mid;
	}
	cout<<l<<endl;
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
   
