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

ll V, E, nsets, maxIndSet;
vector<ll> adjMat;

void solve(ll i, ll used, ll depth) {
	if (used == (1LL<<V)-1) {
		nsets++;
		maxIndSet = max(maxIndSet, depth);
	}
	else {
		for (ll city = i; city < V; city++) {
		if (!(used & (1LL<<city))) {
			solve(city+1, used | adjMat[city], depth+1);
		}
	}
	}
	   
}

int main() {
	freopen("in.txt","r", stdin);
	freopen("out.txt","w", stdout);
	
	ll cities;
	cin >> cities;
	while(cities--) {
		scanf("%lld %lld", &V, &E);
		adjMat.assign(V, 0);
		for (ll i = 0; i < V; i++) {
			adjMat[i] = (1LL << i);
		}
		for (ll i = 0; i < E; i++) {
			ll u, v;
			scanf("%lld %lld", &u, &v);
			adjMat[u] |= (1LL<<v);
			adjMat[v] |= (1LL<<u);
		}

		nsets = 0, maxIndSet = 0;
		solve(0, 0, 0);
		printf("%lld\n%lld\n", nsets, maxIndSet);
	}

	return 0;
}
