#define Mid ((L+R)>>1)

struct node *null;
struct node{
	node *L,*R;
	int sum;
} Nd[Top],*cur=Nd+1;
int Qx;

node *New(node *L,node *R,int sum){
	return *cur=(node){L,R,sum},cur++;
}
node *Modify(node *x,int L,int R){
	if (L==R) return New(0x0,0x0,x->sum+1);
	if (Qx<=Mid){
		return New(Modify(x->L,L,Mid),x->R,x->sum+1);
	} else{
		return New(x->L,Modify(x->R,Mid+1,R),x->sum+1);
	}
}
