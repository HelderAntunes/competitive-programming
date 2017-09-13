#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll MOD = 1000000007;
int n;
ll fac[200005], inv[200005];

// To compute x^y under modulo m
ll power(ll x, ll y, ll m) {
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

ll comb(int n, int k) {
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    scanf("%d", &n);
    vi a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i * fac[i-1] % MOD;
        inv[i] = power(fac[i], MOD-2, MOD);
    }

    if (n % 4 == 0) {
        int n_comb = (n - 2) / 2;
        int k_comb = 0;
        ll ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans = (ans + comb(n_comb, k_comb) * a[i] % MOD) % MOD;
            ans = (ans - comb(n_comb, k_comb) * a[i+1] % MOD + MOD) % MOD;
            k_comb++;
        }
        printf("%d\n", (ans+MOD)%MOD);
    }
    else if (n % 4 == 1) {
        int n_comb = (n - 1) / 2;
        int k_comb = 1;
        ll ans = comb(n_comb, 0) * a[0];
        for (int i = 1; i < n; i += 2) {
            ans = (ans + comb(n_comb, k_comb) * a[i+1] % MOD) % MOD;
            k_comb++;
        }
        printf("%d\n", (ans+MOD)%MOD);
    }
    else if (n % 4 == 2) {
        int n_comb = (n - 2) / 2;
        int k_comb = 0;
        ll ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans = (ans + comb(n_comb, k_comb) * a[i] % MOD) % MOD;
            ans = (ans + comb(n_comb, k_comb) * a[i+1] % MOD + MOD) % MOD;
            k_comb++;
        }
        printf("%d\n", (ans+MOD)%MOD);
    }
    else {
        int n_comb = (n - 3) / 2;
        int k_comb = 0;
        ll ans = comb(n_comb, k_comb) * a[0];
        for (int i = 1; i < n; i += 2) {
            ans = (ans + 2 * comb(n_comb, k_comb) * a[i] % MOD) % MOD;
            ans = (ans + (comb(n_comb, k_comb + 1) - comb(n_comb, k_comb) + MOD) % MOD * a[i+1] % MOD + MOD) % MOD;
            k_comb++;
        }
        printf("%d\n", (ans+MOD)%MOD);
    }

    return 0;
}