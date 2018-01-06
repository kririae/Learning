#include<bits/stdc++.h>
using namespace std;
/*---------------------------
该数据结构需要支持的操作
加入键值为K的节点
查询第K大的节点
删除键值比K小的节点
好吧，我现在不想做

所以我们来谈一下treap到底是什么
众所周知，BST(排序二叉树)在怀有深深的恶意的
出题者面前是个大坑
20个数据至少五个数据会建成链
所以要发挥一下随机化的威力
当然我们要给自己的树随机建立的可能
所以宁可麻烦也不被坑
so，我们来建立一棵有堆性质的BST
作为BST发挥该有的查找作用
作为堆来随机确定形状以保证不成链
用左旋右旋来维护堆性质

再说一下splay（伸展树）
1、他是一棵BST
2、他也有堆性质
3、同时可以把某点旋转到根，然后可以分裂和合并//两树之间有严格的大于小于关系O（1）
											//否则size小的树依次插入大树O（nlogn)
4、当然根据“八二”原则，把需要的转到根还是有用的
-----------------------------*/
const int L = 0;
const int R = 1;
struct Treap {
	//根据key1来确定BST
	//根据key2来确定堆性质
	int gz;//工资即排序 关键字key1
	int size;//含有子节点数量 包括自己
	Treap* son[2];
	Treap(int k) {
		gz = k;
		son[L] = son[R] = NULL;
	}
	int sum() { //初始化size
		if(son[L] == NULL) {
			if(son[R] == NULL) {
				size = 1;
			} else {
				size = 1 + son[R]->sum();
			}
		} else {
			if(son[R] == NULL) {
				size = 1 + son[L]->sum();
			} else {
				size = 1 + son[L]->sum() + son[R]->sum();
			}
		}

		return size;
	}

	void check(Treap* &tothis) { //检查当前节点是否符合堆性质否则旋转
	}

	int add(int k) { //左小右大  //(此题不用)当然还要维护堆性质
		int si = k < gz ? L : R;

		if(son[si] != NULL) {
			son[si]->add(k);
		} else {
			son[si] = new Treap(k);
		}
	}
	//旋转当前节点到子树  side=L 旋转后为左子树
	void Turn(int side, Treap* &tothis) {
		Treap* k = tothis->son[side ^ 1];
		tothis->son[side ^ 1] = k->son[side];
		k->son[side] = tothis;
		tothis = k;
	}
};


int main() {

	return 0;
}
