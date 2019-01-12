# 「Va-11 Hall-a」

## 「题目描述」

$Jill$是在$Vallhalla$工作的调酒师。为客人送上美味的饮料是她的工作内容。但$Jill$是个有创造力和上进心的女孩，她并不满足于仅为客人调制菜单上的饮料，她想自己去创造属于自己的饮料。虽说如此，她并不知道怎么去创造一种受客人欢迎的饮料，于是她想出了一个绝妙的办法。$Jill$将$n$瓶酒摆成一列，每瓶酒初始评价值都为$1$，然后有$m$次操作。每次操作$Jill$会在$[l,r]$内的酒中随机选择任意瓶每瓶加入一个评价值随机（不一定相同）的配料，并重复这个操作$k_i$次。由于原料和配料会发生剧烈的化学反应，所以混合之后评价值并不是相加 那么简单。据$Jill$观察，一瓶评价值为$a$酒在加入评价值为整数$b(0 \leq b < c)$，的配料后评价值会变为$a\cdot b \ mod \ c$。现在$Jill$想知道她最终调制出的酒的评价值的和期望是多少。

**一句话题意**：给你一个初始全为$1$的长度为$n$的序列，$m$次操作，每次操作重复$ki$次，对于$[l,r]$间的随机一些数$a$，再对每个数选择一个随机整数$b(0 \leq b < c)$，将这些数变成$a\cdot b \ mod \ c$。问最终所有数的和期望是多少。 为了方便保证精度，你需要输出答案对$10^9+7$取模后的结果。 提示：如果答案是$\frac{a}{b}$的形式，那么你需要输出$a \cdot b^{-1} \ mod \ (10^9 + 7)$的结果。由于费马小定理，你只需输出$a \cdot b^{10^9 + 5} \ mod \ (10^9 + 7)$就可以了。

## 「输入格式」
第一行三个正整数$n, m, c$接下来每行三个数$l_i, r_i, k_i$表示操作的区间和重复次数。
## 「输出格式」
 一行一个整数表示答案对$10^9+7$取模后的整数。
 
## 「样例输入」 
`3 1 3 1 2 1`
## 「样例输出」
`500000007`
## 「数据规模及约定」
 对于$30\%$的数据$n=10, m \leq 10, k_i \leq 10, c \leq 5$
 对于$100\%$的数据$n \leq 100, m \leq 1e6, k_i \leq 100, c \leq 50$

## 题解
由于期望的可加性，我们可以这么处理这道题。对于每个数，我们求出它最后为某一个数的期望，然后求和。因为它最后的值一定属于$[0, c)$。所以我们建立矩阵：
$$
\begin{bmatrix}
	p_0 \\
	p_1 \\
	p_2 \\
	\cdots \\
	p_{c - 1} \\
\end{bmatrix}
$$
$p_i$表示最后值为$i$的概率是。当然，现在的矩阵是初始的，我们考虑如何对这个矩阵进行转移。即转移到某一次操作后，某一个数变换成某一个数的概率是。转移矩阵的第$i$行第$j$列定义为，数值$i$变换到数值$j$的概率是。特别的，这个矩阵有第$0$行第$0$列。对于一次$[L, R]$的操作，选取到某个数的概率是$\frac{1}{2}$。而选取到这个数之后，进行的操作可能是乘上$[0, c)$中的任意一个数，乘这个数的概率就是$\frac{1}{c \cdot 2}$。所以我们在某个数$x$乘上$[0, c)$后的数$y$，$x \rightarrow y$之间的边加上概率$\frac{1}{c \cdot 2}$。

对于这道题的矩阵乘法，我们这么考虑：$a_{1, 2}$的意思是经过一次操作后，$1$变到$2$的概率，则在乘上原矩阵第二列之后，最后的变为$2$的概率自然加上了某个值，这个值是$1$变为$2$的概率。

按照套路，这个时候该进行矩阵快速幂了。但是，如果直接进行矩阵快速幂的话...我们看看复杂度：$O(nc^3log{km})$，$2.5 \cdot 10^8$有点玄乎啊。这个时候，考虑优化矩阵乘法。我们$n \times n$的矩阵乘法的复杂度是$O(n^3)$，如果是$n \times n$和$n \times 1$的矩阵乘法，不就是$O(n^2)$了。我们预处理出转移矩阵的$2^k$次方，复杂度是$O(n^3log{k})$，可以接受，然后，用预处理出的信息和$n \times 1$的矩阵一一结合，得出的就是最后的矩阵，然后对所有求和，得出期望。

$std$代码如下
```cpp
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long

int n,m,c,ans;
int num[105];

struct Matrix{
	int x[55][55];
	Matrix operator * (const Matrix &b) const {
        Matrix ret;
		memset(ret.x,0,sizeof(ret.x));
        for(int i=0;i<c;i++) 
            for(int j=0;j<c;j++)
                for(int k=0;k<c;k++) 
                    ret.x[i][k]=(ret.x[i][k]+(LL) x[i][j]*b.x[j][k])%MOD;
        return ret;
    }
}pw[35],st;
int now[55],t[55];

void Merge(int k) {
	memset(t,0,sizeof(t));
	for(int i=0;i<c;i++) 
		for(int j=0;j<c;j++) 
			t[i]=(t[i]+(LL) now[j]*pw[k].x[i][j])%MOD;
	for(int i=0;i<c;i++) now[i]=t[i];
}

int fpow(int a,int b) {
	LL t=a,ret=1;
	while(b) {
		if(b&1) ret=ret*t%MOD;
		b>>=1;t=t*t%MOD;
	}
	return ret;
}

int main() {
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	 
	scanf("%d%d%d",&n,&m,&c);
	for(int l,r,k,i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&k);
		num[r+1]-=k;num[l]+=k;
	}
	for(int i=1;i<=n;i++) num[i]+=num[i-1];
	LL rev_2=fpow(2,MOD-2),rev_c=fpow(c,MOD-2);
	for(int to,i=0;i<c;i++) {
		for(int j=0;j<c;j++) {
			to=i*j%c;
			st.x[i][to]=(st.x[i][to]+rev_2*rev_c)%MOD;
		}
		st.x[i][i]=(st.x[i][i]+rev_2)%MOD;
	}
	pw[0]=st;
	for(int i=1;i<=30;i++) pw[i]=pw[i-1]*pw[i-1];
	for(int i=1;i<=n;i++) {
		memset(now,0,sizeof(now));
		now[1]=1;
		for(int j=0;j<=30;j++) if(num[i]>>j&1) Merge(j);
		for(int j=0;j<c;j++) 
			ans=(ans+(LL)now[j]*j)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}
```