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

const int M = 200+9;
const int N = 200000+9;
const int Q = 200;
const int SEED = 233;
const int MOD = 9999971;

int n,top,bot;
bitset<M> BIN[M];
struct Data{
	int dec,len;
	bitset<M> bin;
}que[N];

inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

inline void Add_BIN(bitset<M> &A, bitset<M> B) {
	static short tmp[M];
	memset(tmp,0,sizeof(tmp));
	for (int i=1;i<Q;i++) {
		tmp[i] += (short)A[i] + B[i];
		tmp[i+1] += tmp[i] / 2;
		tmp[i] &= 1;
	}
	for (int i=1;i<Q;i++) A[i] = tmp[i];
}

inline int Get_Hash(bitset<M> &A, const int len) {
	int ret = 0; 
	for (int i=1;i<=len;i++) 
		ret = (LL)(ret + A[i]) * SEED % MOD;
	return ret;
}

inline bool Extend(Data w, bool v) {
	if (w.len++, v) Add_BIN(w.bin, BIN[w.len]);
	w.dec = (LL)(w.dec+v)*SEED % MOD;
		
	if (w.dec != Get_Hash(w.bin, w.len)) return 0;
	else return que[++top] = w, 1;
}

int main() {
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	n = read() - 1;
	
	BIN[1][1] = 1;
	for (int i=2;i<Q;i++) {
		BIN[i] = BIN[i-1]<<1;
		Add_BIN(BIN[i], BIN[i-1]<<3);
	}
	
	que[1].len = que[2].len = 1;
	que[2].dec = SEED;
	que[2].bin[1] = 1;
	bot = 1; top = 2; 
	
	for (int tmp=top;n;bot=tmp+1,tmp=top) {
		for (int i=bot;i<=tmp && n;i++) 
			Extend(que[i],0);
		for (int i=bot;i<=tmp && n;i++) 
			if (Extend(que[i],1)) n--;
	} 
	for (int i=que[top].len;i;i--) 
		putchar(que[top].bin[i]?'1':'0');
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
   
