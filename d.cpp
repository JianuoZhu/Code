#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e15+7
#define int long long
const int maxn = 3e5+10;
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
int n, m, k;
int f[maxn][11], a[maxn];
signed main(){
    read(n); read(m); read(k);
    for(int i=1; i<=n; i++) read(a[i]);
    for(int i=0; i<=n; i++) for(int j=0; j<=10; j++) f[i][j] = -inf;
    for(int i=0; i<=n; i++) f[i][10] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j != 1) f[i][j] = f[i-1][j-1] + a[i];
            else f[i][j] = max(f[i-1][m] - k + a[i], a[i] - k);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ans = mmax(ans, f[i][j]);
        }
    }
    printf("%I64d", ans);
    return 0;
}
