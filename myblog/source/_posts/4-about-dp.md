---
title: '- 4 - about dp'
tags:
  - dp
  - 动态规划
  - 字符串距离
  - 递推
id: 174
categories:
  - oi
date: 2017-11-03 20:42:21
---

# - 4 - about dp

> dp做的还是有点小小的恼火...
>   我还是有写一点东西的必要了
>   动规解题的思路

*   分解为子问题

    > 比如说对于数字三角形, 子问题就是求这一步和上一步行走距离最小的...
>   (形式和原问题基本一致...只是将问题化小)
>   比如说背包问题, 子问题有两种表示方法
>   `到达当前状态(质量)的最大可以装的物品的价值`
>   `取...物品, 在小于m的质量下, 价值的最大值`
*   确认状态

    > 数字三角形的当前状态就是"到这个位置的最大和.."
>   (个人觉得逆推可能更好思考?)
*   确认边界状态的值

    > 比如说数字三角形, 边界状态就是第一个数或者最后一行数字
>   比如说背包问题, 边界状态就是`value[0]`
*   状态转移方程

    > 比如说我之前写过的...背包问题的状态转移方程...
>   `f[i] = max(f[i - w] + c, f[i]);`
>   `f[i][v] = max(f[i - 1][v - w] + c, f[i - 1][v]);`
>   还有数字三角形的状态转移方程: `f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + value[i][j];`
>   “上一个状态到当前如何变化”

