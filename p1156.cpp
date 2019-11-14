#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 2e3+10;
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
struct trash{
    int t, f, h;
}a[maxn];
int h, n, f[maxn][maxn];
bool cmp(trash x, trash y){return x.t < y.t;}
signed main(){
    read(h); read(n);
    for(int i=1; i<=n; i++){
        read(a[i].t); read(a[i].f); read(a[i].h);
    }
    sort(a+1, a+1+n, cmp);
    for(int i=0; i<=2000; i++) f[i] = -inf;
    for(int i=0; i<=n; i++)f[i][0] = 10;
    for(int i=1; i<=n; i++){
        for(int _h=0; _h<=h; _h++){
            if(f[i-1][_h] >= a[i].t) f[i][_h] = mmax(f[i][_h], f[i-1][_h]+a[i].f);
            
        } 
    }
    int ans = 10;
    for(int i=1; i<=n; i++) ans += a[i].f; 
    printf("%lld", ans);
    return 0;
}
