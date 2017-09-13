#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll countD(ll n) {
    ll res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ll n, s;
    cin >> n >> s;

    ll l = 1, r = n, m, sumD;
    while (l < r) {
        m = (l + r) / 2;
        sumD = countD(m);
        //cout << l << " " << r << " " << m << " " << sumD << endl;
        if (m - sumD - s >= 0) {
            r = m;
        }
        else {
            l = m+1;
        }
    }

    if (l - countD(l) - s >= 0) {
        cout << n-l+1 << endl;
    }
    else {
        cout << n-l << endl;
    }
    return 0;
}