#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 1e3+10;
inline int mmax(int a, int b){return a>b?a:b;}
inline int mmin(int a, int b){return a<b?a:b;}
inline int aabs(int a){return a>0?a:-a;}
inline void read(int &x){
     x = 0; char c = getchar(); int w = 1;
     while(c < '0' || c > '9'){if(c == '-') w = -1; c = getchar();}
     while(c >= '0' && c <= '9') x = x*10+c-'0', c = getchar();
     x *= w;
}
struct node{
    int pos, val;
    friend bool operator <(node a, node b){
        return a.val > b.val;
    }
};
using namespace std;
set<node> st[maxn];
int n, map[maxn][maxn], book[maxn][maxn];
signed main(){
    printf("1\n");
    read(n);
    for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) read(map[i][j]), map[j][i] = map[i][j];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) st[i].insert(node{j, map[i][j]});
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        set<node>::iterator it = st[i].begin();
        it++;
        ans = mmax(ans, (*it).val);
    }
    printf("%lld", ans);
    return 0;
}
