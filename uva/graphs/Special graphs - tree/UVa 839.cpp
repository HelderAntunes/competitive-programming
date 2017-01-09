#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
#include <fstream>
#include <map>
#include <functional>
#include <sstream>
#include <bitset>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define INF2 2e9
#define PI acos(-1)
#define VISITED 1
#define UNVISITED 0
#define PROCESSED 2

ll pre_order() {
    ll wl, dl, wr, dr;
    scanf("%lld %lld %lld %lld", &wl, &dl, &wr, &dr);

    if (wl == 0) {
        wl = pre_order();
    }

    if (wr == 0) {
        wr = pre_order();
    }

    if (wl == -1 || wr == -1)
        return -1;

    if (wl * dl == wr * dr) {
        return wl + wr;
    }
    else {
        return -1;
    }

}

/**
 * Helder Antunes
 * UVa - 839 Not so Mobile
 * Pre-order traversal of a tree.
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    int T;
    cin >> T;

    while(T--) {
        ll res = pre_order();
        // cout << res << endl;
        if (res == -1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
        if (T > 0) {
            cout << endl;
        }
    }

    return 0;
}
