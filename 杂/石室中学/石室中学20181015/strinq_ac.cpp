#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cmath>
#define R register
#define IN inline
#define W while
#define gc getchar()
#define File freopen("strinq.in", "r", stdin), freopen("strinq.out", "w", stdout)
#define MX 50050
char buf1[MX], buf2[MX];
struct Seg {int id, len, mark;} dat1[MX], dat2[MX];
int cnt1, cnt2, len1, len2;
int main(void)
{
	#ifdef LPA
	freopen("strinq.in", "r", stdin);
	#else
	File;
	#endif
	int T, l, mk, id;
	scanf("%d", &T);
	start : W (T--)
	{
		cnt1 = cnt2 = l = mk = 0;
		scanf("%s%s", buf1 + 1, buf2 + 1);
		len1 = std::strlen(buf1 + 1), len2 = std::strlen(buf2 + 1);
		buf1[0] = buf1[1], buf2[0] = buf2[1]; id = buf1[0];
		for (R int i = 1; i <= len1; ++i)
		{
			if(buf1[i] == id) ++l;
			else if(buf1[i] == '*') mk = true;
			else dat1[++cnt1] = {id, l, mk}, mk = false, l = 1, id = buf1[i];
		}
		dat1[++cnt1] = {id, l, mk};
		l = mk = 0; id = buf2[1];
		for (R int i = 1; i <= len2; ++i)
		{
			if(buf2[i] == id) ++l;
			else dat2[++cnt2] = {id, l, mk}, mk = false, l = 1, id = buf2[i];
		}
		dat2[++cnt2] = {id, l, mk};
		if(cnt1 ^ cnt2) {puts("No"); goto start;}
		for (R int i = 1; i <= cnt1; ++i)
		{
			if(dat1[i].id ^ dat2[i].id) {puts("No"); goto start;}
			if(dat1[i].len < dat2[i].len && !dat1[i].mark) {puts("No"); goto start;}
			if(dat1[i].len > dat2[i].len) {puts("No"); goto start;}
		}
		puts("Yes");
	}
}
