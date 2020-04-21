#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
const int maxn = 1e5+10;
const double EPS=1E-8;
inline int mmax(int a, int b){return a>b?a:b;}
inline int mmin(int a, int b){return a<b?a:b;}
inline int aabs(int a){return a>0?a:-a;}
inline void read(int &x){
     x = 0; char c = getchar(); int w = 1;
     while(c < '0' || c > '9'){if(c == '-') w = -1; c = getchar();}
     while(c >= '0' && c <= '9') x = x*10+c-'0', c = getchar();
     x *= w;
}

using namespace std;
stack<char> op;
stack<double> num;
double eq[110][110];
int prio(char c);
double cal(double a, double b);
double Calc();
void calc();
void e_1();
void Handle();
signed main(){
    printf("欢迎使用本计算器！请选择你要进行的操作：\n");
    printf("1.四则运算\n2.解线性方程组\n3.退出\n");
    printf("请选择(输入1~3的一个数字):");
    Handle();
    return 0;
}
void Handle(){
    int opt;
    scanf("%d", &opt);
    if(opt == 1) calc();
    else if(opt == 2) e_1();
    else if(opt == 3) exit(0);
    else printf("请输入1~4的一个数字:"), Handle();
}
void calc(){
    getchar();
    printf("请输入一个只含有+-*/和括号的表达式，并以#结尾\n");
    printf("例：12*(23+34)/2-3#\n");
    printf("请输入：");
    double ans = Calc();
    printf("答案为：%lf\n感谢您的使用!", ans);
}
int prio(char c){
	int pri;
    if(c == '+' || c == '-') pri = 1;
    if(c == '*' || c == '/') pri = 2;
    if(c == '(' || c == ')') pri = 3;
    if(c == '#') pri = 0;
    return pri;
}
double cal(double a, char c, double b){
	if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
}
double Calc(){
	op.push('#');
	int flag = 0;
	char c = getchar();
	while (c != '#' || op.top() != '#'){
		if(isdigit(c)){
			if (flag == 1){
				double t = num.top(); num.pop();
				num.push(t * 10 + (c - '0'));
				flag = 1;
			}
			else{
				num.push(c - '0');
				flag++;
			}
			c = getchar();
		}
		else{
			flag = 0; int p1 = prio(op.top()), p2 = prio(c);
			if((c == '(' && op.top() == ')') || (c == op.top() && c == '#')){
				op.pop();
				c = getchar();
            }
            else if(p1 <= p2){
                op.push(c);
				c = getchar();
            }
			else if(p1 > p2){
				char t = op.top(); op.pop();
				double a = num.top(); num.pop();
				double b = num.top(); num.pop();
				num.push(cal(b, t, a));
			}
		}
	}
	return num.top();
}
void e_1(){
    printf("请问您要解几元的方程组呢？\n请输入一个小于100的整数：");
    int n;
    scanf("%d", &n);
    printf("请依次输入每个方程的未知数的系数以及等式右边的值\n");
    printf("例如下面这个三元方程组：\n");
    printf("x+y+z=3\n2x+y+z=4\nx+y=2\n");
    printf("你需要输入:\n1 1 1 3\n2 1 1 4\n1 1 0 2\n");
    printf("请输入：");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            scanf("%lf", &eq[i][j]);
        scanf("%lf", &eq[i][n]);
    }
    for (int i=0; i<n; i++){
        int ti=i;
        for (int j=i; j<n; j++)
            if (fabs(eq[j][i]-eq[ti][i]) <= EPS) ti=j;
        for (int j=0; j<=n; j++){
            double t=eq[i][j];
            eq[i][j]=eq[ti][j];
            eq[ti][j]=t;
        }
        if (fabs(eq[i][i])<=EPS){
            printf("无解\n");
            exit(0);
        }
        for (int j=i+1; j<=n; j++) eq[i][j] /= eq[i][i];
        for (int j=0; j<n; j++)
            if (i != j)
                for (int k=i+1; k<=n; k++) eq[j][k] -= eq[j][i]*eq[i][k];
    }
    printf("方程的解依次为：");
    for(int i=0; i<n; i++) cout << eq[i][n] << " ";
    printf("\n感谢您的使用！");
}
