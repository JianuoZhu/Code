#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
const int maxn = 2e5+10;
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
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    int point = n, flag = 0;
    for(int i=2; i<=n; i++) if(a[i-1] >= a[i]) {point = i; break;}
    if(point == n) {printf("YES"); exit(0); }
    for(int i=point+1; i<=n; i++) if(a[i] >= a[i-1]) flag = 1;
    if(flag == 0) printf("YES");
    else printf("NO");
    return 0;
}
