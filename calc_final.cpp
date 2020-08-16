#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
const double EPS=1E-8;

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
    printf("           简单计算器              \n");
	printf("━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ \n");
	printf("          1-四则运算\n");
	printf("          2-解线性方程组\n");
	printf("          3-退出\n");
	printf("━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ \n");
    printf("请选择(输入1~3的一个数字):");
    Handle();
    return 0;
}
void Handle(){ //处理输入
    int opt;
    scanf("%d", &opt);
    if(opt == 1) calc();
    else if(opt == 2) e_1();
    else if(opt == 3) exit(0);
    else printf("请输入1~4的一个数字:"), Handle();
}
void calc(){//计算表达式
    getchar();
    printf("请输入一个只含有+-*/和括号的表达式，并以#结尾(注意：请输入英文字符)\n");
    printf("例：12*(23+34)/2-3#\n");
    printf("请输入：");
    double ans = Calc();
    printf("答案为:");
    cout << ans;
    printf("\n感谢您的使用!");
}
int prio(char c){//设定符号优先级
	int pri;
    if(c == '+' || c == '-') pri = 1;
    if(c == '*' || c == '/') pri = 2;
    if(c == ')') pri = 3;
    if(c == '(') pri = -1;
    if(c == '#') pri = 0;
    return pri;
}
double cal(double a, char c, double b){//返回a和b运算后的结果
	if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
    return 0;
}
double Calc(){ //表达式计算
	op.push('#');
	int flag = 0, fflag = 0;
	char c = getchar();
	while (c != '#' || op.top() != '#'){
		if(isdigit(c)){
            if(fflag){ //处理小数
                double t = num.top(); num.pop();
                num.push(t + pow(0.1, fflag)*(c-'0'));
                fflag++;
            }
			else if (flag == 1){
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
        else if(c == '.'){
            fflag = 1; c = getchar();
        }
		else{
			flag = 0; fflag = 0; int p1 = prio(op.top()), p2 = prio(c);
			if((c == ')' && op.top() == '(') || (c == op.top() && c == '#') || (c == ')' && op.top() == '#')){
				op.pop();
				c = getchar();
            }
			else if(c == '('){
				op.push(c); c = getchar();
			}
            else if(p1 < p2 && c != ')'){
                op.push(c);
				c = getchar();
            }
			else if(p1 >= p2 || c == ')'){
				char t = op.top(); op.pop();
				double a = num.top(); num.pop();
				double b = num.top(); num.pop();
				num.push(cal(b, t, a));
			}
		}
	}
	return num.top();
}
void e_1(){ //解方程组
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
    printf("方程组的解依次为：");
    for(int i=0; i<n; i++) cout << eq[i][n] << " ";
    printf("\n感谢您的使用！");
}