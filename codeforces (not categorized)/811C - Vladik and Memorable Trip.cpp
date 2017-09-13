#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
vi a;
vector<ii> intervalos;
vi dp;

int getVal(int i, int j) {
    int val = 0;
    set<int> conjunto = set<int>();
    for (int k = i; k <= j; k++)
        conjunto.insert(a[k]);
    set<int>::iterator it = conjunto.begin();
    while (it != conjunto.end()) {
        int x = (*it);
        val = val ^ (*it);
        it++;
    }
    return val;
}

int solve(int i) {
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int val = a[i];
    if (intervalos[val].first == i) {
        int j = intervalos[val].second;
        int xorVal = getVal(i, j);
        return dp[i] = max(xorVal + solve(j+1), solve(i+1));
    }
    else {
        return dp[i] = solve(i+1);
    }
}

int main() {
  //  freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    scanf("%d", &n);
    a = vi(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    intervalos = vector<ii>(5005, ii(-1, -1));
    dp = vi(n, -1);
    for(int i = 0; i < n; i++) {
        int val = a[i];
        if (intervalos[val].first == -1) {
            for (int j = n-1; j >= 0; j--) {
                if (a[j] == a[i]) {
                    intervalos[val] = ii(i, j);
                    //cout << intervalos[val].first << " " << intervalos[val].second << endl;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 5005; i++) {
        if (intervalos[i].first != -1) {
            int x = intervalos[i].first;
            int y = intervalos[i].second;
            int max_j = y;
            int min_i = x;
            for (int j = x; j <= y; j++) {
                int val = a[j];
                max_j = max(max_j, intervalos[val].second);
                min_i = min(min_i, intervalos[val].first);
            }
            intervalos[i].first = min_i;
            intervalos[i].second = max_j;
            //cout << intervalos[i].first << " " << intervalos[i].second << endl;
        }
    }

    int res = solve(0);
    cout << res << endl;

    return 0;
}