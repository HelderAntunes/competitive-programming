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

int dr[] = {1, -1, 0, 0}; 
int dc[] = {0, 0, 1, -1};
int res; 

void solve(vector<string> adjMat, int index, int cost) {
	if (index == 100) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j< 10; j++) {
				if (adjMat[i][j] == 'O') {
					return;
				}
			}
		}
		res = min(res, cost);
		return;
	}
	int r = index / 10;
	int c = index % 10;
	char l = adjMat[r][c];
	char l_other = (l == '#') ? 'O':'#';

	if (r >= 1) {
		if (adjMat[r-1][c] == 'O') {
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10) {
					adjMat[nr][nc] = (adjMat[nr][nc] == '#')? 'O':'#';
				}
			}
			adjMat[r][c] = l_other;
			solve(adjMat, index+1, cost+1);
		}
		else {
			solve(adjMat, index+1, cost);
		}
	}
	else {
		solve(adjMat, index+1, cost);
		adjMat[r][c] = l_other;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10) {
				adjMat[nr][nc] = (adjMat[nr][nc] == '#')? 'O':'#';
			}
		}
		solve(adjMat, index+1, cost+1);
	}
}

int main() {
	freopen("in.txt","r", stdin);
	freopen("out.txt","w", stdout);

	string s, s2;
	while (cin >> s) {
		if (s == "end")
			break;

		vector<string> adjMat = vector<string>(10);
		for (int i = 0; i < 10;i++) {
			cin >> s2;
			adjMat[i] = s2;
		}

		res = 101;
		solve(adjMat, 0, 0);
		if (res > 100) {
			cout << s << " " << -1 << endl;
		}
		else {
			cout << s << " " << res << endl;
		}
	}
	

	return 0;
}
