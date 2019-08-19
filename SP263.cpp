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
int T, TT, len, nxt[maxn];
char s[maxn];
void get_nxt(){
    int k = 0;
    for(int i=2; i<=len; i++){
        if(k && s[i] != s[k+1]) k = nxt[k];
        if(s[i] == s[k+1]) k++;
        nxt[i] = k;
    }
}
signed main(){
    read(TT); T = TT;
    while(T--){
        printf("Test case #%lld\n", TT-T);
        memset(s, '\0', sizeof(s));
        read(len);
        scanf("%s", s+1);
        get_nxt();
        for(int i=1; i<=len; i++){
            if(i/(i-nxt[i])>1 && !(i%(i-nxt[i]))) printf("%lld %lld\n", i, i/(i-nxt[i]));
        }
        printf("\n");
    }
    return 0;
}
