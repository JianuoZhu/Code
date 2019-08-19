#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
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
int n, k, a[maxn], b[maxn];
signed main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=2; i<=n; i++) b[i] = a[i] - a[i-1];
    sort(b+2, b+1+n);
    int tot = a[n]-a[1], m = n;
    for(int i=k-1; i; i--){
        tot -= b[m]; m--;
    }
    printf("%I64d", tot);
    return 0;
}
