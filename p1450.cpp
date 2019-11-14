#include<cstdio>
#include<cstdlib>
#include<iostream>
#define int long long
const int maxn = 1e5+10, maxs = 1e5+10;
using namespace std;
int c[4], t, f[maxn], s, d[5];
signed main(){
    f[0] = 1;
    for(int i=1; i<=4; i++) scanf("%lld", &c[i]);
    scanf("%lld", &t);
    for(int p=1; p<=4; p++){
        for(int i=c[p]; i<=maxs; i++) f[i] += f[i-c[p]];
    }
    while(t--){
        scanf("%lld%lld%lld%lld%lld", &d[1], &d[2], &d[3], &d[4], &s);
        int ans = f[s];
        printf("ha%lld\n", ans);
        for(int S=15; S; S=(S-1)&15){
            int ts = S, p = 0, tmp = 0;
            for(int i=1; i<=4; i++){
                if((ts >> (i-1))&1) p ^= 1, tmp += c[i]*(d[i]+1);
            }
            if(s >= tmp) ans = p ? ans - f[s-tmp] : ans + f[s-tmp];
        }
        printf("%lld\n", ans);
    }
}