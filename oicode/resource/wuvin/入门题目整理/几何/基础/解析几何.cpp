#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
/*
解析几何开始 

*/
int dcmp(double &x){
	if(x<1e-10&&x>-(1e-10)) return 0;
	return (x<0)?-1:1; 
}


struct Point{
	double x,y;
	Point(double x1,double y1){
		x=x1;y=y1;
	}
	Point(){
		x=y=0;
	}
	
	Point operator + (Point b){
		return Point(x+b.x, y+b.y);
	}
	Point operator - (Point b){
		return Point(x-b.x,y-b.y);
	}
	Point operator * (double p){
		return Point(x*p,y*p);
	}
	Point operator / (double p){
		return Point(x/p,y/p);
	}
	
	double distan(const Point& b){
		return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
	}
};

struct Vector{
	double x,y;
	double lenth;
	Vector(){
		x=y=0;lenth=-1;
	}
	Vector(int x1,int y1){
		lenth=-1;
		x=x1;y=y1;
	}
	Vector(double x1,double y1){
		lenth=-1;
		x=x1;y=y1;
	}
	
	Point to_point(){
		return Point(x,y);
	}
	
	void Die(){
		delete(this);
	}
	
	Vector operator + (Vector b){
		return Vector(x+b.x, y+b.y);
	}
	Vector operator - (Vector b){
		return Vector(x-b.x,y-b.y);
	}
	Vector operator * (double p){
		return Vector(x*p,y*p);
	}
	Vector operator / (double p){
		return Vector(x/p,y/p);
	}
	
	bool operator <(const Vector &b)const{
		if(x==b.x){
			return y<b.y;
		}
		return x<b.x;
	}
	bool operator > (const Vector &b)const{
		if(x==b.x){
			return y>b.y;
		}
		return x>b.x;
	}
	bool operator ==(const Vector &b)const{
		if(x==b.x&&y==b.y) return true;
		return false;
	}
	
	double getlen(){
		if(lenth==-1){
			lenth=sqrt(x*x+y*y);
		}
		return lenth;
	}
	
	double dot(const Vector &b){//点乘 一四象限为正 
		return x*b.x+y*b.y;
	}
	
	double cross(const Vector &b){//有向面积的2倍  可用正弦求sin 一二象限为正 
		return x*b.y-y*b.x;
	}
	
	long double angle(const Vector &b){
		return acos(dot(b)/sqrt(x*b.x*x*b.x+x*x*b.y*b.y+y*y*b.x*b.x+y*y*b.y*b.y));
	}
	
	long double theta(){
		return atan2(y,x);
	}
	
	void rotate(double radix){
		y=y*cos(radix)+x*sin(radix);
		x=x*cos(radix)-y*sin(radix);
	}
	
	void normalize(){//单位化 
		getlen();
		x/=lenth;y/=lenth;
	}
	
	Vector normalized(){//返回单位向量 
		getlen();
		return Vector(x/lenth,y/lenth);
	}
}; 

/*
有向直线 
*/
struct Line{
	Point p;//起始点
	Vector v;//方向向量
	//两点确定直线 
	Line(double x1,double y1,double x2,double y2){
		p=Point(x1,y1);v=Vector(x2-x1,y2-y1);
	}
	Line(Point p1,Point p2){
		p=p1;v=Vector(p2.x-p1.x,p2.y-p1.y);
	}
	//起始点和方向向量 
	Line(double x0,double y0,Vector v0){
		p=Point(x0,y0);v=v0;
	}
	Line(Point &p0,Vector &v0):p(p0),v(v0){
		p=p0;v=v0;
	}
	
	
};
int main(){
	double x1,x2,y1,y2,r1,r2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	Point p1(x1,y1),p2(x2,y2);
	long double d=p1.distan(p2);
	if(d>=r1+r2){
		printf("0.000");
		return 0;
	}
	Line yx(p1,p2);
	
	return 0;
}
