---
title: '- 2 - bfs'
tags:
  - oi
id: 107
categories:
  - oi
date: 2017-10-26 22:55:11
---

<iframe frameborder="no" border="0" marginwidth="0" marginheight="0" width=330 height=86 src="//music.163.com/outchain/player?type=2&id=28699494&auto=0&height=66"></iframe>

<iframe frameborder="no" border="0" marginwidth="0" marginheight="0" width=330 height=86 src="//music.163.com/outchain/player?type=2&id=4937357&auto=0&height=66"></iframe>

> 由于本子是从开始学习bfs之后买的，就从bfs写起吧...
>   写的不高级 见谅（

## bfs采用队列

## dfs采用递归

至于队列的使用方法？分为几种吧...
- queue
- array（数组

我相对来说...都挺喜欢用的，看方便不了...

## queue

首先需要知道队列怎么用..

    #include &lt;queue&gt;
    queue&lt;int&gt; q;
    q.push(i);
    q.pop();  
    q.size(); 
    q.front();
    q.back();
    `</pre>

    具体函数作用我就不赘述了，和stack大致一样（stl好像基本都是这样的
    在bfs中，queue的用法实例:
    这个是最最最最经典的了吧..
    来个走迷宫的吧..
    简单描述了

    > 输入n, m分别为矩阵的行数和列数
>       然后输入一个矩阵，求从起点到终点最小步数

    <pre class="line-numbers prism-highlight" data-start="1">`// 我也知道这篇代码很幼稚...但那毕竟是我曾经写出来的
    #include &lt;iostream&gt;
    #include &lt;cstdio&gt;
    #include &lt;cstring&gt;
    #include &lt;queue&gt;
    using namespace std;
    struct point {
        int x;
        int y;
        int deepth;
    };
    bool cango[202][202];   //走过的位置（判重
    const int go[4][2] = { { 1, 0 },{ -1, 0 },{ 0, -1 },{ 0, 1 } }; //为了方便，建立常量数组
    int main() {
        memset(cango, false, sizeof(cango));
        int n, m;
        cin &gt;&gt; n &gt;&gt; m;
        for (int i = 1; i &lt;= n; ++i)
            for (int j = 1; j &lt;= m; ++j) {
                char x;
                cin &gt;&gt; x;
                cango[i][j] = (x == '.');
            }
        queue&lt;point&gt; q;
        point root;
        cango[1][1] = true;
        root.x = 1, root.y = 1, root.deepth = 1;
        q.push(root);
        while (!q.empty()) {
            for (int i = 0; i &lt; 4; ++i) {
                int gox = q.front().x + go[i][0];
                int goy = q.front().y + go[i][1];
                if (gox &lt; 1 || goy &lt; 1 || gox &gt; n || goy &gt; m) continue; // 如果有不符合条件的 那就下一个
                if (!cango[gox][goy]) continue; // 如果不能走 那就下一个
                cango[gox][goy] = false;
                if (gox == n &amp;&amp; goy == m) { cout &lt;&lt; q.front().deepth; return 0; }
                point p;
                p.x = gox, p.y = goy, p.deepth = q.front().deepth + 1;
                q.push(p);
            }
            cango[q.front().x][q.front().y] = false;
            q.pop();
        }
        cout &lt;&lt; "failed";
        return 0;
    }
    `</pre>

    好啦qwq
    对这篇代码进行简单的解释

    <pre class="line-numbers prism-highlight" data-start="1">`while (!q.empty()) {
        for (int i = 0; i &lt; 4; ++i) {
            int gox = q.front().x + go[i][0];
            int goy = q.front().y + go[i][1];
            if (gox &lt; 1 || goy &lt; 1 || gox &gt; n || goy &gt; m) continue; // 如果有不符合条件的 那就下一个
            if (!cango[gox][goy]) continue; // 如果不能走 那就下一个
            cango[gox][goy] = false;
            if (gox == n &amp;&amp; goy == m) { cout &lt;&lt; q.front().deepth; return 0; }
            point p;
            p.x = gox, p.y = goy, p.deepth = q.front().deepth + 1;
            q.push(p);
        }
        cango[q.front().x][q.front().y] = false;
        q.pop();
    }
    `</pre>

    这段是bfs的核心
    其中`cango[][]`表示能够去的点
    gox和goy表示下一个点
    想象一下，一个队列
    bfs的核心可以用两个词语概括
    “正在处理” “当前处理的源头”
    [2, 2][1, 2][2, 1][3, 2][3, 1]这些都是从1, 1延伸出来的
    for循环前 : [2, 2]
        for循环后 : [2, 2][1, 2][2, 1][3, 2][3, 1]
    然后取出第一个[2, 2]
    因为不再需要了
    接下来进入[1, 2]作为根节点的时间
            又成了 : [1, 2][2, 1][3, 2][3, 1][...][...][...][...]
    后面四个是以[1, 2]延伸出来的，然后[1, 2]又不需要了，有了q.pop()取出[1, 2]
    下一个q.front就是[2, 1]
                这下成了[2, 1][3, 2][3, 1][...][...][...][...][...][...][...][...]
    后面四个是由[2, 1]延伸出来的
    不需要再写了...这是利用队列的方式

    至于利用array，没必要赘述了...
    下面是模板:

    <pre class="line-numbers prism-highlight" data-start="1">`const int go[.][.] = {}; // 常量数组，方便循环
    建立根，将根加入判重队列中
    while (!q.empty()) {
        for (int ...) {
            int gox = ...;
            int goy = ...;
            // (跳出当前的条件)
            // if(gox &lt; 1 || goy &lt; 1 || gox &gt; n || goy &gt; m) continue; // 如果有不符合条件的 那就下一个
            // if(!cango[gox][goy]) continue; // 如果不能走 那就下一个
            将新的压入队列中
        }
        将之前的节点弹出来，没必要用了，节约内存...
    }
    `</pre>

    然后写一点关于bfs判重有关的..
    几个吧？
    - set
    - 桶（最快

    <pre class="line-numbers prism-highlight" data-start="1">`#include &lt;set&gt;
    #include &lt;iostream&gt;
    set&lt;int&gt; s;
    int main() {
        int n;
        cin &gt;&gt; n;
        for (int i = 0; i &lt; n; ++i) {
            int value;
            cin &gt;&gt; value;
            set.insert(value);
        }
        int a;
        cin &gt;&gt; a;
        cout &lt;&lt; set.count(a) &lt;&lt; endl;
        return 0;
    }
    `</pre>

    <pre class="line-numbers prism-highlight" data-start="1">`至于桶，倒是有一个骚操作
    vector&lt;int&gt; s[100007];
    在这个100007的桶里push_back
    虽然烧内存
    但是速度up~up~up~

晚安