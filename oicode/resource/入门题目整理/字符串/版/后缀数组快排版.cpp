#include<bits/stdc++.h>
using namespace std;
/*------------------------------------------
nlogn*logn
------------------------------------------*/
char s[105];
int len;
int sa[105];//最终的后缀数组
int f1[105], f2[105];
int n1;//上次排序结果f1 本次排序装到f2
bool cmp(int a, int b) //指向的a和指向的b谁大   第n1次排序两个元素距离相差2^（n-1)
{
	if(f1[a] != f1[b]) return f1[a] < f1[b];
	int dd = 1 << (n1 - 1); //先算加减再算位运算
	if(b + dd > len) return false;
	if(a + dd > len) return true;
	return f1[a + dd] < f1[b + dd];
}
int tj[105];//统计  105为元素种类
void build()
{
	for(int i = 0; i < len; i++) {
		tj[s[i] - 'a'] = 1;
	}
	for(int i = 1; i < 105; i++) {
		tj[i] += tj[i - 1];
	}
	for(int i = 0; i < len; i++) {
		f1[i] = tj[s[i] - 'a'];
	}
	//----初始化完成-------
	for(int i = 0; i < len; i++) {
		f2[i] = i;
	}
	n1 = 1;
	for(int k = 1; k < len; k <<= 1, n1++) {
		sort(f2, f2 + len, cmp);
		int cnt = 1;
		tj[0] = 1;
		bool fl = true;
		for(int i = 1; i < len; i++) {
			if(cmp(f2[i - 1], f2[i])) {
				cnt++;
			} else {
				fl = false;
			}
			tj[i] = cnt;
		}
		for(int i = 0; i < len; i++) {
			f1[f2[i]] = tj[i];
		}
		if(fl) break;
	}
	//----排序完成----------
	for(int i = 0; i < len; i++) {
		sa[i] = f1[i];
	}
}
int main()
{
	char sr[] = "aabaaaab";
	for(int i = 0, len1 = strlen(sr); i < len1; i++) {
		s[i] = sr[i];
	}
	len = strlen(s);
	build();
	for(int i = 0; i < len; i++) {
		printf("%d", sa[i]);
	}
	return 0;
}
