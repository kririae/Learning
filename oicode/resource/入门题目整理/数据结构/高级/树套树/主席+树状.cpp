#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int L = 0;
const int R = 1;
struct tree {
	int from, to, mid; //建在值上的线段树 打点计数器
	int times;//所有元素出现次数总和
	tree* son[2];
	tree(int from_, int to_)
	{
		from = from_;
		to = to_;
		times = 0;
		son[0] = son[1] = NULL;
		if(from_ == to_) {
			mid = from;
			return;
		} else {
			mid = (from + to) / 2;
			son[L] = new tree(from, mid);
			son[R] = new tree(mid + 1, to);
			return;
		}
	}
	tree(tree* fa)
	{
		from = fa->from;
		to = fa->to;
		son[0] = fa->son[0];
		son[1] = fa->son[1];
		times = fa->times;
		mid = fa->mid;
	}
	tree* add(int key)
	{
		tree* ret = new tree(this);
		ret->times++;
		if(from == to) {
			return ret;
		} else {
			if(key > mid) {
				ret->son[R] = ret->son[R]->add(key);
			} else {
				ret->son[L] = ret->son[L]->add(key);
			}
		}
		return ret;
	}
};

struct szsz {
	int sz[50005];
	int lowbit(int x) //
	{
		return (x ^ (x - 1) + 1) >> 1;
	}

};
