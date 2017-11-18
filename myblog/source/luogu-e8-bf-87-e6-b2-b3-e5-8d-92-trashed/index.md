---
title: luogu_过河卒
id: 139
comment: false
date: 2017-10-28 10:27:17
---

[过河卒](https://www.luogu.org/problem/show?pid=1002)

    #include &lt;iostream&gt;
    #include &lt;cstring&gt;
    #include &lt;cstdio&gt;
    using namespace std;
    struct point {
        int x;
        int y;
    };
    const int go[2][2] = {{-1, 0}, {0, -1}};
    const int go_h[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    long long memo[23][23];
    bool gcan[23][23];
    bool horse[23][23];
    point p[10000];
    int main() {
        memset(gcan, false, sizeof(gcan));
        memset(horse, false, sizeof(gcan));
        memset(memo, 0, sizeof(memo));
        int posibx, posiby;
        int hposix, hposiy;
        cin &gt;&gt; posibx &gt;&gt; posiby &gt;&gt; hposix &gt;&gt; hposiy;
        ++posibx, ++posiby, ++hposix, ++hposiy;
        horse[hposix][hposiy] = true;
        for(int i = 0; i &lt; 8; ++i)  {
            int gox = hposix + go_h[i][0];
            int goy = hposiy + go_h[i][1];
            if(gox &lt; 1 || goy &lt; 1 || gox &gt; posibx || goy &gt; posiby) continue;
            horse[gox][goy] = true;
        }
        gcan[1][1] = true;
        memo[1][1] = 1;
        for(int i = 1; i &lt;= posibx; ++i) {
            for(int j = 1; j &lt;= posiby; ++j) {
                if(!horse[i][j]) {
                    for(int k = 0; k &lt; 2; ++k) {
                        if(gcan[i + go[k][0]][j + go[k][1]] &amp;&amp; !horse[i + go[k][0]][j + go[k][1]]) {
                                memo[i][j] += memo[i + go[k][0]][j + go[k][1]];
                                gcan[i][j] = true;
                        }
                    }
                }   
            }
        } 
        cout &lt;&lt; memo[posibx][posiby];
    }
    