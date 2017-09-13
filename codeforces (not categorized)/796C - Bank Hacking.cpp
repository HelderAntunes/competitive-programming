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
#define VISITED 1
#define UNVISITED 0
#define PROCESSED 2


int main() {
	//freopen("in.txt","r", stdin);
	//freopen("out.txt","w", stdout);

	int n;
	scanf("%d", &n);
	vi a = vi(n);
	vector<vi> adjList(n, vi());
	int maxVal = -INF;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		maxVal = max(maxVal, a[i]);
	}

	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// respostas posiveis: maxVal, maxVal+1, maxVal+2
	int count2 = 0, count1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == maxVal)
			count2++;
		else if (a[i] == maxVal-1)
			count1++;
	}
	int _count2 = count2, _count1 = count1;

	int ans = maxVal+2; // pessimismo...

	for (int i = 0; i < n; i++) {

		if (a[i] == maxVal) {
			count2--;
		} else if (a[i] == maxVal-1) {
			count1--;
		}

		for (int j = 0; j < adjList[i].size(); j++) {
			int v = adjList[i][j];
			if (a[v] == maxVal) {
				count2--;
				count1++;
			}
			else if (a[v] == maxVal-1) {
				count1--;
			}
		}

		if (count2 == 0) {
			ans = min(ans, maxVal+1);
			if (count1 == 0) {
				ans = min(ans, maxVal);
			}
		}

		count1 = _count1;
		count2 = _count2;

	}

	cout << ans << endl;

	return 0;
}