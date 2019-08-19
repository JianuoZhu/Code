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
int l1, l2, nxt[maxn];
char s1[maxn], s2[maxn];
void get_nxt(){
    int k = 0;
    for(int i=2; i<=l2; i++){
        while(k && s2[i] != s2[k+1]) k = nxt[k];
        if(s2[i] == s2[k+1]) k++;
        nxt[i] = k;
    }
}
signed main(){
    scanf("%s%s", s1+1, s2+1);
    l1 = strlen(s1+1); l2 = strlen(s2+1);
    get_nxt();
    int j = 0;
    for(int i=1; i<=l1; i++){
        while(j && s1[i] != s2[j+1]) j = nxt[j];
        if(s1[i] == s2[j+1]) j++;
        if(j == l2) printf("%lld\n", i-j+1);
    }
    for(int i=1; i<=l2; i++) printf("%lld ", nxt[i]);
    return 0;
}
