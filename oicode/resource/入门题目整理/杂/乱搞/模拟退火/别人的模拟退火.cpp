#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

struct pos {
	double x, y;
} *P, city[101];
int n;

///////// 计算点x到各点距离之和 /////////////
double dis(struct pos * x) {
	double d = 0;

	for (P = city + n - 1; P >= city; P--)
		d += hypot(P->x - x->x, P->y - x->y);

	return d;
}

///////// 模拟退火 /////////////
double SA() {
	double t, min, tmp;     // 温度，最小距离，临时距离
	struct pos p, tp;       // 最优点，临时点
	int k = 0;                  // 记录连续未接受点数

	p.x = p.y = 5000;       // 初始化最优点为中心点
	min = dis(&p);
	srand((unsigned)&t);

	///// 初始化温度，温度以一定速率减小，温度小于临界（1） 或 连续超过一定数量（20）个临时点未被接受时 终止 /////
	for (t = 5000; t > 1 && k++ < 20; t *= .93) {

		///// 在p周围一定 范围 内生成临时点， 该范围随温度t降低逐渐减小 /////
		tp.x = p.x + (rand() & 1 ? 1 : -1) * rand() * t / RAND_MAX;
		tp.y = p.y + (rand() & 1 ? 1 : -1) * rand() * t / RAND_MAX;
		tmp = dis(&tp);

		///// 若生成的临时点距离小于当前最小，更新最优点 /////
		///// 否则，以一定 概率 接受该临时点，该概率随温度t降低逐渐减小 /////
		if (tmp < min || rand() * 10000. / RAND_MAX < t) {
			p = tp;
			min = tmp;
			k = 0;
		}
	}

	return min;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &city[i].x, &city[i].y);

	printf("%.0f\n", SA());
	return 0;
}
