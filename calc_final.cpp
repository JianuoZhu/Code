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
    printf("           �򵥼�����              \n");
	printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n");
	printf("          1-��������\n");
	printf("          2-�����Է�����\n");
	printf("          3-�˳�\n");
	printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n");
    printf("��ѡ��(����1~3��һ������):");
    Handle();
    return 0;
}
void Handle(){ //��������
    int opt;
    scanf("%d", &opt);
    if(opt == 1) calc();
    else if(opt == 2) e_1();
    else if(opt == 3) exit(0);
    else printf("������1~4��һ������:"), Handle();
}
void calc(){//������ʽ
    getchar();
    printf("������һ��ֻ����+-*/�����ŵı��ʽ������#��β(ע�⣺������Ӣ���ַ�)\n");
    printf("����12*(23+34)/2-3#\n");
    printf("�����룺");
    double ans = Calc();
    printf("��Ϊ:");
    cout << ans;
    printf("\n��л����ʹ��!");
}
int prio(char c){//�趨�������ȼ�
	int pri;
    if(c == '+' || c == '-') pri = 1;
    if(c == '*' || c == '/') pri = 2;
    if(c == ')') pri = 3;
    if(c == '(') pri = -1;
    if(c == '#') pri = 0;
    return pri;
}
double cal(double a, char c, double b){//����a��b�����Ľ��
	if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
    return 0;
}
double Calc(){ //���ʽ����
	op.push('#');
	int flag = 0, fflag = 0;
	char c = getchar();
	while (c != '#' || op.top() != '#'){
		if(isdigit(c)){
            if(fflag){ //����С��
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
void e_1(){ //�ⷽ����
    printf("������Ҫ�⼸Ԫ�ķ������أ�\n������һ��С��100��������");
    int n;
    scanf("%d", &n);
    printf("����������ÿ�����̵�δ֪����ϵ���Լ���ʽ�ұߵ�ֵ\n");
    printf("�������������Ԫ�����飺\n");
    printf("x+y+z=3\n2x+y+z=4\nx+y=2\n");
    printf("����Ҫ����:\n1 1 1 3\n2 1 1 4\n1 1 0 2\n");
    printf("�����룺");
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
            printf("�޽�\n");
            exit(0);
        }
        for (int j=i+1; j<=n; j++) eq[i][j] /= eq[i][i];
        for (int j=0; j<n; j++)
            if (i != j)
                for (int k=i+1; k<=n; k++) eq[j][k] -= eq[j][i]*eq[i][k];
    }
    printf("������Ľ�����Ϊ��");
    for(int i=0; i<n; i++) cout << eq[i][n] << " ";
    printf("\n��л����ʹ�ã�");
}