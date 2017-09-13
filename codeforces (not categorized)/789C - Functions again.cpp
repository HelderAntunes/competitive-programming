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

ll f_maximo(ll v1, ll v2) {
	if (v1 > v2)
		return v1;
	else
		return v2;
}

ll f_abs(ll v1) {
	if (v1 < 0) {
		return -v1;
	}
	else {
		return v1;
	}
}

int main() {
	//freopen("in.txt","r", stdin);
	//freopen("out.txt","w", stdout);

	int n;
	cin >> n;
	vector<ll> a = vector<ll>(n);
	vector<ll> b = vector<ll>(n-1);
	vector<ll> c = vector<ll>(n-1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i >= 1) {
			if (i % 2 == 0) {
				b[i-1] = f_abs(a[i]-a[i-1]);
				c[i-1] = -f_abs(a[i]-a[i-1]);
			}
			else {
				b[i-1] = -f_abs(a[i]-a[i-1]);
				c[i-1] = f_abs(a[i]-a[i-1]);
			}
		}
	}

	ll sum = 0, ans = 0;
	for (int i = 0; i < n-1; ++i)
	{
		sum += b[i];
		ans = f_maximo(ans, sum);
		if (sum < 0) sum = 0;
	}
	sum = 0;
	for (int i = 0; i < n-1; ++i)
	{
		sum += c[i];
		ans = f_maximo(ans, sum);
		if (sum < 0) sum = 0;
	}


	cout << ans << endl;

	return 0;
}