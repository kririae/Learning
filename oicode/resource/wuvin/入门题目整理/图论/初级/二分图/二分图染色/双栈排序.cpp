#include<cstdio>
#include<iostream>
#include<vector>
/*
真是一道神奇的题目(可以用并查集)
…… a b c d a-1 1 a+e ……
考虑数字a 假设c>b>a>d
由于需要按照1234……n的顺序弹出
所以a入栈后bc一定不能压在a上面，只能在对面的栈
而d比a小，所以d随便放，不对a造成影响
a-1同理
//但是a-1弹出后就该弹a了，所以ef是不用考虑的(错误)
（此时a-1并不一定能弹出，要等到a-2弹了才行，以此类推要一直讨论到最右侧比a小的数k才行）
构图：a向右侧k之前比a大的连边
最后黑白染色
至于什么字典序之类的
加点连通分量就对了
然后我就不想写程序了。。。
*/
using namespace std;
const int black = 1;
const int white = 2; //stack 1
int n;
int xl[1005];
int rxl[1005];//reverse
int map[1005][1005];
int color[1005];//
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &xl[i]);
	}
	for(int i = 1; i <= n; i++) {
		rxl[xl[i]] = i;
	}
	color[1] = white;
	for(int i = 2; i <= n; i++) {
		for(int j = )
		}
	return 0;
}