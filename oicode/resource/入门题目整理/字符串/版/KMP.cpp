#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
int f[1000005];
int len;
/*
***wkl 构造法
*/
void build_demo(char *demo)
{
	int p1, p2;
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
void build_demo1(char *demo)
{
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
int main()
{
	char s[1000002];
	for(int i = 0; i < 500002; i++) {
		s[i * 2] = 1;
		s[i * 2 + 1] = (i % 255) + 1;
	}
	len = strlen(s);
	time_t a, b;
	a = clock();
	build_demo(s);
	b = clock();
	printf("%d", b - a);
	return 0;
}
