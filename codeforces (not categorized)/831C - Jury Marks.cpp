#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, k;
vi jurys, remembers;

int main() {
   // freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        int v; scanf("%d", &v);
        jurys.push_back(v);
    }
    for (int i = 0; i < n; i++) {
        int v; scanf("%d", &v);
        remembers.push_back(v);
    }

    set<int> conjunto;
    conjunto.insert(jurys[0]);
    for (int i = 1; i < k; i++) {
        jurys[i] += jurys[i-1];
        conjunto.insert(jurys[i]);
    }

    int ans = 0;
    set<int>::iterator it = conjunto.begin();
    while (it != conjunto.end()) {
        int initial = - (*it) + remembers[0];
        bool possible = true;
        for (int j = 0; j < n; j++) {
            int v = remembers[j] - initial;
            if (conjunto.find(v) == conjunto.end()) {
                possible = false;
                break;
            }
        }
        if (possible) ans++;
        it++;
    }
    printf("%d\n", ans);
    return 0;
}