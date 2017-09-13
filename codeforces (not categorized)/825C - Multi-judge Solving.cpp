#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int canSolve = k * 2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= canSolve) {
            canSolve = max(canSolve, a[i] * 2);
        }
        else {
            while (canSolve < a[i]) {
                canSolve *= 2;
                ans++;
            }
            canSolve = max(canSolve, a[i] * 2);
        }
    }
    cout << ans << endl;

    return 0;
}