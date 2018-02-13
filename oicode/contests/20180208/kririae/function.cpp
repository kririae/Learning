#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &val)
{
	val = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		val = val * 10 + ch - '0';
		ch = getchar();
	}
	val *= f;
}

const int maxn = 1000005;
const int mod = 1000000007;
int n, m;
int a[maxn], b[maxn], c[maxn];
int p, q, x;

inline long long bf(int p, int q, int x)
{
	if (c[p] < q)
		return (a[p] * x) + b[p];
	else
		return (a[p] * bf(c[p], q, x) + b[p]) % mod;
}
/*
...100����㹻��...
��������˼·�����鼯��ѹ��ά������
����c[p]Ϊ���鼯father[p]
�Ȱ�ѯ������һ��
��ɢ��һ�� 
�߹���·��ֱ�ӱ���һ����Ȼ���ã� 
x��ô����......................
����ʹ�ú���ʽ��̵�˼�롣�����߹���ÿһ���㽨��һ������
���ҽ�������������һ�����λ��... (�Զ�̫���� 
*/
int main()
{
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]);
		read(b[i]);
		read(c[i]);
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		read(p);
		read(q);
		read(x);
		int res = bf(p, q, x);
		ans = ans ^ res % mod;
	}
	cout << ans << endl;
}
