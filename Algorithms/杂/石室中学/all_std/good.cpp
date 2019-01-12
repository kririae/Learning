<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<iostream>
#include<stdio.h>
using namespace std;

const int N=100010;
const int M=1000000;
int n,m,a[N];
bool re[M+1];
int prime[M],cnt=0;
struct node
{
	int x,y;
	int l,r;
	int sum,maxs;
}g[N*2];
int tot=0;

void init()
{
	int i,j;
	for (i=2;i<=M;i++)
	{
		if (!re[i])prime[++cnt]=i;
		for (j=1;j<=cnt&&prime[j]*i<=M;j++)
		{
			re[prime[j]*i]=true;
			if (i%prime[j]==0)break;
		}
	}
	re[0]=re[1]=re[6]=false;
	for (i=4;i<=M;i<<=1)re[i]=false;
}

void cal(int ro)
{
	g[ro].sum=g[g[ro].l].sum+g[g[ro].r].sum;
	g[ro].maxs=max(g[g[ro].l].maxs,g[g[ro].r].maxs);
}

void build(int x,int y)
{
	int ro=++tot;
	g[ro].x=x;g[ro].y=y;
	if (x==y)
	{
		g[ro].sum=!re[a[x]];g[ro].maxs=a[x];
		return;
	}
	g[ro].l=tot+1;build(x,(x+y)/2);
	g[ro].r=tot+1;build((x+y)/2+1,y);
	cal(ro);
}

void in_change(int ro,int c,int x)
{
	if (g[ro].x==g[ro].y)
	{
		g[ro].sum=!re[x];
		g[ro].maxs=x;
		return;
	}
	if (c<=(g[ro].x+g[ro].y)/2)in_change(g[ro].l,c,x);
	else in_change(g[ro].r,c,x);
	cal(ro);
}

void in_mod(int ro,int l,int r,int s)
{
	if (g[ro].maxs<s)return;
	if (g[ro].x==g[ro].y)
	{
		g[ro].maxs%=s;
		g[ro].sum=!re[g[ro].maxs];
		return;
	}
	int mid=(g[ro].x+g[ro].y)/2;
	if (l<=mid)in_mod(g[ro].l,l,r,s);
	if (r>mid)in_mod(g[ro].r,l,r,s);
	cal(ro);
}

int out(int ro,int l,int r)
{
	if (l<=g[ro].x&&g[ro].y<=r)return g[ro].sum;
	int mid=(g[ro].x+g[ro].y)/2,s=0;
	if (l<=mid)s+=out(g[ro].l,l,r);
	if (r>mid)s+=out(g[ro].r,l,r);
	return s;
}

int main()
{
	freopen("good.in","r",stdin);
	freopen("good.out","w",stdout);
	scanf("%d%d",&n,&m);
	init();
	int i,p,l,r,s,c,x;
	for (i=1;i<=n;i++)scanf("%d",a+i);
	build(1,n);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&p);
		if (p==1)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",out(1,l,r));
		}
		else
			if (p==2)
			{
				scanf("%d%d%d",&l,&r,&s);
				in_mod(1,l,r,s);
			}
			else
			{
				scanf("%d%d",&c,&x);
				in_change(1,c,x);
			}
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
   
