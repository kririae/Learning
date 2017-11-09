#include <bits/stdc++.h>
using namespace std;
struct line
{
    int x = 0;
    int y = 0;
    int value = 0x7fffffff;
} p[1000];
line *result = new line[1000];
int *w = new int[1000], *dist = new int[1000] = {0x7fffffff};
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i].x >> p[i].y;
    cin >> m;
    for (int x, y, i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        result[i].x = x, result[i].y = y;
        result[i].value = sqrt(pow(p[x].x - p[y].x, 2) + pow(p[x].y - p[y].y, 2));
    }
    int s, t;
    cin >> s >> t;
    dist[s] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (dist[result[j].x] + result[j].value < dist[result[j].y])
                dist[result[j].y] = dist[result[j].x] + result[j].value;
            if (dist[result[j].y] + result[j].value < dist[result[j].x])
                dist[result[j].x] = dist[result[j].y] + result[j].value;
        }
    }
    cout << dist[t];
    return 0;
}