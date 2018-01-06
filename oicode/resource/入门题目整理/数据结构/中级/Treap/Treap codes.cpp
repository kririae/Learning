/*-------------------
codevs 1285
裸Treap
---------------------*/
#include<bits/stdc++.h>
using namespace std;
const int L = 0;
const int R = 1;
const int NO_nessary = -1;
const int Turn_Myleftson = 0;
const int Turn_Myrightson = 1;
struct Treap {
	int key;//size请全局自己手动计数
	int pri;//priority
	Treap* son[2];
	Treap() {
	}
	Treap(int keys) {
		key = keys;
		son[L] = son[R] = NULL;
	}
	void add(int x) { //插入键值为x的节点
		int side = (x < key) ? L : R;

		if(son[side] == NULL) {
			son[side] = new Treap(x);
		} else {
			son[side]->insert(x);//因为还有其他递归动作
		}
	}
	/*---------BST部分写完，堆部分开始---------*/
	void zhuan(int from, int side) { //来自son[from]告诉父节点他要旋转side方向的孙节点
		Treap* s = son[from];
		Treap* gs = s->son[side]; //grandson
		s->son[side] = gs->son[side ^ 1];
		gs->son[side ^ 1] = s;
		son[from] = gs;
	}
	int check() { //返回是否需要旋转 如果需要返回方向
		if(son[L] == son[R] == NULL) {
		} else if(son[L] == NULL) {
			if(son[R]->pri > pri) {
				return Turn_Myrightson;
			}
		} else if(son[R] == NULL) {
			if(son[L]->pri > pri) {
				return Turn_Myleftson;
			}
		} else {
			int ma = max(son[L]->pri, son[R]->pri);

			if(ma > pri) {
				if(son[L]->pri == ma) {
					return Turn_Myleftson;
				} else {
					return Turn_Myrightson;
				}
			}
		}

		return NO_nessary;
	}
	/*--------堆部分完毕------------*/
	void insert(int x) {
		add(x);

	}
};

int main() {
	return 0;
}
