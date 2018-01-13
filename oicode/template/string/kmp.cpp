#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int f[N];//fail 数组
char s[N], t[N]; //s 匹配串  t 被匹配串
int ans[N];
int main()
{
	scanf("%s%s", s + 1, t + 1); //下表从1开始储存
	int lens = strlen(s + 1), lent = strlen(t + 1);
	f[1] = 0; //第一个串显然是空

	for(int i = 2; i <= lens; i++) {
		//缩水指沿着fail链向上跳
		//即找到这个前缀的后缀中最长的原串的前缀
		int p = f[i - 1]; //先缩水一次，不然会求出自己

		while(p != 0 && //没有跳到空
		      s[p + 1] != s[i]) //没有找到正确的缩水后的串
			p = f[p]; //那就继续缩水

		if(s[p + 1] == s[i]) //匹配成功
			f[i] = p + 1; //那么缩水后为原串 s[1..p+1]
		else f[i] = 0; //不存在的

	}

	/*熟练之后一般是这么写的
	for(int i=2,p;i<=lens;i++){
		for(p=f[i-1];p!=0&&s[p+1]!=s[i];p=f[p]);
		f[i]=s[p+1]==s[i]? p+1:0;
	}
	*/

	puts("f[x]:");

	for(int i = 1; i <= lens; i++) printf("%d ", f[i]);

	puts("");

	//那么我们再来匹配一下T串

	for(int i = 1; i <= lent; i++) {
		ans[i] = ans[i - 1]; //继续上次的匹配

		if(ans[i] == lens) ans[i] = f[ans[i]]; //上次匹配成功，那显然先要缩水

		while(ans[i] != 0 && s[ans[i] + 1] != t[i]) //匹配没成功 继续缩水
			ans[i] = f[ans[i]];

		if(s[ans[i] + 1] == t[i]) ans[i] = ans[i] + 1;
		else ans[i] = 0;
	}

	puts("T[x]:");

	for(int i = 1; i <= lent; i++) printf("%d ", ans[i]);

	puts("");

	return 0;
}
