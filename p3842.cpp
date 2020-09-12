#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 2e4+10;
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
int n, f[maxn][2], l[maxn], r[maxn];
signed main(){
    read(n);
    for(int i=1; i<=n; i++) read(l[i]), read(r[i]);
    //for(int i=1; i=n; i++) f[i][0] = f[i][1] = inf;
    f[1][1] = r[1]-1; f[1][0] = f[1][1]+(r[1]-l[1]);
    for(int i=2; i<=n; i++){
        f[i][0] = f[i-1][0]+(aabs(l[i-1]-r[i])+1)+(r[i]-l[i]);
        f[i][0] = mmin(f[i-1][1]+(aabs(r[i-1]-r[i])+1)+(r[i]-l[i]), f[i][0]);
        f[i][1] = f[i-1][0]+(aabs(l[i-1]-l[i])+1)+(r[i]-l[i]);
        f[i][1] = mmin(f[i-1][1]+(aabs(r[i-1]-l[i])+1)+(r[i]-l[i]), f[i][1]);
    }
//  for(int i=1; i<=n; i++) printf("f[%lld][0]=%lld, f[%lld][1]=%lld\n", i, f[i][0], i, f[i][1]);
    printf("%lld", mmin(f[n][0]+(n-l[n]), f[n][1]+(n-r[n])));
    return 0;
}
