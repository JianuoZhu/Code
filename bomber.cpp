#include<iostream>
#include<cmath>
#include<cstdio>
const double inf = 1e9+7;
double squ(double a) {return a*a;}
double mmin(double a, double b){return a < b ? a : b;}
double ax, ay, px, py, sx, sy;
double mmin(int a, int b){return a<b?a:b;}
double f(double x){
	double k = (sy-ay)/(sx-ax); int b = ay-ax*k;
	double y = k*x+b;
	return sqrt(squ(x-ax)+squ(y-ay))/2+sqrt(squ(x-px)+squ(y-py));
}
int main(){
	//freopen("bomber.in", "r", stdin);
	//freopen("bomber.out", "w", stdout);
	std::cin >> ax >> ay >> px >> py >> sx >> sy;
	double ans = inf;
	if(ax <= sx){
		for(double i = ax; i<=sx; i+=0.0001){
			ans = mmin(ans, f(i));
		}
	}
	if(ax >  sx){
		for(double i = sx; i<=ax; i+=0.0001){
			ans = mmin(ans, f(i));
		}
	}
	printf("%.2lf", ans);
}
// Orz SYZ SZQ SBR YM!!
