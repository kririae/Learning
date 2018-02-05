#include<bits/stdc++.h>
#define LL long long
using namespace std;

inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

int main(){
	freopen("osiris.in","r",stdin);
	freopen("osiris.out","w",stdout);
	for (int T=read(),a,b,c,x,y,z,t1,t2;T;--T) {
		a = read(); b = read(); c = read();
		x = read(); y = read(); z = read();
		t1 = t2 = 0;
		if (a > x) t1 += a-x >> 1;
		if (b > y) t1 += b-y >> 1;
		if (c > z) t1 += c-z >> 1;
		if (a < x) t2 += x - a;
		if (b < y) t2 += y - b;
		if (c < z) t2 += z - c;
		printf("%s\n",t1>=t2?"YES":"NO");
	}
	return 0;
}

