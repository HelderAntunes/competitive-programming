#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
   // freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ll n, n2;
    cin >> n;
    n2 = n * n;

    if (n <= 2) {
        cout << -1 << endl;
    }
    else if (n % 2 == 1) {
        ll ind = (n2 - 3) / 2 + 1 * 1LL;
        cout << ind << " " << (ll)(ind + 1LL) << endl;
    }
    else {
        ll aux = n2 / 2 - 1;
        ll aux2 = aux + 2;
        ll ind = (aux - 3) / 2 + 1 * 1LL;
        cout << (ll)ind << " " << (ll)(ind + 2) << endl;
    }
    return 0;
}