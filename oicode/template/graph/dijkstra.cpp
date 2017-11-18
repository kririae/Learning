#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 0x7fffffff;
struct point
{
    double x;
    double y;
} p[101];
double value[101][101];
double dist[101];
bool cango[101];
int main()
{
    for (int i = 0; i < 101; ++i)
        dist[i] = maxn;
    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0; j < 101; ++j)
        {
            value[i][j] = maxn;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }
    int m;
    cin >> m;
    memset(value, 0x7f, sizeof(value));
    for (int x, y, i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        value[y][x] = value[x][y] = sqrt(pow(p[x].x - p[y].x, 2) + pow(p[x].y - p[y].y, 2));
    }
    int s, t;
    cin >> s >> t;
    for (int i = 1; i <= n; ++i)
        dist[i] = value[s][i];
    cango[1] = true;
    dist[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int minn = maxn;
        int minindex = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (!cango[j] && minn > dist[j])
            {
                minindex = j;
                minn = dist[j];
            }
        }
        if (minindex == 0)
            break;
        cango[minindex] = true;
        for (int j = 1; j <= n; ++j)
        {
            if (dist[minindex] + value[minindex][j] < dist[j])
            {
                dist[j] = dist[minindex] + value[minindex][j];
            }
        }
    }
    printf("%.2lf", dist[t]);
    return 0;
}
