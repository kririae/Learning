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

int n,a,last;
long long ans;

int main() {
	
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	
	scanf("%d",&n);
	scanf("%d",&last);
	for(int i=1;i<n;i++) {
		scanf("%d",&a);
		ans+=max(a,last);
		last=a;
	}
	printf("%lld\n",ans);
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
   
