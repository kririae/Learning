title: 「TEST」石室考试
author: kririae
tags:
  - hash
  - dp
categories:
  - oi
date: 2018-03-14 09:25:00
---
# cdshishi省选前考试 

<!--more-->

## D1   
### D1T1 contest   
应该是对每一个队伍排序，然后树状数组对另外两队求逆序对   
然而我已经记不到逆序对怎么写了...
### D1T2 river   
物理题？？？是不是文老rand错题了，而且为啥全都WA？？？是不是被卡精度了   
woc   
在游完的前提下走的最多...   
想简单了   
正解求导，放弃吧   
[Qizy的题解](https://oi.qizy.tech/?p=281)
### D1T3 alliances 
[Qizy的题解](https://oi.qizy.tech/?p=320)   
无思路
## D2   
### D2T1 matrix   
矩阵的hash，大概就是$O(n^2log^2{n})$枚举左上角的顶点，然后倍增正方形的大小，可以过   
### D2T2 tree   
dp题   
dp[i][j]是i染j种颜色的方案数   
$$dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (k - j + 1)$$   
### D2T3 cyclic   
一看是shy的题...   
先不说这个，一看是最小表示法，然而...   
emmmmmmmm...
我又想到蚯蚓那道题了...然而没用   
$O(n^2)$肯定过不了5w...放弃了...  
那么就放弃吧！
[Qizy的题解](https://oi.qizy.tech/?p=298)
## D3 USACO水题
神级大水题，开心就好   
USACO DEC13   
### D3T1 blackholes
不是那个分层图的虫洞，鉴于12的数据范围，枚举子集然后计算就好   
### D3T2 namerecord
排序后对字符串进行hash，hash模板题   
### D3T3 牛棒球
n^2枚举，然后线段树维护判断   
有一个更快的算法，利用队列   
枚举两个点，然后计算出第三个点的区间，然后排序   
这样可以用队列维护然后快速解决，懒得争这个rk1了。

## D4 UESTC PRETEST
### D4T1 alpha
prufer编码+dp，全班gg
### D4T2 beta
深搜or贪心，深搜把树的节点从到处第三层展开，贪心贪前面全部然后暴力后三个，其实是一样的。
### D4T3 gamma
并不知道正解，貌似是质数排序后用$\sqrt{n}$来划分然后暴力...拿了50
之前做过的“prime”，貌似思路一模一样orzzzzz
但是考试的时候想起了prime，但是写不来了orzzzzzzzzzzzzzzzzz...
总之啊。明天的正式比赛加油