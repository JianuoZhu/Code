#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 1e6+10;
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
int n, a[maxn], b[maxn], f[maxn];
signed main(){
    read(n);
    for(int i=0; i<=800000; i++) f[i] = -inf;
    for(int i=1; i<=n; i++) read(a[i]), read(b[i]);
    f[400000] = 0;
    for(int i=1; i<=n; i++){
        if(a[i] < 0){
            for(int j=0; j<=a[i]+800000; j++){
                f[j] = mmax(f[j], f[j-a[i]]+b[i]);
            }
        }
        else if(a[i] >= 0){
            for(int j=800000; j>=a[i]; j--){
                f[j] = mmax(f[j], f[j-a[i]]+b[i]);
            }
        }
    }
    int ans = 0;
    for(int i=400000; i<=800000; i++) if(f[i] > 0) ans = mmax(ans, f[i]+i-400000);
    printf("%lld", ans);
    return 0;
}
