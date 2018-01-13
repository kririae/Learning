#include<cstdio>
#include<iostream>
#define N 50005
using namespace std;
int n, m, cnt, root;
const int L = 0, R = 1, INF = 1000009999;
struct splay {
	struct node* null;
	struct node {
		node* son[2];
		node *fa;
		int turn, add, maxn, size, val;
		inline void update()
		{
			maxn = val;
			size = 1;
			if(son[L] != null) size += son[L]->size, maxn = max(maxn, son[L]->maxn + add);
			if(son[R] != null) size += son[R]->size, maxn = max(maxn, son[R]->maxn + add);
		}
		inline void pushdown()
		{
			if(turn != 0) {
				swap(son[L], son[R]);
				if(son[L] != null) son[L]->turn ^= 1;
				if(son[R] != null) son[R]->turn ^= 1;
			}
		}
	} node[N];
	splay()
	{
		null->size = 0;
	}
};

int main()
{

	return 0;
}
