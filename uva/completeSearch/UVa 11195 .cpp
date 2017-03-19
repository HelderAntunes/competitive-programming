#include <bits/stdc++.h>


using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define PI acos(-1)
#define VISITED 1
#define UNVISITED 0
#define PROCESSED 2

int n, ans;
vector<string> adjMat;

int getBitOn(int integer) {
	int i = 1;
	int bitOn = 0;
	while (i != integer) {
		i *= 2;
		bitOn++;
	}
	return bitOn;
}

void solve(int rows, int dl, int dr, int iter) {

	if (rows == (1<<n)-1) {
		ans++;
		return;
	}

	int pos = ((1<<n)-1) & (~(rows|dl|dr));
	while(pos) {
		int p = pos & -pos;
		pos -= p;
		if (adjMat[getBitOn(p)][iter] == '.')
			solve(rows|p, (dl|p)<<1, (dr|p)>>1, iter+1);
	}


}

int main() {
	freopen("in.txt","r", stdin);
	freopen("out.txt","w", stdout);
	int Case = 1;
	while (cin >> n) {
		if (n == 0) break;
		string s;
		adjMat.clear();
		for (int i = 0; i < n; i++) {
			cin >> s;
			adjMat.push_back(s); 
		}
		ans = 0;
		solve(0, 0, 0, 0);
		cout << "Case " << Case << ": " << ans << endl;

		Case++;
	}
	

	return 0;
}
