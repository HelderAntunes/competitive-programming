#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ll> ill;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define PI acos(-1)

int n, a, b;
vi c;

int main() {
//	freopen("in.txt","r", stdin);
//	freopen("out.txt","w", stdout);

    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        c.push_back(v);
    }

    vi count(10e6 + 5, 0);
    for (int i = 0; i < n; i++) {
        int v = c[i];
        if (v == b) {
            count[v]++;
            continue;
        }
        if (count[v] != -1) {
            if (count[v] < count[b]) {
                count[v] = -1;
            }
            else {
                count[v]++;
            }
        }
    }

    int res = -1;
    for (int i = 0; i < n; i++) {
        int v = c[i];
        if (count[v] >= count[b] && v != b) {
            res = v;
            break;
        }
    }

    cout << res << endl;
   
	return 0;
}