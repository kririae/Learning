/*
启发式并查集ver
因为开始的带权路径压缩怎么都调不出来
于是就启发式了
比较板子的一个带权并查集，但是带权并查集的调试难度都不是很低
这样，get(a)表示a到a的根节点的距离。d[a]表示a到fa[a]的距离。
然后get(r) - get(l)就表示，按照目前的限制来看，r_i和l_i的距离是多少
如果不满足的话，直接gg
但是满足的话，继续。
继续之后存在一个合并的问题。
假如说我们把b设置为a的父亲，和a设置为b的父亲有点不同...
因为fa总比x大...换方向的话要考虑到这个
当然这是启发式并查集的锅
因为人家好写嘛QwQ
啊啊啊这段好乱，等我理一理QAQ
因为需要维护l, r的距离
我们用l -> a的距离，就是a - l，减去r -> b的距离。
这样，这个差值，加上d，就是l -> r的距离啦！
 */
#define ll long long
#define R register
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e5 + 5;
int n, m, l, r, dis, fa[maxn], d[maxn], h[maxn];
 
inline int get(int x, int ans = 0)
{
	if(x == fa[x]) return d[x];
	return d[x] + get(fa[x]);
}
 
inline int find(int x)
{
	if(x == fa[x]) return x;
	 return find(fa[x]);
}
 
int main()
{
	for (R int i = 0; i < maxn; ++i) fa[i] = i, h[i] = 1;
	scanf("%d%d", &n, &m);
	for (R int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &l, &r, &dis);
		int a = find(l), b = find(r);
		if(a != b) 
		{
			if(h[a] > h[b]) fa[b] = a, d[b] = get(l) - get(r) + dis;
			else if(h[a] < h[b]) fa[a] = b, d[a] = get(r) - get(l) - dis;
			else fa[a] = b, d[a] = get(r) - get(l) - dis, ++h[b];
		}
		else if(get(r) - get(l) != dis) 
				return puts("No"), 0;
	}
	return puts("Yes"), 0;
}