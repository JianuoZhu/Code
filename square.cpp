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
int key[8] = {0, 20031223, 19260817, 10000007, 19930219, 19990303, 19990213, 18670313}, len;
char s[maxn];
bool book[8][20200000];
bool check(int x){
    int k=0;
    for(int i=1; i<=len; i++){
        k = (k*10 + s[i] - '0') % key[x];
    }
    return book[x][k];
}
signed main(){
    int T;
    read(T);
    for(int i=1; i<=7; i++){
        for(int j=1; j<=key[i]/10; j++) 
            book[i][(j*j)%key[i]] = 1;
    }
    while(T--){
        scanf("%s", s+1);
        len = strlen(s+1);
        bool flag = 1;
        for(int i=1; i<=7; i++) flag &= check(i);
        printf("%d\n", flag);
    }
    return 0;
}
