#include<cstdio>

/*
***ËÄ´¨2010Ê¡Ñ¡  ĞòÁĞ²Ù×÷
0 a b °Ñ[a, b]Çø¼äÄÚµÄËùÓĞÊıÈ«±ä³É0
1 a b °Ñ[a, b]Çø¼äÄÚµÄËùÓĞÊıÈ«±ä³É1
2 a b °Ñ[a,b]Çø¼äÄÚµÄËùÓĞÊıÈ«²¿È¡·´£¬Ò²¾ÍÊÇËµ°ÑËùÓĞµÄ0±ä³É1£¬°ÑËùÓĞµÄ1±ä³É0
3 a b Ñ¯ÎÊ[a, b]Çø¼äÄÚ×Ü¹²ÓĞ¶àÉÙ¸ö1
4 a b Ñ¯ÎÊ[a, b]Çø¼äÄÚ×î¶àÓĞ¶àÉÙ¸öÁ¬ĞøµÄ1
*/
using namespace std;
struct node {
	int left, right, mid; //Çø¼ä (left,mid)  (mid+1,right)
	int index;//ĞòºÅ  ×ó¶ù×Óindex*2 ÓÒ¶ù×Óindex*2+1
	int cz[3];//ËÄÖÖ²Ù×÷ 1 2 3   1Òª²Ù×÷ ×î¶àÓĞÒ»¸öÊÇ1 0-not nessary
	void addcz(int *t) {} //²Ù×÷µş¼

	if(t[0] == 1) { //¹éÁã
		cz[1] = 0;
		cz[0] = 1;
		cz[2] = 0;
	} else if(t[1] == 1) { //¹éÒ»
		cz[0] = 0;
		cz[1] = 1;
		cz[2] = 0;
	} else if(t[2] == 1) { //È¡·´
		if(cz[0] == 1) {
			cz[0] = 0;
			cz[1] = 1;
			cz[2] = 0;
		} else if(cz[1] == 1) {
			cz[0] = 1;
			cz[1] = 0;
			cz[2] = 0;
		} else if(cz[2] == 1) {
			cz[0] = 0;
			cz[1] = 0;
			cz[2] = 0;
		} else {
			cz[0] = 0;
			cz[1] = 0;
			cz[2] = 1;
		}
	}

	return;
}
int yi, ling; //1ºÍ0µÄ¸öÊı
int l1, r1, l0, r0; //×î×ó×îÓÒÁ¬ĞøµÄ0 1
int long1, long0; //ÖĞ¼ä×î³¤0 1
int qing;//ÇåÒ»É« 0¡¾=10¡¿ »¹ÊÇ 1¡¾=11¡¿
void doit() {} //½øĞĞ²Ù×÷

if(cz[0]) {
	l0 = r0 = right - left + 1;
	l1 = r1 = 0;
	long1 = 0;
	long0 = l0;
	yi = 0;
	ling = l0;
} else if(cz[1]) {
	l1 = r1 = right - left + 1;
	l0 = r0 = 0;
	long1 = l1;
	long0 = 0;
	yi = long1;
	ling = 0;
} else if(cz[2]) {
	swap(l0, l1);
	swap(r0, r1);
	swap(long0, long1);
	swap(yi, ling);
}

int len = right - left + 1;

if((l0 == len) || (r0 == len)) {
	qing = 10;
} else if((l1 == len) || (r1 == len)) {
	qing = 11;
} else {
	qing = 0;
}

return 0;
}
void fresh(const node& lson, const node& rson) { //¸ù¾İ×Ó½ÚµãË¢ĞÂ
	if(left == right) {
		return;
	}

	yi = lson.yi + rson.yi;
	ling = lson.ling + rson.ling;

	if(lson.qing == 11) { //×ó²àÈ«1
		l1 = lson.l1 + rson.l1;
		l0 = 0;

		if(rson.qing == 11) {
			r1 = l1;
			r0 = 0;
			long1 = l1;
			long0 = 0;
			qing = 11;
		} else {
			r1 = rson.r1;
			r0 = rson.r0;
			long1 = rson.l1 + lson.l1;
			long0 = rson.long0;
			qing = 0;
		}
	} else if(lson.qing == 10) { //×ó²àÈ«0
		l0
	}
}
};
int main() {

	return 0;
}
