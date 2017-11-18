---
title: '- 3 - optimal path'
tags:
  - dijkstra
  - floyed
  - ford
  - graph
  - oi
  - SPFA
  - 图论
id: 164
categories:
  - oi
date: 2017-11-03 12:09:22
---

# 图论算法

> 补偿我那段没有停课的日子...
>   首先, 肯定是欧拉路吧...

    #include &lt;iostream&gt;
    #include &lt;cstring&gt;
    using namespace std;
    bool grap[105][105];
    int deepth[105];
    int result[105];
    int n, m, posi = 0;
    void find(int index) {
        for(int i = 1; i &lt;= n; ++i) {
            if(grap[index][i]) {
                grap[index][i] = grap[i][index] = false;
                find(i);
            }
        }
        result[++posi] = index;
    }
    int main() {
        memset(result, 0, sizeof(result));
        cin &gt;&gt; n &gt;&gt; m;
        for(int x, y, i = 0; i &lt; m; ++i) {
            cin &gt;&gt; x &gt;&gt; y;
            grap[x][y] = grap[y][x] = true;
            ++deepth[x];
            ++deepth[y];
        }
        int starti = 1;
        for(int i = 1; i &lt;= n; ++i) {
            if(deepth[i] % 2 == 1)
                starti = i;
        }
        find(starti);
        for(int i = 1; i &lt;= posi; ++i) {
            cout &lt;&lt; result[i] &lt;&lt; " ";
        }
    }
    `</pre>

    以上...的...

    ### floyed

    [toc]

    <pre class="line-numbers prism-highlight" data-start="1">`#include &lt;iostream&gt;
    #include &lt;cstdio&gt;
    #include &lt;cmath&gt;
    #include &lt;cstring&gt;
    using namespace std;
    struct point {
        double x;
        double y;
    } p[101];
    double value[101][101];
    int main() {
        int n;
        cin &gt;&gt; n;
        for (int i = 1; i &lt;= n; ++i) {
            cin &gt;&gt; p[i].x &gt;&gt; p[i].y;
        }
        int m;
        cin &gt;&gt; m;
        memset(value, 0x7f, sizeof(value));
        for(int x, y, i = 1; i &lt;= m; ++i) {
            cin &gt;&gt; x &gt;&gt; y;
            value[y][x] = value[x][y] = sqrt(pow(p[x].x - p[y].x, 2) + pow(p[x].y - p[y].y, 2));
        }
        int s, t;
        cin &gt;&gt; s &gt;&gt; t;
        for (int k = 1; k &lt;= n; ++k) {
            for (int i = 1; i &lt;= n; ++i) {
                for (int j = 1; j &lt;= n; ++j) {
                    if(i != j &amp;&amp; i != k &amp;&amp; j != k &amp;&amp; value[i][k] + value[k][j] &lt; value[i][j]) {
                        value[i][j] = value[i][k] + value[k][j];
                    }
                }
            }
        }
        printf("%.2lf", value[s][t]);
        return 0;
    }
    `</pre>

    > 原理:
>       floyed --- 动态规划算法, 对每一个节点进行迭代
>       `value[i][j] = value[i][k] + value[k][j];`
>       一个点到另外一个点的距离用`value[i][j]来表示`
>       状态转移方程: `f[i][j] = max(f[i][k] + f[k][j], f[i][j]);`

    ## ### dijkstra

    dijkstra算法的时间复杂度是O(n^2)
    dijkatra和ford的基本都有一个, 蓝白点的控制
    蓝点代表还没计算出最小距离的点...白点代表计算出了的
    用一个`white[maxn]`表示
    最开始的时候将`white[1]`设置为`true`
    因为我们将最开始的点默认为其距离为0,将其设置为一个白点
    因为是“单源距离计算” 大概就是一次只能计算一个点到某一个点的距离
    所以起始点到当前点的距离用`dist[i]`来表示
    `dist[1] = 0, white[1] = true`
    先把代码放出来

    <pre class="line-numbers prism-highlight" data-start="1">`#include &lt;iostream&gt;
    #include &lt;cstdio&gt;
    #include &lt;cmath&gt;
    #include &lt;cstring&gt;
    using namespace std;
    const int maxn = 0x7fffffff;
    struct point {
        double x;
        double y;
    } p[101];
    double value[101][101];
    double dist[101];
    bool cango[101];
    int main() {
        for(int i = 0; i &lt; 101; ++i) 
            dist[i] = maxn;
        for(int i = 0; i &lt; 101; ++i) {
            for(int j = 0; j &lt; 101; ++j) {
                value[i][j] = maxn;
            }
        }
        int n;
        cin &gt;&gt; n;
        for (int i = 1; i &lt;= n; ++i) {
            cin &gt;&gt; p[i].x &gt;&gt; p[i].y;
        }
        int m;
        cin &gt;&gt; m;
        memset(value, 0x7f, sizeof(value));
        for(int x, y, i = 1; i &lt;= m; ++i) {
            cin &gt;&gt; x &gt;&gt; y;
            value[y][x] = value[x][y] = sqrt(pow(p[x].x - p[y].x, 2) + pow(p[x].y - p[y].y, 2));
        }
        int s, t;
        cin &gt;&gt; s &gt;&gt; t;
        for(int i = 1; i &lt;= n; ++i) 
            dist[i] = value[s][i];
        cango[1] = true;
        dist[1] = 0;
        for(int i = 1; i &lt;= n; ++i) {
            int minn = maxn;
            int minindex = 0;
            for(int j = 1; j &lt;= n; ++j) {
                if(!cango[j] &amp;&amp; minn &gt; dist[j]) {
                    minindex = j;
                    minn = dist[j];
                }
            }
            if(minindex == 0) break;
            cango[minindex] = true;
            for(int j = 1; j &lt;= n; ++j) {
                if(dist[minindex] + value[minindex][j] &lt; dist[j]) {
                    dist[j] = dist[minindex] + value[minindex][j];
                }
            }
        }
        printf("%.2lf", dist[t]);
        return 0;
    }
    `</pre>

    有点长啊...
    直接说核心的部分
    大概是这里
    提前说明每一个变量的意思

    > `dist[i]: 初始点到i点的距离`
>       `cango[] 白点, 有没有计算最小值的点`
>       `value[][], 某个点到某个点的距离, 有部分无限大`

    <pre class="line-numbers prism-highlight" data-start="1">`for(int i = 1; i &lt;= n; ++i) 
        dist[i] = value[s][i];
    cango[1] = true;
    dist[1] = 0;
    for(int i = 1; i &lt;= n; ++i) {
        // 这一个循环是迭代所有点
        // 下面是寻找最小的值, 就是寻找下一个变为白点的点
        int minn = maxn; // 我之前已经把maxn初始化为0x7fffffff
        int minindex = 0; // 那个点的坐标
        for(int j = 1; j &lt;= n; ++j) {
            if(!cango[j] &amp;&amp; minn &gt; dist[j]) {
            // 这一个循环的意思是 如果那一个点是蓝点 那么判断他是不是最小值
            // 这里有一个可以说明的地方
            // 最后的minn &gt; dist[j]
            // 这里有一个关键
            /*
            第一次循环后，会把最小的那个，就是和出发点直接通路的那一个最小的点初始化
            因为前面的第一个循环
            (for(int i = 1; i &lt;= n; ++i) 
                dist[i] = value[s][i];)
            将大部分化为了无限大
            所以这里只会管和a相接的
            很多教程没讲清楚
            搞得很恼火...
            */
                minindex = j;
                minn = dist[j];
            }
        }
        if(minindex == 0) break; // 如果找不到了, 那就代表照完了, 程序结束
        cango[minindex] = true; // 将找到的并且执行的点化为白点, 代表已经计算最小值（其实还没有
        // 这里才是嘛
        for(int j = 1; j &lt;= n; ++j) {
        // 遍历所有的点
            if(dist[minindex] + value[minindex][j] &lt; dist[j]) {
                // 第一次的话 这里的dist[j] 其实是0x7fffffff的
                // 看能不能够替换
                dist[j] = dist[minindex] + value[minindex][j];
            }
        }
        printf("%.2lf", dist[t]); // 因为要输出最小的嘛
    }
    `</pre>

    倒是一个很绝妙的算法..就是写起来太麻烦啦!

    ### Bellman-Ford &amp;&amp; SPFA

    下面是ford

    <pre class="line-numbers prism-highlight" data-start="1">`#include &lt;bits/stdc++.h&gt;
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
        cin &gt;&gt; n;
        for (int i = 1; i &lt;= n; ++i)
            cin &gt;&gt; p[i].x &gt;&gt; p[i].y;
        cin &gt;&gt; m;
        for (int x, y, i = 1; i &lt;= m; ++i)
        {
            cin &gt;&gt; x &gt;&gt; y;
            result[i].x = x, result[i].y = y;
            result[i].value = sqrt(pow(p[x].x - p[y].x, 2) + pow(p[x].y - p[y].y, 2));
        }
        int s, t;
        cin &gt;&gt; s &gt;&gt; t;
        dist[s] = 0;
        for (int i = 1; i &lt;= n; ++i)
        {
            for (int j = 1; j &lt;= m; ++j)
            {
                if (dist[result[j].x] + result[j].value &lt; dist[result[j].y])
                    dist[result[j].y] = dist[result[j].x] + result[j].value;
                if (dist[result[j].y] + result[j].value &lt; dist[result[j].x])
                    dist[result[j].x] = dist[result[j].y] + result[j].value;
            }
        }
        cout &lt;&lt; dist[t];
        return 0;
    }
    `</pre>

    下面是LR的最短路径...我不想写了...

    <pre class="line-numbers prism-highlight" data-start="1">`/* 
    * by LittleRewriter
    * SPFA
    */
    #include &lt;bits/stdc++.h&gt;
    using namespace std;
    #define MAXN 10005
    #define INF 0x7fffffff
    typedef long long LL;
    LL start, n, m;
    bool vis[MAXN];
    LL dis[MAXN];
    inline void read(LL &amp;x) {
        x = 0; char c = getchar();
        while (!isdigit(c)) c = getchar();
        while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    }
    struct edge{
        LL to, va;
        edge(LL a, LL b) {
            to = a, va = b;
        }
    };
    vector&lt;edge&gt; v[MAXN];
    void add_edge(LL from, LL to, LL va) {
        v[from].push_back(edge(to, va));
    }
    void SPFA() {
        queue&lt;LL&gt; q;
        q.push(start);
        vis[start] = 1;
        dis[start] = 0;
        while (!q.empty()) {
            LL now = q.front();
            q.pop();
            vis[now] = 0;
            for (int i = 0; i &lt;v[now].size(); ++i) {
                //cout&lt;&lt;dis[v[now][i].to]&lt;&lt;" "&lt;&lt;dis[now]&lt;&lt;" "&lt;&lt;v[now][i].to&lt;&lt;endl;
                if (dis[v[now][i].to] &gt; dis[now] + v[now][i].va) {
                    dis[v[now][i].to] = dis[now] + v[now][i].va;    
                    if (!vis[v[now][i].to]) {
                        q.push(v[now][i].to); 
                        vis[v[now][i].to] = 1; 
                    }
                }
            }
        }
    }
    int main() {
        cin&gt;&gt;n&gt;&gt;m&gt;&gt;start;
        LL a, b, c;
        for (int i = 1; i &lt;= m; ++i) {
            read(a), read(b), read(c);
            add_edge(a, b, c);
        }
        for (int i = 1; i &lt;= n; ++i) dis[i] = INF;  
        //memset(dis, INF, sizeof(dis));
        //for(int i = 1; i &lt;= 5; ++i) cout&lt;&lt;dis[i]&lt;&lt;" ";
        /*for(int i = 1; i &lt;= n; ++i) {
            for(int j = 0; j &lt; v[i].size(); ++j)
                printf("%d ", v[i][j].to);
            printf("\n");
        }*/
        SPFA();
        for (int i = 1; i &lt;= n; ++i) {
            cout&lt;&lt;dis[i]&lt;&lt;" ";
        }
    }
    `</pre>

    太晚了 以后再解释了
    i'm coming back...
    貌似有点没搞清楚
    核心部分

    <pre class="line-numbers prism-highlight" data-start="1">`void SPFA() {
        queue&lt;LL&gt; q;
        q.push(start);
        vis[start] = 1;
        dis[start] = 0;
        while (!q.empty()) {
            LL now = q.front();
            q.pop();
            vis[now] = 0;
            for (int i = 0; i &lt;v[now].size(); ++i) {
                //cout&lt;&lt;dis[v[now][i].to]&lt;&lt;" "&lt;&lt;dis[now]&lt;&lt;" "&lt;&lt;v[now][i].to&lt;&lt;endl;
                if (dis[v[now][i].to] &gt; dis[now] + v[now][i].va) {
                    dis[v[now][i].to] = dis[now] + v[now][i].va;    
                    if (!vis[v[now][i].to]) {
                        q.push(v[now][i].to); 
                        vis[v[now][i].to] = 1; 
                    }
                }
            }
        }
    }
    `</pre>

    对 就是这一部分
    while(不是空的 - >还没有迭代完所有的点) {
        将当前要处理的点取出来
        然后把那个点pop出来
        vis的意思是“是否在队列里”(lr教我的...)
        如果在 就不加了
        v[now]是当前的储存方式 就是当前点能够到的所有位置...
        所以有一个从零开始的迭代, 迭代当前edge能够到的所有点
        然后dis[v[now][i].to]就是从零到最大的, 初始化为无限大
        如果是“没有修改过的”, 就用到当前点的最小值 + 这条线的长度修改那个点(可以看成用白点修改蓝点)
        if (!vis[v[now][i].to]) {
            q.push(v[now][i].to); 
            vis[v[now][i].to] = 1; 
        }
        大概就是(如果处理的点不在队列里) 那就加入(以后准备处理) 然后标记为在队列里
        如果在队列里 那就不管
    }
    如果大概剖析一下的话
    SPFA是ford的队列版本
    ford的原理是对每一条线迭代 用蓝点修改白点
    由于是单源求解 就用一个dis的大小来表示当前距离start的距离 vis来表示这个点在不在队列里

    <pre class="line-numbers prism-highlight" data-start="1">`while(!q.empty()) {
    }

在所有点里 如果全部解决了 那就退出了呗
大概就是对每一个能够到的点 然后迭代以他为起点的所有线
然后用当前点修改它所到的点