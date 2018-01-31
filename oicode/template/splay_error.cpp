/*
splay
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>

namespace solve
{
	template<typename T>
	inline T min(T a, T b)
	{
		return a < b ? a : b;
	}

	template<typename T>
	inline T max(T a, T b)
	{
		return a < b ? b : a;
	}

	inline char read()
	{
		static const int IN_LEN = 1000000;
		static char buf[IN_LEN], *s, *t;
		s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
		return s == t ? -1 : *s++;
	}

	template <typename T>
	inline void read(T &x)
	{
		static char c;
		static bool iosig;
		for (c = read(), iosig = false; !isdigit(c); c = read()) {
			if (c == -1) return;
			c == '-' ? iosig = true : 0;
		}
		for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
		iosig ? x = -x : 0;
	}

	const int maxn = 1e5 + 5;
	const int nil = 0;
	int cnt = 0;
	int root = 0;

	struct node {
		int father;
		int val;
		int son[2];
		int size;

		node(): val(0), father(nil), size(1) {
			son[0] = nil, 
			son[1] = nil;
		}
	};
	node t[maxn];

	inline void pushup(int k) {
		t[k].size = t[t[k].son[0]].size + t[t[k].son[1]].size + 1;
	}

    inline void bt_modify(int k) {
        for (int i = t[k].father; i != 0; i = t[i].father) ++t[i].size;
    }
    
	inline void insert(int k, int val) {
		// splay
		if(root == 0) {
			t[++cnt].val = val;
			t[cnt].father = nil;
			root = cnt;
			return;
		}
		for (;;) {
			int side = (t[k].val <= val);
			if(t[k].son[side] == nil) {
				t[++cnt].val = val;
				t[cnt].father = k;
				t[k].son[side] = cnt;
				bt_modify(cnt);
				break;
			}
			else 
				k = t[k].son[side];
		}
	}

	inline void print(int k) {
        if (t[k].son[0]) print(t[k].son[0]);
        std::printf("t[i].val:%3d, father:%3d, size:%3d\n", t[k].val, t[t[k].father].val, t[k].size);
        // std::cout << t[i].val << " " << t[t[i].father].val <<" "<< t[i].size <<endl;
        if (t[k].son[1]) print(t[k].son[1]);
    }
    
    inline int get_side(int k) {
        // for index k, get its side in its father
        // no spec for root
        return (t[t[k].father].son[1] == k);
    }
    
    inline void rotate(int k, int side) {
    	side = get_side(k);

    	int fa = t[k].father, grand = t[fa].father;
    	t[fa].son[side] = t[k].son[side ^ 1];
    	t[t[k].son[side ^ 1]].father = fa;
    	t[fa].father = k;
    	t[k].son[side ^ 1] = fa;

    	pushup(fa), pushup(k);

    	if(grand) {
    		t[grand].son[get_side(fa)] = k;
    		t[k].father = grand;

    		pushup(grand);
    	}
    }

}

int n, m;
int main() {
	using namespace solve;
    using namespace std;
	read(n);
	for (int val, i = 0; i < n; ++i) {
		read(val);
		insert(root, val);
	}
    	    
	print(root);
}