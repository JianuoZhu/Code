#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 1e5+10;
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
int n, L, c[maxn], sum[maxn];
double a[maxn], b[maxn], dp[maxn];
int q[maxn];
double X(int x){return (double)b[x];}
double Y(int x){return (double)dp[x]+b[x]*b[x];}
double slope(int x, int y){return (Y(x)-Y(y))/(X(x)-X(y));}
signed main(){
    read(n); read(L);
    for(int i=1; i<=n; i++){
        read(sum[i]); sum[i] += sum[i-1];
    }
    for(int i=1; i<=n; i++) {a[i] = sum[i]+i; b[i] = a[i]+L+1;}
    int h = 1, t = 1;
    for(int i=1; i<=n; i++){
        while(h<t && slope(q[h], q[h+1]) < 2*a[i]) h++;
        dp[i] = dp[q[h]] + (a[i]-b[q[h]])*(a[i]-b[q[h]]);
        while(h<t && slope(i, q[t-1]) < slope(q[t-1], q[t])) --t;
        q[++t] = i;
    }
    printf("%.0lf", dp[n]);
    return 0;
}
