<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

typedef long long LL;
const int Mod=1e9+7;

int Pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1)
			c=c*(LL)a%Mod;
		a=a*(LL)a%Mod;b>>=1;
	}
	return c;
}

int C(int n,int m)
{
	if(m<0||m>n)
		return 0;
	int Now=1;
	for(int i=1;i<=m;i++)
		Now=Now*(n-i+1ll)%Mod*Pow(i,Mod-2)%Mod;
	return Now;
}

int main()
{
	
	freopen("xu.in","r",stdin);
	freopen("xu.out","w",stdout);
	
	int t,p;scanf("%d%d",&t,&p);
	if(p<0)
		p=-p;
	cout<<C(2*t,t-p)*(LL)Pow(Mod+1>>1,2*t)%Mod;
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
   
