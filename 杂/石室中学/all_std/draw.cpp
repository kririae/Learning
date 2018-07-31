<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
ï»¿<title>æˆéƒ½çŸ³å®¤ä¸­å­¦ä¿¡æ¯å­¦å¥¥èµ›</title>
</head>
<body background='background.jpg'>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 1000000+5
using namespace std;
//¶ş·ÖÑéÖ¤´ğ°¸
//ÓĞµÈÊ½(x1+x2)/(y1+y2)>=kµÃµ½
//x1+x2>=k(y1+y2)  ---->    ky1-x1+ky2-x2>=0
//Éè b(n) = kyn-xn µÃµ½Ê¹ (x1+x2)/(y1+y2) ×î´óÊ± Ã¿Ò»Ïîb(n)×î´óÊ±×îÓÅ
//ÓÃÀ´ÑéÖ¤¶ş·Ö´ğ°¸ 
int z[MAXN],k,m[MAXN],n;
double f[MAXN];
bool check(double v){
	for(int i=1;i<=n;i++){
		f[i]=v*m[i]-z[i];
	}
	sort(f+1,f+1+n);
	double sum=0;
	for(int i=1;i<=k;i++){
		sum+=f[i];
	}
	return sum<=0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&m[i],&z[i]);
	}
	double l=0,r=MAXN;
	for(int i=1;i<=50;i++){
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.2lf\n",r);
	return 0;
}
<script language='javascript'>document.location='index.php'</script>
<center>
<p><FONT size=2>
æˆéƒ½çŸ³å®¤ä¸­å­¦ä¿¡æ¯å­¦å¥¥æ—åŒ¹å…‹<br>
ç‰ˆä¸»ä¿¡ç®±ï¼šph89026433@126.com&nbsp;&nbsp;èœ€ICPå¤‡05008618å·<br>
</font></p>
</center>
</body>
</html>
   
