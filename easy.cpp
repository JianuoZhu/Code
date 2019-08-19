#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
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
struct node{
    int idx, val;
    friend bool operator <(node a, node b){
        return a.val > b.val;
    }
}nd[maxn];
using namespace std;
vector<int> e[maxn];
priority_queue<node> q;
int n, fa[maxn], stack[maxn];
signed main(){
	//freopen("easy.in", "r", stdin);
	//freopen("easy.out", "w", stdout);
    scanf("%d", &n);
    for(int i=2; i<=n; i++) {scanf("%d", &fa[i]); e[fa[i]].push_back(i);}
    for(int i=1; i<=n; i++) {nd[i].idx = i; read(nd[i].val);}
    int top = 0;
	q.push(nd[1]);
    while(!q.empty()){
        node x = q.top(); q.pop();
        stack[++top] = x.idx;
        for(int i=0; i<e[x.idx].size(); i++) q.push(nd[e[x.idx][i]]);
    }
    for(int i=top; i>=1; i--){
        printf("%d ", stack[i]);
    }
    return 0;
}
