<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include <bits/stdc++.h>
using namespace std;
const int N = 2005;

int A[N][N];
struct dl{
	int v;
	dl *d,*r;
}e[N][N];

int n,m;

void spawning(int P,int Q,int R,int S,int Mod){
	int T=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			T=(T+(1ll*(i+j)*P+1ll*i*j*Q+1ll*i*R+1ll*j*S)%Mod+Mod)%Mod;
			A[i][j]=T;
		}
	A[P%n+1][P%m+1]^=1;
	A[P%n+1][Q%m+1]^=1;
	A[P%n+1][R%m+1]^=1;
	A[P%n+1][S%m+1]^=1;
	A[Q%n+1][P%m+1]^=1;
	A[Q%n+1][Q%m+1]^=1;
	A[Q%n+1][R%m+1]^=1;
	A[Q%n+1][S%m+1]^=1;
	A[R%n+1][P%m+1]^=1;
	A[R%n+1][Q%m+1]^=1;
	A[R%n+1][R%m+1]^=1;
	A[R%n+1][S%m+1]^=1;
	A[S%n+1][P%m+1]^=1;
	A[S%n+1][Q%m+1]^=1;
	A[S%n+1][R%m+1]^=1;
	A[S%n+1][S%m+1]^=1;
}

void checker(){
	long long Pin=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			Pin+=(1ll*i*n+j)*A[i][j];
		}
	}printf("%lld\n",Pin);
}

int main(){
	freopen("havefun.in","r",stdin);
	freopen("havefun.out","w",stdout);
	int q,i,j,a,b,c,d,s,t,P,Q,R,S,Mod;
	dl *x,*y,*u,*v;
	cin>>n>>m>>q;
	scanf("%d %d %d %d %d",&P,&Q,&R,&S,&Mod);
	spawning(P,Q,R,S,Mod);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			e[i][j].v=A[i][j];
	for(i=0;i<=n;++i)
		for(j=0;j<=m;++j)
			e[i][j].d= &e[i+1][j],e[i][j].r= &e[i][j+1];
	while(q--){
		x= y= &e[0][0];
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&s,&t);
		while(--a)x= x->d;
		while(--b)x= x->r;
		while(--c)y= y->d;
		while(--d)y= y->r;
		u = x,v= y;
		for(i=0;i<s;++i)
			u= u->d,v= v->d,
				swap(u->r,v->r);
		for(i=0;i<t;++i)
			x= x->r,y= y->r,
				swap(x->d,y->d);
		for(i=0;i<t;++i)
			u= u->r,v= v->r,
				swap(v->d,u->d);
		for(i=0;i<s;++i)
			x= x->d,y= y->d,
				swap(x->r,y->r);
	}
	x= &e[0][0];x= x->d;
	for(i=0;i<n;++i){
		y= x;
		for(j=0;j<m;++j){
			y= y->r;
			A[i+1][j+1]=y->v;
		}x= x->d;
	}checker();
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
   
