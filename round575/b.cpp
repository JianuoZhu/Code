#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 2e5+10;
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
int q, n, k, a[maxn], b[maxn];
signed main(){
    read(q);
    while(q--){
        read(n); read(k);
        memset(b, 0, sizeof(b));
        int cnt = 0;
        for(int i=1; i<=n; i++){
            read(a[i]);
            if(a[i]%2) b[i] = 1, cnt++;
        }
        if(cnt < k || (cnt%2)!=(k%2)) printf("NO\n");
        else{
            printf("YES\n");
            int d = cnt-k;
            int _cnt = 0, i;
            if(k == cnt){
                for(int i=1; i<=n; i++){
                    if(b[i]){printf("%d ", i), _cnt++;}
                    if(_cnt == cnt-1) break;
                }
                printf("%d\n", n);
            }
            else{
                for(i=1; i<=n; i++){
                    if(b[i]) _cnt++;
                    if(_cnt == d){i++; break;}
                }
                for(; i<=n; i++){
                    if(b[i]){printf("%d ", i); _cnt++;}
                    if(_cnt == cnt-1) break;
                }
                printf("%d\n", n);
            }
            
        }
    }
    return 0;
}
