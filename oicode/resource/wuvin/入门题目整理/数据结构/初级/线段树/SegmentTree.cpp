#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int L=0,R=1;

struct SegmentTree{
	int l,r;//当前管理区间 [l,r] 
	long long sum;//当前区间和
	
	//记录左右儿子 
	//SegmentTree* son[2];
	//SegmentTree* lson,rson;
	int son[2];//左儿子为 son[0] 右儿子为 son[1]
	//int lson,rson;
	
}node[N*2];
int root,ini[N],cnt;//cnt 当前已经有了多少个节点 
//假设数组初始时为ini 

void buildTree(int &k,int l,int r){//初始化一个管理[l,r]的节点 ， 下标为k 
	k=++cnt;//k = cnt+1; cnt++;
	node[k].l=l;node[k].r=r;//初始化[l,r] 
	if(l==r){//没有儿子了 
		node[k].sum=ini[r];
	}else{//我是爸爸 
		int mid=( node[k].l+node[k].r )/2;//儿子的左右分界 
		buildTree(node[k].son[L],l,mid);//调用完后 左右儿子下表就可以被储存 
		buildTree(node[k].son[R],mid+1,r); 
		node[k].sum=node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum;//计算当前节点的和 
	}
}

void modify(int k,int pos,int val){//修改  把ini[pos]修改为val 
	if(node[k].l==node[k].r){//儿子！  l==r l==pos
		node[k].sum+=val;
		ini[pos]+=val;
	}else{
		int mid=( node[k].l+node[k].r )/2;//儿子的左右分界 
		if( pos<=mid ) modify(node[k].son[L],pos,val);//这个点在左儿子 
		else modify(node[k].son[R],pos,val);
		
		node[k].sum=node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum;//计算当前节点的和 
	}
}

long long query(int k,int ql,int qr){//查询[ql,qr]
	if(node[k].l==ql && node[k].r==qr){
		return node[k].sum;
	}else{
		int mid=( node[k].l+node[k].r )/2;//儿子的左右分界 
		if(qr<=mid) return query(node[k].son[L],ql,qr);//全在左儿子 
		else if(ql>=mid+1) return query(node[k].son[R],ql,qr);//全在右儿子
		else return query(node[k].son[L],ql,mid) + query(node[k].son[R],mid+1,qr);//分开了 
	}
}

int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&ini[i]);
	
	buildTree(root,1,n); 
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1) modify(root,l,r);
		else printf("%lld\n",query(root,l,r));
	}
	
	return 0;
}
