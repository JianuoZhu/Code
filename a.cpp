#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
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
int t, n, a[maxn];
signed main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int max1 = -inf, max2 = -inf;
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            if(a[i] >= max1) max2 = max1, max1 = a[i];
            else if(a[i] > max2) max2 = a[i];
        }
        printf("%d\n", mmin(max2-1, n-2));
    }
    return 0;
}
