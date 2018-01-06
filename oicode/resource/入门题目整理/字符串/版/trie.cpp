#include<cstdio>
#include<cstring>
#include<vector>
/*
用trie做相同的后三位，我也是—醉--利~奥~~
*/
using namespace std;
struct node {
	int val;
	int way[28];//小写 x-'a'
	node(int v): val(v) { //是否为单词节点
		memset(way, 0, sizeof(way));
	}
	void add(char c, int to) {
		way[c - 'a'] = to;
	}
};
struct trie_tree {
	int root;
	int size;
	vector<node> x;
	trie_tree() {
		root = 0;
		size = 1;
		x.clear();
		x.push_back(node(0));
	}
	void addword(char* s, int key) { //key != 0
		int len = strlen(s);
		int p = root;

		for(int i = 0; i < len; i++) {
			int d = s[i] - 'a';
			int weihu = x[p].way[d];

			if(x[p].way[d]) {
				p = x[p].way[d];
			} else {
				x.push_back(node(0));
				x[p].way[d] = size;
				p = size;
				size++;
			}

			if(i == len - 1) {
				x[size - 1].val = key;
			}
		}
	}
	int find(char *s) {
		int len = strlen(s);
		int p = root;

		for(int i = 0; i < len; i++) {
			int d = s[i] - 'a';

			if(x[p].way[d]) {
				p = x[p].way[d];
			} else {
				return -1;
			}

			if(i == len - 1) {
				if(x[p].val) {
					return x[p].val;
				}
			}
		}

		return -1;
	}
};
int main() {
	int p;
	trie_tree tt;
	scanf("%d", &p);

	for(int r = 1, i = 1;; i++) {
		r *= p;
		r %= 1000;
		char k[3];
		k[0] = r / 100 + 'a';
		k[1] = (r % 100) / 10 + 'a';
		k[2] = (r % 10) + 'a';
		int val = tt.find(k);

		if(val == -1) {
			tt.addword(k, i);
		} else {
			printf("%d %d", i, val);
			return 0;
		}
	}

	return 0;
}