啊, 稍微难一点...
放出一段代码:

    #include &lt;iostream&gt;
    #include &lt;cstdio&gt;
    #include &lt;cstring&gt;
    using namespace std;
    int map[15][15];
    int value[15][15][15][15];
    int main() {
        memset(map, 0, sizeof(map));
        int n;
        cin &gt;&gt; n;
        while(true) {
            int xi, yi, v;
            cin &gt;&gt; xi &gt;&gt; yi &gt;&gt; v;
            if(xi == 0 &amp;&amp; yi == 0 &amp;&amp; v == 0) break;
            map[xi][yi] = v;
        }
        for(int i = 1; i &lt;= n; ++i) {
            for(int j = 1; j &lt;= n; ++j) {
                for(int k = 1; k &lt;= n; ++k) {
                    for(int l = 1; l &lt;= n; ++l) {
                        int list[4] = 
                        {
                            value[i - 1][j][k - 1][l], value[i][j - 1][k][l - 1],
                            value[i - 1][j][k][l - 1], value[i][j - 1][k - 1][l]
                        };
                        int maxn = 0;
                        for(int i = 0; i &lt; 4; ++i) if(maxn &lt; list[i]) maxn = list[i];
                        value[i][j][k][l] = maxn + map[k][l];
                        if(i != k &amp;&amp; j != l) value[i][j][k][l] += map[i][j];
                    }
                }
            }
        }
        cout &lt;&lt; value[n][n][n][n];
        return 0;
    }
    `</pre>

    这段代码中
    - 子问题就是“两个人上一步到这一步能够取得最大的数字”
    - 状态是“到达当前状态能够取得最大的数字”, 用`value[n][n][n][n]`表示
    - 边界状态是`value[0][0][0][0]`
    - 状态转移方程`value[i][j][k][l] = max(value[i - 1][j][k - 1][l], value[i][j - 1][k][l - 1],value[i - 1][j][k][l - 1], value[i][j - 1][k - 1][l]) + map[k][l] + map[i][j];`
    以上 就是这样

    啊，继续补充一点吧...
    关于LCS, 最长公共子序列..
    7 6 8 2 3
    8 9 2 3 6
    求这两组的最长公共子序列
    按照前面书写的
    首先想出状态
    `f[i][j]`表示到a的i位置.b的j位置的最长公共子序列
    那么看看
    follow meee!!!
    到1, 1的位置
    不存在 `f[1][1] = 0;`
    继续到1, 2的位置
    不存在 `f[1][2] = 0;`
    到1, 3的位置
    `f[1][3] = 0;`
    1, 4
    `f[1][4] = 0;`
    1, 5
    `f[1][5] = 0;`

    进入2了...
    `f[2][1] = 0`
    `f[2][2] = 0;`
    `f[2][3] = 0;`
    `f[2][4] = 0;`
    因为 到a的2位置, b的5位置 存在`f[2][5] = 1;`
    6为其公共子序列

    `f[3][1] = 1`
    `f[3][2] = 0`
    `f[3][3] = 0`
    `f[3][4] = 1`
    `f[3][5] = 1`
    这里的`f[3][5]`的变化需要注意一下
    其实从前面的也可以看出来, 只是这里比较明显
    可以得出方程`f[3][5] = f[3][4]`
    因为`b[5]`不在a中
    得出第一个关键 **`f[i][j] = f[i][j - 1]`**
    当这个不在公共子序列中
    那么同理可得
    `f[i][j] = f[i - 1][j]` 当当前元素不在公共子序列中
    接着这个惯性走下去, 当两个都在的时候, 该怎么做?
    `f[i][j] = f[i - 1][j - 1] + 1`
    看看之前每次有增加的
    `f[3][4] = f[2][3] + 1`
    大概就可以知道了
    我笨, 只能用这种方法来促使自己理解...

    剩下的会更加细致

    `f[4][1]`

    > a中的第四个元素2在公共子序列中
>       b的第一个元素在公共子序列中
>       可以得到: `f[4][1] = f[3][0] + 1;`
>       所有`f[4][1] = 1;`

    `f[4][2]`
    9不在公共子序列中
    所以`f[4][2] = 1;`

    `f[4][3] = 2`
    `f[4][4] = 2`
    `f[4][5] = ....`
    懒得写了
    大概就是这样的说 会有推理错的吧...
    代码如下

    <pre class="line-numbers prism-highlight" data-start="1">`/*
    * by kriaeth 2017/11/7 20:54
    * lcs
    */
    #include &lt;bits/stdc++.h&gt;
    using namespace std;
    int value[205][205] = {0};
    char a[205];
    char b[205];
    int lcs(char* a, char* b);
    int main() {
        while(scanf("%s%s", a + 1, b + 1) == 2) {
            cout &lt;&lt; lcs(a, b) &lt;&lt; endl;
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
        }
        return 0;
    }
    int lcs(char *a, char *b) {
        memset(value, 0, sizeof(value));
        int lena = strlen(a + 1), lenb = strlen(b + 1);
        for(int i = 1; i &lt;= lena; ++i) {
            for(int j = 1; j &lt;= lenb; ++j) {
                if(a[i] == b[j]) {
                    value[i][j] = value[i - 1][j - 1] + 1;
                }
                else {
                    value[i][j] = max(value[i - 1][j], value[i][j - 1]);
                }
            }
        }
        return value[lena][lenb];
    }
    `</pre>

    * * *

    一个例题
    <button > [luogu2733](https://www.luogu.org/problem/show?pid=2733) </button>

    > ### 题目背景
> 
>       农民约翰在一片边长是N (2 &lt;= N &lt;= 250)英里的正方形牧场上放牧他的奶牛。(因为一些原因，他的奶牛只在正方形的牧场上吃草。)遗憾的是,他的奶牛已经毁坏一些土地。( 一些1平方英里的正方形)

    ### 题目描述

    > 农民约翰需要统计那些可以放牧奶牛的正方形牧场(至少是2x2的,在这些较大的正方形中没有一个点是被破坏的，也就是说，所有的点都是“1”)。
>       你的工作要在被供应的数据组里面统计所有不同的正方形放牧区域(>=2x2)的个数。当然，放牧区域可能是重叠。

    ### 输入输出格式

    #### 输入格式：

    > 第 1 行:N,牧区的边长。
>       第 2 到 n+1 行:N个没有空格分开的字符。0 表示 "那一个区段被毁坏了";1 表示 " 准备好被吃"。

    #### 输出格式：

    > 输出那些存在的正方形的边长和个数，一种一行。

    ##### 输入样例

    6
    101111
    001111
    111111
    001111
    101101
    111001

    ##### 输出样例

    2 10
    3 4
    4 1

    好难了我一会儿...看了题解 + 自己的理解

    ## 读入么...

    <pre class="line-numbers prism-highlight" data-start="1">`bool farm[255][255];
    int n;
    cin &gt;&gt; n;
    for(int i = 1; i &lt;= n; ++i) {
        for(int v, j = 1; j &lt;= n; ++j) {
            cin &gt;&gt; v;
            farm[i][j] = (v == '1');
        }
    `</pre>

    推理: 
    状态表示: 以`f[i][j]为右下角的最大正方形`
    像之前一样...再次推理一次
    a...小点的吧

    > 4
>       0111
>       1111
>       1111
>       0110
>       2 6
>       3 1

    从0, 0开始
    无...
    0, 1
    这样看 0 开头的都算了
    1, 0无

    # TODO

    再来一道题
    <button> [ 一本通 1344 ](http://ybt.ssoier.cn:8088/problem_show.php?pid=1302)</button>

    > 最近越来越多的人都投身股市，阿福也有点心动了。谨记着“股市有风险，入市需谨慎”，阿福决定先来研究一下简化版的股票买卖问题。
>       假设阿福已经准确预测出了某只股票在未来N天的价格，他希望买卖两次，使得获得的利润最高。为了计算简单起见，利润的计算方式为卖出的价格减去买入的价格。
>       同一天可以进行多次买卖。但是在第一次买入之后，必须要先卖出，然后才可以第二次买入。
>       现在，阿福想知道他最多可以获得多少利润。
> 
>       输入的第一行是一个整数T(T&lt;=50)，表示一共有T组数据。
>       接下来的每组数据，第一行是一个整数N(1&lt;=N&lt;=100,000)，表示一共有N天。第二行是 N 个被空格分开的整数，表示每天该股票的价格。该股票每天的价格的绝对值均不会超过1,000,000。
> 
>       对于每组数据，输出一行。该行包含一个整数，表示阿福能够获得的最大的利润。

    #### 输入数据:

    3
    7
    5 14 -2 4 9 3 17
    6
    6 8 7 4 1 -2
    4
    18 9 5 2

    #### 输出数据:

    > 28
>       2
>       0

    题解如下

    <pre class="line-numbers prism-highlight" data-start="1">`#include &lt;bits/stdc++.h&gt;
    using namespace std;
    int value[1000005] = {0} ,pre[1000005] = {0}, fu[1000005] = {0};
    int main() {
        int t;
        cin &gt;&gt; t;
        for (int k = 0; k &lt; t; ++k) {
            int n;
            cin &gt;&gt; n;
            for (int i = 1; i &lt;= n; ++i) 
                scanf("%d", &amp;value[i]);
            int maxn = -2000000, minn = 2000000;
            // 从前到后 刷新最小值, 并且计算到当前的最大值
            for (int i = 1; i &lt;= n; ++i) {
                if(minn &gt; value[i]) minn = value[i];
                pre[i] = max(value[i] - minn, pre[i - 1]);
            }
            // 从后到前, 刷最大值, 并且计算当前位置选不选?
            for(int i = n; i &gt;= 1; --i) {
                if(maxn &lt; value[i]) maxn = value[i];
                fu[i] = max(maxn - value[i], fu[i + 1]);
            }
            int profit = 0;
            for(int i = 1; i &lt;= n; ++i) 
                profit = max(pre[i] + fu[i], profit);
            printf("%d\n", profit);
            memset(value, 0, sizeof(value));
            memset(pre, 0, sizeof(pre));
            memset(fu, 0, sizeof(fu));
        }
        return 0;
    }
    `</pre>

    要说难度, 这道题是一个基础难度的题（虽然对我这种菜鸡来说还是很费劲...
    总结一下关键

    <pre class="line-numbers prism-highlight" data-start="1">`// 从前到后 刷新最小值, 并且计算到当前的最大值
    for (int i = 1; i &lt;= n; ++i) {
        if(minn &gt; value[i]) minn = value[i];
        pre[i] = max(value[i] - minn, pre[i - 1]);
    }
    // 从后到前, 刷最大值, 并且计算当前位置选不选?
    for(int i = n; i &gt;= 1; --i) {
        if(maxn &lt; value[i]) maxn = value[i];
        fu[i] = max(maxn - value[i], fu[i + 1]);
    }
    `</pre>

    是不是觉得和某一种经典题型有点像...就是“合唱队形”那种
    大概就是吧
    所以也就不写细致了
    但是还有一个重点
    这道题的刷新maxn的值...
    这种是“从开始、从末尾”到当前的最大值, 顺应了股票买卖需要看时间的
    比如说最小值在第三个位置, 但是我当前买的在第二个位置...

    这里还可以总结出动态规划的一个比较重点的地方

    ### 重点

    （貌似说过了？
    动态规划有一种理解方式, 和背包问题一样
    当前可以存在选, 不选的两种
    选就是f[i] + ...
    不选就是f[i - 1];
    这个可能成为动态规划的一个关键性问题, 和那个编辑距离的方式一样

    > 2017/11/7 停课晚自习搞竞赛

    又有一点灵感了
    对于dp
    一切都是由上一个状态推算而来, 所以一般把问题分解然后想简单!!!想简单!!!
    但是首先要熟悉递推
    太简单了...就放一个递推题吧
    计算位数

    <pre class="line-numbers prism-highlight" data-start="1">`#include &lt;bits/stdc++.h&gt;
    using namespace std;
    int even[10001] = {0}, odd[10001] = {0};
    int main() {
        int n, x = 9;
        cin &gt;&gt; n;
        even[1] = 9;
        odd[1] = 1;
        for(int i = 2; i &lt;= n; ++i) {
            if(i == n) x = 8;
            even[i] = (even[i - 1] * x + odd[i - 1]) % 12345;
            odd[i] = (even[i - 1] + odd[i - 1] * 9) % 12345;
        }
        cout &lt;&lt; even[n];
        return 0;
    }

放在这就对了 貌似也没啥难度（可是我还是没懂
以后写吧
// # TODO
累死啦！
休息休息