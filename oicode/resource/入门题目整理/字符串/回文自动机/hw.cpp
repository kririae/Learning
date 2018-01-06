/*
回文自动机学习笔记
paper:http://pan.baidu.com/s/1hqzRlvm
code :http://pan.baidu.com/s/1pJHnT0Z
回文自动机每个节点保存的是一个回文串
这个回文串的fail边指向这个回文串中右侧开始的第二长（最长是自己） 的
回文串。然后增量构造即可。复杂度O(n)证明可以类似AC自动机
至于不同回文串只有n个的证明，请采用manacher证明。如果不懂到uoj上去问
由于只有一个原串所以没有保存回文串的必要，只需要保留长度和中点
由于层数没有保障，只好非递归

可以考虑像manacher一样处理后，只保留奇数回文串
*/
//bzoj 3676
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 300008
using namespace std;
char s[N];
int n, cnt;
struct node {
	int len;//只记录长度，具体是什么取决于到根的路径
	int times;
	int fst;//压位  快速DFS
	int ne[28];
	int fail;
} node[N];
void build() {
	int p = 2; //pointer
	cnt = 2;

	for(int i = 1; i <= n; i++) s[i] -= 'a' - 1;

	node[1].fail = 1;
	node[1].len = -1;
	node[2].fail = 1;
	node[2].len = 0;

	for(int i = 1; i <= n; i++) {
		while(s[i] != s[i - node[p].len - 1]) p = node[p].fail;

		if(node[p].ne[s[i]] != 0) {
			node[node[p].ne[s[i]]].times++;    //该节点已存在
			p = node[p].ne[s[i]];
			continue;
		}

		int k = node[p].ne[s[i]] = ++cnt;
		node[k].len = node[p].len + 2;
		node[k].times = 1;

		if(p == 1) {
			node[k].fail = 2;
			p = k;
			continue;
		}

		p = node[p].fail;

		while(p != 1 && s[i] != s[i - node[p].len - 1]) p = node[p].fail;

		node[k].fail = node[p].ne[s[i]];
		p = k;
	}
}
void count() {
	long long ans = 0;

	for(int i = cnt; i > 2; i--) {
		ans = max(ans, node[i].len * (long long)node[i].times);
		node[node[i].fail].times += node[i].times;
	}

	printf("%lld\n", ans);
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	build();
	count();
	return 0;
}
