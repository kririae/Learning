#include<cstdio>
#include<iostream>
#include<cstdio>
using namespace std;
const int LEFT = 0, RIGHT = 1;
extern struct Treap* turn(int way, Treap &u, Treap &v);
struct Treap {
	Treap *son[2];//0-left 1-right
	int value;
	int priority;
	int size;//所含节点数  包括自己

	Treap()
	{
		son[0] = NULL;
		son[1] = NULL;
		value = 0;
		priority = 0;
		size = 1;
	}
	Treap(int v, int p)
	{
		son[0] = NULL;
		son[1] = NULL;
		value = v;
		priority = p;
		size = 1;
	}
	bool operator <(const Treap &b)const
	{
		return priority < b.priority;
	}

	//维护堆性质
	//返回父节点
	Treap* check(Treap* c)
	{
		int da = -1;
		int side = 0;
		if(c->son[LEFT] != NULL) {
			da = max(da, c->son[LEFT]->priority);
			side = LEFT;
		}
		if(c->son[RIGHT] != NULL) {
			if(c->son[RIGHT]->priority > da) {
				da = c->son[RIGHT]->priority;
				side = RIGHT;
			}
		}
		if(da > c->priority) {
			return turn(side, *c, *(c->son[side]));
		}
		return c;
	}

	/*
	**
	*/
	void addson(int vson, int pson)
	{
		int d = -1;
		d = (vson <= value) ? LEFT : RIGHT;
		if(son[d] == NULL) {
			son[d] = new Treap(vson, pson);
		} else {
			son[d]->addson(vson, pson);
		}
		son[d] = check(son[d]);
		return;
	}

	Treap* killpoint(Treap& c, Treap* fa)
	{
		c.priority = -1;

	}

	/*
	//返回替代c的点
	Treap* killpoint(Treap& c){
		Treap* p1;
		Treap* ret;
		if(c.son[LEFT]!=NULL){
			p1=c.son[LEFT];
			while(p1->son[RIGHT]!=NULL){
				p1=p1->son[RIGHT];
			}
			p1->son[RIGHT]=c.son[RIGHT];
			ret=c.son[LEFT];
		}else{
			ret=c.son[RIGHT];
		}
		delete &c;
		return ret;
	}*/

	int getsize()
	{
		int l, r;
		if(son[LEFT] == NULL) {
			l = 0;
		} else {
			l = son[LEFT]->getsize();
		}
		if(son[RIGHT] == NULL) {
			r = 0;
		} else {
			r = son[RIGHT]->getsize();
		}
		size = l + r + 1;
		return size;
	}

	//第x小的元素
	int findrank(int x)
	{
		if(x == son[LEFT]->size + 1) {
			return value;
		} else if(x < son[LEFT]->size) {
			return son[LEFT]->findrank(x);
		} else if(x > son[LEFT]->size) {
			x -= son[LEFT]->size + 1;
			return son[RIGHT]->findrank(x);
		}
		return -1;
	}
};

/*
//u是父节点
// 返回此处旋转后父节点
Treap* turnleft(Treap &u,Treap &v){
	u.son[RIGHT]=v.son[LEFT];
	v.son[LEFT]=&u;
	return &v;
}

//u是父节点
// 返回此处旋转后父节点
Treap* turnright(Treap &u,Treap &v){
	u.son[LEFT]=v.son[RIGHT];
	v.son[RIGHT]=&u;
	return &v;
}
*/

//u是父节点
// 返回此处旋转后父节点
Treap* turn(int way, Treap &u, Treap &v)
{
	u.son[way ^ 1] = v.son[way];
	v.son[way] = &u;
	return &v;
}

//输入n个数 每次输入 当n>=m是输出第m大的数
//10 3
//
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	Treap* tp = new Treap(100000, 100000);
	for(int i = 1; i <= n; i++) {
		int v, p;
		scanf("%d", &v);
		tp->addson(v, v);
	}
	if(n >= m) {
		tp->getsize();
		cout << tp->findrank(m);
	}
	return 0;
}
