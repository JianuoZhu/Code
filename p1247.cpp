#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
const int maxn = 5e5+10;
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
int n, a[maxn];
signed main(){
    read(n);
    for(int i=1; i<=n; i++) read(a[i]);
    int ans = 0;
    for(int i=1; i<=n; i++) ans ^= a[i];
    if(!ans){printf("lose");exit(0);}
    for(int i=1; i<=n; i++){
        if((a[i]^ans) < a[i]){
            printf("%d %d\n", a[i] - (a[i]^ans), i);
            for(int j=1; j<i; j++) printf("%d ", a[j]);
            printf("%d ", a[i] - (a[i] - (a[i]^ans)));
            for(int j=i+1; j<=n; j++) printf("%d ", a[j]);
            exit(0);
        }
    }
    return 0;
}
