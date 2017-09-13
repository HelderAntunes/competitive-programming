#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define PI acos(-1)
#define VISITED 1
#define UNVISITED 0
#define PROCESSED 2

vector<ll> a;

ll computeCost(int k, vector<ll>& a) {
    ll cost = 0;
    vector<ll> costs = a;
    for (int i = 0; i < costs.size(); i++) {
        ll baseCost = costs[i];
        ll newCost = baseCost + (ll)(i+1)*(ll)k;
        costs[i] = newCost;
    }
    sort(costs.begin(), costs.end());
    for (int i = 0; i<  k; i++) {
        cost += costs[i];
    }
    return cost;
}

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n, S;
    scanf("%d %d", &n, &S);
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n;
    int m;
    ll cost;
    while(l < r) {
        m = (l + r)/2;
        cost = computeCost(m, a);
        //cout << m << " " << cost << endl;
        if (cost > S) {
            r = m - 1;
        }
        else if (cost == S) {
            cout << m << " " << cost << endl;
            return 0;
        }
        else {
            l = m + 1;
        }
    }


    m = (l + r)/2;
    cost = computeCost(m, a);
    if (cost > (ll)S) {
        m--;
        cost = computeCost(m, a);
        if (cost > (ll)S) {
            m = 0;
            cost = 0;
        }
    }
    cout << m << " " << cost << endl;

    return 0;
}