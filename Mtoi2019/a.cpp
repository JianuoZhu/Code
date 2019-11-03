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
int n, m, k, a[maxn], book[maxn];
signed main(){
    cin >> n >> m >> k;
    for(int i=1; i<=k; i++) read(a[i]), book[a[i]]=1;
    int ans = 0, i=0;
    while(i < n){
        ++ans; i += m;
        if(book[i]) m++;
    }
    printf("%d", ans);
    return 0;
}
