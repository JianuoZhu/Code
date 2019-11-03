#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
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
struct node{
    int pos, x, val;
    bool friend operator <(node a, node b){
        return a.val>b.val;
    }
};
int n, m, k;
int a[maxn][10];
priority_queue<node, vector<node> > q;
int qp(int a, int b)
{
	int ans=1, res=a;
	while(b){
		if(b&1) ans=ans*res;
		res=res*res;
		b>>=1;
	}
	return ans;
}
int solve(int p, int x){
    int ans = 0;
    for(int i=0; i<=k; i++) ans += a[p][i]*qp(x, i);
    return ans;
}
signed main(){
    read(n); read(m); read(k);
    for(int i=1; i<=m; i++)
        for(int j=0; j<=k; j++) read(a[i][j]);
    for(int i=1; i<=m; i++) q.push(node{i, 1, solve(i, 1)});
    node Orz_CZQ;
    for(int i=1; i<=n; i++){
        Orz_CZQ = q.top(); q.pop();
        q.push(node{Orz_CZQ.pos, Orz_CZQ.x+1, solve(Orz_CZQ.pos, Orz_CZQ.x+1)});
    }
    printf("%lld", Orz_CZQ.val);
    return 0;
}
