#include<bits/stdc++.h>
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

signed main(){
    srand(time(0));
    int n = 100000, m  = 100000;
    printf("%lld %lld\n", n, m);
    for(int i=1; i<=n; i++) printf("%d ", rand());
    printf("\n");
    for(int i=1; i<=m; i++){
        int opt = rand()%2;
        printf("%d ", opt+1);
        int l = ((rand()*rand())%n)+1, r = ((rand()*rand())%n), k;
        if(l > r) swap(l, r);
        if(!opt){
            k = rand()%3000; printf("%lld %lld %lld\n", l, r, k);
        }
        else printf("%lld %lld\n", l, r);
    }
    return 0;
}
