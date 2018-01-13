#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
int fp[200005];
int ppcd[200005];
int m, n, k;
char am[200005];
char bm[200005];
/*
***wkl 构造法
*/
void build_demo(char *demo, int *f)
{
	int p1, p2;
	int len = strlen(demo);
	p1 = 0;
	memset(f, 0, sizeof(f));
	f[1] = f[0] = 0;
	p1++;
	while(p1 <= len) {
		int x = 0;
		int save = p1;
		p2 = 0;
		while(demo[p1] == demo[p2] && demo[p1]) {
			x++;
			p1++;
			p2++;
		}
		for(int i = x; i >= 0; i--) {
			f[p1 - (x - i)] = i;
		}
		p1++;
	}
	return ;
}

/*
***lrj动态构造法
*/
void build_demo1(char *demo, int *f)
{
	int len = strlen(demo);
	f[0] = f[1] = 0;
	memset(f, 0, sizeof(f));
	for(int i = 1; i < len; i++) {
		int p = f[i];
		while(p && demo[p] != demo[i]) p = f[p];
		//f[i+1]=(p==0)? 0:p+1;  错误   aaa
		f[i + 1] = (demo[p] == demo[i]) ? p + 1 : 0;
	}
}
/*
***测试结果 几乎相同
*/





/*
***在T中找p 失配数组为f
***返回成功匹配的开头
***失败返回-1
*/
int pipei(char *T, char *p, int *f)
{
	int lent = strlen(T);
	int lenp = strlen(p);
	build_demo1(p, f);
	int ypp = 0; //已匹配的个数
	for(int i = 0; i < lent; i++) { //正在匹配ypp位
		while(ypp && p[ypp] != T[i]) ypp = f[ypp]; //尝试匹配  少点没关系 重点是要匹配
		if(p[ypp] == T[i]) ypp++; //对的 匹配成功 匹配下一位
		if(ypp == lenp) return i - lenp + 1; //指向开头
	}
	return -1;
}


int main()
{
	scanf("%d%d", &m, &n);
	return 0;
}
