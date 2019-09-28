#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
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
const int mx = 1000001;
bool n_p[mx+10], book[mx+10];
int sum[mx+10];
vector<int> primes;
signed main(){
    for(int i=5; i<=mx; i+=4){
        if(n_p[i]) continue;
        primes.push_back(i);
        for(int j=5; j*i<=mx; j+=4) n_p[i*j] = true;
    }
    for(int i=0; i<primes.size(); i++){
        for(int j=0; j<primes.size(); j++){
            if(primes[i]*primes[j] > mx) break;
            book[primes[i]*primes[j]] = 1;
        }
    }
    //printf("book[25] = %d\n", book[25]);
    for(int i=1; i<=mx; i++)
        sum[i] = sum[i-1] + book[i];
    //printf("sum[85] = %d\n", sum[85]);
    while(1){
        int k; read(k); if(k == 0) break;
        printf("%lld %lld\n", k, sum[k]);
    }
    return 0;
}
