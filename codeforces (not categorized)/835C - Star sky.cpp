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

int n, q, c;
vector<vector<vi> > oriMap;
vector<vector<vi> > upright;

int solve(int x, int y, int time) {
    if (x > 100 || x < 1 || y > 100 || y < 1) return 0;
    if (upright[x][y][time] != -1) return upright[x][y][time];

    int atual = 0;
    for (int i = 0; i < oriMap[x][y].size(); ++i)
    {
        atual += (oriMap[x][y][i] + time) % (c+1);
    }
    return upright[x][y][time] = atual + solve(x+1, y, time) + solve(x, y+1, time) - solve(x+1, y+1, time);
} 

int main() {
	//freopen("in.txt","r", stdin);
	//freopen("out.txt","w", stdout);

    scanf("%d %d %d", &n, &q, &c);
    oriMap.assign(101, vector<vi>(101, vi()));
    upright.assign(101, vector<vi>(101, vi(c+1, -1)));
    for (int i = 0; i < n; ++i)
    {
        int x, y, s;
        scanf("%d %d %d", &x, &y, &s);
        oriMap[x][y].push_back(s);
    }

    for (int i = 0; i <= c; ++i)
    {
        solve(1, 1, i);
    }

    for (int i = 0; i < q; ++i)
    {
        int t, x1, y1, x2, y2;
        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
        t = t % (c+1);
        
        int ans = upright[x1][y1][t];
        if (x2 == 100 && y2 < 100) ans -= upright[x1][y2+1][t];
        else if (y2 == 100 && x2 < 100) ans -= upright[x2+1][y1][t];
        else if (x2 < 100 && y2 < 100) ans -= upright[x1][y2+1][t] + upright[x2+1][y1][t] - upright[x2+1][y2+1][t];
        cout << ans << endl;
    }
    
    return 0;
}
