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
#define int long long
const int maxn = 3e5+10;
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
vector<int> g[maxn], _g[maxn];
queue<int> q;
int n, m, stack[maxn], dfn[maxn], low[maxn], ins[maxn];
int belong[maxn], sum[maxn], cnt, tot, top, dis[maxn];
bool vis[maxn];
void tarjan(int x){
    stack[++top] = x; ins[x] = true;
    dfn[x] = low[x] = ++cnt;
    for(int i=0; i<g[x].size(); i++){
        int v = g[x][i];
        if(!dfn[v]) tarjan(v), low[x] = mmin(low[x], low[v]);
        else if(ins[v]) low[x] = mmin(low[x], dfn[v]);
    }
    if(dfn[x] == low[x]){
        tot++;
        while(stack[top+1] != x){
            ins[stack[top]]=false;
            belong[stack[top]] = tot;
            sum[tot]++; top--;
        }
    }
}
signed main(){
    read(n); read(m);
    int u, v;
    for(int i=1; i<=m; i++){
        read(u); read(v);
        g[u].push_back(v);
    }
    for(int i=1; i<=n; i++) if(!dfn[i]) tarjan(i);
    for(int p=1; p<=n; p++) for(int i=0; i<g[p].size(); i++){
        if(belong[p] == belong[g[p][i]]) continue;
        _g[belong[p]].push_back(belong[g[p][i]]);
        _g[belong[g[p][i]]].push_back(belong[p]+tot);
        _g[belong[p]+tot].push_back(belong[g[p][i]]+tot);
    }
    for(int i=1; i<=tot; i++) sum[i+tot] = sum[i];
    q.push(belong[1]); vis[belong[1]] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        //printf("now u = %d\n", u);
        for(int i=0; i<_g[u].size(); i++){
            int v = _g[u][i];
            //printf("now v = %d\n", v);
            if(dis[v] < dis[u] + sum[u]){
                dis[v] = dis[u] + sum[u];
                if(!vis[v]) q.push(v), vis[v] = 1;
            }
        }
        vis[u] = 0;
    }
    printf("%lld", dis[belong[1]+tot]);
    return 0;
}
