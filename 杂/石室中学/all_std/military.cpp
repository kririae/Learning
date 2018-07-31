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
#define MOD 998244353
using namespace std;
int _ret,_f;char _c; 
inline int read() {
	_ret=0,_f=1;_c=getchar();
	while(_c>'9'||_c<'0') {if(_c=='-') _f=-1;_c=getchar();}
	while(_c<='9'&&_c>='0') {_ret=_ret*10+_c-'0';_c=getchar();}
	return _ret*_f;
}

#define MAXN 1000005
#define MAXM 100005

int n,tot,m[MAXM],c[MAXM],ans;
struct stu{
	int h,bl;
	bool operator < (const stu &b) const {
		return h<b.h;
	}
	bool operator > (const stu &b) const {
		return h>b.h;
	}
}p[MAXN];
priority_queue<stu ,vector<stu> ,greater<stu> > q;
int st[MAXN],ed[MAXN],l[MAXN],r[MAXN],mv,mx;

int main() {
	
	freopen("military.in","r",stdin);
	freopen("military.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;i++) {
		m[i]=read();c[i]=read();
		st[i]=tot+1;ed[i]=tot+m[i];
		l[i]=tot+1;r[i]=tot;
		for(int j=1;j<=m[i];j++) {
			p[++tot].h=read();
			p[tot].bl=i;
		}
	}
	for(int i=1;i<=n;i++) sort(p+st[i],p+ed[i]+1);
	for(int i=1;i<=n;i++) {
		r[i]+=c[i];q.push(p[l[i]]);
		mx=max(mx,p[r[i]].h);
	}
	ans=mx-q.top().h;
	while(1) {
		mv=q.top().bl;q.pop();
		if(r[mv]==ed[mv]) break;
		q.push(p[++l[mv]]);
		mx=max(mx,p[++r[mv]].h);
		ans=min(ans,mx-q.top().h);
	}
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
   
