/*
这题有点黑
直接开空间开不下
而且还带空格
MLE

所以：
“400W的int或者指针会MLE，但是神奇的是400W的char不会MLE。
所以可以储存所有字符，然后压缩路径的Trie TAT”
什么叫压缩路径——一个叶节点储存多个字符

“yanba @ 2015-03-10 21:57:53 [ Quote ] [ Edit ] [ Delete ] 3#
hash过了。”
hash黑科技。。。。。 

但是我一hash就WA。。。
不怕，多重hash 
hash值不能比mod大 
右WA 
好吧现在要严格概率分析了 
一共可以有10^7组hash值
所以数组一定要大于10^7 
根据概率论实际上大于sqrt（n）就会有重复 
所以由于空间问题不能开双hash 
我投子 
*/
#include<cstdio>
#define LL unsigned int
using namespace std;
const LL P=3001,mod=25000007;
LL hash[25000009];
char word[20005];
int read(char *w){
    int p=0;char c=getchar();
    while(c=='\n'||c=='\r') c=getchar();
    while(c!='\n'&&c!='\r') w[p++]=c,c=getchar();
    return p;
}
int n;
LL maxn=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m=read(word);
        for(int i=0,ha=1;i<m;i++){
            ha=ha*P+word[i];
            ha%=mod;
            hash[ha]+=i+1;
            maxn=maxn<hash[ha]? hash[ha]:maxn;
        }
    }
    printf("%d",maxn);
    return 0;
} 
