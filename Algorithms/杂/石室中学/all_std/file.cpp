<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string name[55];
int n,st,sz,pos;
string now[7],th,emp="";

int main(){
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>name[i];
	for(int i=1;i<=n;i++) name[i]+="/";
	sort(name+1,name+n+1);
	for(int i=1;i<=n;i++) {
		int len=name[i].size();
		st=0;pos=1;
		for(int j=0;j<len;j++) {
			if(name[i][j]=='/') {
				sz=0;
				for(int p=st;p<j;p++) {
					th+=name[i][p];
				}
				if(th!=now[pos]) {
					if(pos==1) cout<<th<<endl;
					else {
						for(int i=2;i<pos;i++) cout<<"|    ";
						cout<<"|----"<<th<<endl;
					}
					now[pos]=th;
					for(int i=pos+1;i<6;i++) now[i]=emp;
				}
				st=j+1;th=emp;pos++;
			}
		}
	}
	return 0;
}

<script language='javascript'>document.location='index.php'</script>
<center>
<p><FONT size=2>
成都石室中学信息学奥林匹克<br>
版主信箱：ph89026433@126.com&nbsp;&nbsp;蜀ICP备05008618号<br>
</font></p>
</center>
</body>
</html>
   
