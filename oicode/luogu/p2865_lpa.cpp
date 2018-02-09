#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define EMX 100005
#define DMX 5005
#define IN inline
#define R register
#define W while
#define gc getchar()
queue <int> q;
int head[DMX];
struct Edge
{
	int to, dis, nextt;
}edge[EMX<<1];
int dist1[DMX],dist2[DMX],cnt;
bool in_q[DMX];
IN void in(int &x)
{
	R char c = gc; x = 0;
	W(!isdigit(c))c=gc;
	W(isdigit(c)) x*=10, x += c - 48, c = gc;
}
IN void addedge(int a , int b , int dist)
{
	edge[++cnt].to = b;
	edge[cnt].dis = dist;
	edge[cnt].nextt = head[a];
	head[a] = cnt;
	edge[++cnt].to = a;
	edge[cnt].dis = dist;
	edge[cnt].nextt = head[b];
	head[b] = cnt;
}
void SPFA()
{
	q.push(1);
	dist1[1]=0;
	R int now, nex, now_dis;
	W (!q.empty())
	{
		now = q.front();
		in_q[now]=false;
		q.pop();
		for (R int i = head[now]; i != -1; i = edge[i].nextt)
		{
			nex = edge[i].to;
			now_dis = dist1[now] + edge[i].dis;
			if(dist1[nex] > now_dis)
			{
				swap(now_dis, dist1[nex]);
				if(!in_q[nex])
				q.push(nex), in_q[nex]=true;
			}
			if(dist2[nex] > now_dis && dist1[nex] < now_dis)
			{
				dist2[nex] = now_dis;
				if(!in_q[nex])
				q.push(nex), in_q[nex]=true;
			}
			if(dist2[nex] > dist2[now] + edge[i].dis && dist1[nex] < dist2[now] + edge[i].dis)
			{
				dist2[nex] = dist2[now] + edge[i].dis;
				if(!in_q[nex])
				q.push(nex), in_q[nex]=true;
			}
		}
	}
}
int main(void)
{
	int dot, road, a, b, c;
	in(dot), in(road);
	memset(head,-1,sizeof(head));
	for (R int i = 1; i <= road; ++i)
	{
		in(a), in(b),in(c); 
		addedge(a, b, c);
	}
	memset(dist1,127,sizeof(dist1));
	memset(dist2,127,sizeof(dist2));
	SPFA();
	printf("%d",dist2[dot]);
	return 0;
}