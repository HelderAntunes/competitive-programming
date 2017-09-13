#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll mod = 1000000007;

ll pow_mod(int a,int b,int c){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c;
        b /= 2;
    }
    return x%c;
}

// 2^0 + 2^1 + 2^2 + ... + 2^i-1
ll geometricSum2(int i) {
    ll num = (pow_mod(2, i, mod) - 1 + mod) % mod;
    return num;
}

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n;
    vi a;
    scanf("%d", &n);
    a.assign(n, 0);
    for (int i = 0;i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll val = a[i];
        if (i > 0) {
            ll pos = (val * geometricSum2(i))%mod;
            res = (res + pos)%mod;
        }
        if (i < n-1) {
            ll neg = (val * geometricSum2(n-1-i))%mod;
            res = (res - neg + mod)%mod;
        }
    }
    printf("%d", res);
    return 0;
}