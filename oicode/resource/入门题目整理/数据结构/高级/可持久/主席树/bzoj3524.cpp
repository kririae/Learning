#include<cstdio>
#include<iostream>
#include<set>
#define low(x) (x&(-x))
#define N 300005//3e5µÄÊý¾ÝÓÐµãÏÅÈË£¬²»¹ýÏàÐÅ²»»áT,(but I MLE..bzoj 3524)
/*µ«ÊÇ bzoj2223 AÁË
ËäÈ»Ê÷×´Êý×é³£ÊýÐ¡
µ«ÊÇ³£Êý¾Þ´óµÄset°ÑÊ÷×´Êý×é´øµÃÀ´±È¶þ·Ö+Ö÷Ï¯Ê÷»¹Âý
ÎÞÓï¡£¡£¡£
²»¹ý»¹ÊÇ×÷ËÀ³É¹¦£¬ËäÈ»Ã»ÓÐ¿ªÌì±ÙµØ´´Ôì³öÊ²Ã´ÌØ¿ì½á¹¹£¬µ«ÊÇÐÂ½á¹¹»¹ÊÇÓÐµÄ
ÏÖÔÚ£¬È¥Ñ§Äª¶Ó¹ý2223ÁË
*/
using namespace std;
int n, m, cnt, maxn; // ¡£cntÒªµ¹Ðð ÒòÎªlowerbound ·µ»Ø>=xµÄ
struct nodedate {
	int date, vision;
	bool operator <(const nodedate &b)const {
		return vision < b.vision;
	}
};
set<nodedate> bi_t[10005];//ÓÐµãÏÅÈË£¬ÕâÃ´¶àset
void add(int x) {
	for(int i = x; i <= maxn; i += low(i)) {
		set<nodedate>::iterator itr = bi_t[i].begin();
		bi_t[i].insert((nodedate) {
			(*bi_t[i].begin()).date + 1, cnt
		});
	}
}
int times = 1;
int query(int fr, int en) {
	fr--;//(,]
	int at = 0, ele = (en - fr) >> 1, sum = 0;
	nodedate bufr = (nodedate) {
		1, n - fr + 1
	};
	nodedate bufen = (nodedate) {
		1, n - en + 1
	};//Í»È»·¢¾õÎÒ°ÑdataÆ´³ÉÁËdate

	for(int i = times; i >= 0; i--) {
		at ^= 1 << i;

		if(at > maxn) {
			at ^= 1 << i, sum = 0;
			continue;
		}

		int num = (*bi_t[at].lower_bound(bufen)).date - (*bi_t[at].lower_bound(bufr)).date;

		if(num > ele) at ^= 1 << i, sum = 0;
		else sum += num;
	}

	int buf = (*bi_t[at + 1].lower_bound(bufen)).date - (*bi_t[at + 1].lower_bound(bufr)).date;

	if(buf - sum > ele) return at + 1;

	return 0;
}
int bufin[N];
int main() {
	scanf("%d%d", &n, &maxn);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &bufin[i]);
	}

	for(int i = 0; i <= maxn; i++) bi_t[i].insert((nodedate) {
		0, n + 5
	});

	while((1 << times) <= maxn) times++;

	times--;

	for(cnt = n; cnt > 0; cnt--)
		add(bufin[n - cnt + 1]);

	scanf("%d", &m);

	for(int i = 1; i <= m; i++) {
		int fr, to;
		scanf("%d%d", &fr, &to);
		int x = query(fr, to);

		if(x != 0) {
			printf("yes %d\n", x);
		} else printf("no\n");
	}

	return 0;
}
