<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;

LL inv[3000006],ctn[3000006];
int n;

void GetInv() {
	inv[1]=1;
	for(int a,b,i=2;i<=n;i++) {
		a=MOD/i;b=MOD%i;
		inv[i]=(MOD-a)*inv[b]%MOD;
	}
}

void GetCtn() {
	ctn[1]=1;
	for(int i=2;i<n;i++) 
		ctn[i]=ctn[i-1]*(4*i-2)%MOD*inv[i+1]%MOD;
}

int main () {
	
	freopen("school.in","r",stdin);
	freopen("school.out","w",stdout);
	
	scanf("%d",&n);
	GetInv();
	GetCtn();
	printf("%lld\n",ctn[n-1]);
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
   
