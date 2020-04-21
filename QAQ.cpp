
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<stack>
using namespace std;
 
stack<char> op;
stack<double> num;
 
int prio(char c){
	int pri;
    if(c == '+' || c == '-') pri = 1;
    if(c == '*' || c == '/') pri = 2;
    if(c == '(' || c == ')') pri = 3;
    if(c == '#') pri = 0;
    return pri;
}
 
double calc(double a, char c, double b){
	if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
}
 
double getAnswer(){
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
			flag = 0; int p1 = prio(op.top()), p2 = prio(c);//flag置零
			if((c == '(' && op.top() == ')') || (c == op.top() && c == '#')){         //=将op栈顶元素弹出，用于括号的处理
				op.pop();
				c = getchar();
            }
            else if(p1 <= p2){
                op.push(c);
				c = getchar();
            }
			else if(p1 > p2){
				char t = op.top();
				op.pop();
				double a = num.top();
				num.pop();
				double b = num.top();
				num.pop();
				num.push(calc(b, t, a));
			}
		}
	}
	return num.top();
}
 
int main()
{
	while (!op.empty()) op.pop();
	while (!num.empty()) num.pop();
	double ans = getAnswer();
	cout << ans << endl<< endl;
	getchar();
	return 0;
}