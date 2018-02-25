#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int L=0,R=1;

struct SegmentTree{
	int l,r;//当前管理区间 [l,r] 
	//long long sum;//当前区间和
	long long add;//当前区间每个数加了多少 
	//记录左右儿子 
	//SegmentTree* son[2];
	//SegmentTree* lson,rson;
	int son[2];//左儿子为 son[0] 右儿子为 son[1]
	//int lson,rson;
	
}node[N*2];
int root,ini[N],cnt;//cnt 当前已经有了多少个节点 
//假设数组初始时为ini 

void pushdown(int k){//把节点K上的数值下传 
	if(node[k].add==0 || node[k].l==node[k].r ) return;//没有需要下传的 或者 没有儿子 
}

void buildTree(int &k,int l,int r){//初始化一个管理[l,r]的节点 ， 下标为k 
	k=++cnt;//k = cnt+1; cnt++;
	node[k].l=l;node[k].r=r;//初始化[l,r] 
	if(l==r){//没有儿子了 
		//do nothing
	}else{//我是爸爸 
		int mid=( node[k].l+node[k].r )/2;//儿子的左右分界 
		buildTree(node[k].son[L],l,mid);//调用完后 左右儿子下表就可以被储存 
		buildTree(node[k].son[R],mid+1,r); 
		//node[k].sum=node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum;//计算当前节点的和 
	}
}

void modify(int k,int ql,int qr,int val){//[ql,qr] += val
	pushdown(k);
	if( node[k].l==ql && node[k].r==qr ){
		node[k].add+=val;//打标记 
	}else{
		//pushdown
		int mid=( node[k].l+node[k].r )/2;//儿子的左右分界 
		if(qr<=mid) modify(node[k].son[L],ql,qr,val);
		else if( mid<ql ) modify(node[k].son[R],ql,qr,val);
		else modify(node[k].son[L],ql,mid,val) , modify(node[k].son[R],mid+1,qr,val);
	}
}

long long query(int k,int pos,int val){
	pushdown(k);
	if( node[k].l==node[k].r ){// l==r==pos
		return node[k].add+ini[pos];
	}else{
		int mid=( node[k].l+node[k].r )/2;//儿子的左右分界 
		if( pos<=mid ) return query(node[k].son[L],pos,val);
		else return query(node[k].son[R],pos,val);
	}
} 

int n,m;
int main(){
	
	return 0;
}
