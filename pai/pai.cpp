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
    for(int i=1; i<=1000; i++){
        system("maker.exe >in");
        system("a.exe <in >out1");
        system("b.exe <in >out2");
        if(system("fc out1 out2")){printf("GG!!\n"); break;}
        printf("Pass:%lld\n", i);
        _sleep(1000);
    }
    return 0;
}
