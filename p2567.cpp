#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int unsigned long long
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
int l, r, n, tot, num, a[maxn], b[maxn], t, vis[maxn], ans;
void pre(int x,int y){
	if(x > t || y > r) return;
	if(x > 0) a[++tot]=y;
	pre(x+1,y*10+6);
	pre(x+1,y*10+8);
}
int gcd(int x, int y){return (!y)?x:gcd(y,x%y);}
void dfs(int x, int cnt, int lcm){
    if(x > n){
        if(cnt&1) ans += r/lcm - (l-1)/lcm;
        else if(cnt) ans -= r/lcm - (l-1)/lcm;
        return;
    }
    dfs(x+1, cnt, lcm);
    lcm = lcm / gcd(b[x], lcm) * b[x];
    if(lcm <= r) dfs(x+1, cnt+1, lcm);
}
signed main(){
    read(l); read(r);
    t=(int)(log(r)/log(10))+1;
    pre(0, 0);
    sort(a+1, a+tot+1);
    for(int i=1; i<=tot; i++){
        if(!vis[i]){
            b[++n] = a[i];
            for(int j=i+1; j<=tot; j++) if(!(a[i]%a[j])) vis[j] = 1;
        }
    }
    reverse(b+1, b+1+n);
    dfs(1, 0, 1);
    printf("%lld", ans);
    return 0;
}
