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

int n,k,a[10005],b[10005];
int cnt[10005],ans;

bool Check(int v) {
	int res=0;
	for(int i=1;i<=n;i++) 
		res+=((v/a[i]>10000)?n:cnt[v/a[i]]);
	if(res<k) return 1;
	return 0;
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		cnt[b[i]]++;
	}
	for(int i=1;i<=10000;i++) cnt[i]+=cnt[i-1];
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	k=n*n-k+1;
	int l=0,r=100000000,mid;
	while(l<=r) {
		mid=l+r>>1;
		if(Check(mid)) l=mid+1;
		else r=mid-1;
	}
	if(Check(l)) ans=l+1;
	else ans=r+1;
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
   
