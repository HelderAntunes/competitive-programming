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

    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    vi station = vi(n, 0);
    for (size_t i = 0; i < k; i++) {
        int st;
        scanf("%d", &st);
        st--;
        station[st] = 1;
    }

    vector<vii> AdjList = vector<vii>(n, vii());
    for (size_t i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        AdjList[u].push_back(ii(v, i));
        AdjList[v].push_back(ii(u, i));
    }

    vi dist = vi(n, -1);
    vi distEdge = vi(n-1, 0);
    queue<ii> q = queue<ii>();
    for (size_t i = 0; i < n; i++) {
        if (station[i]) {
            q.push(ii(0, i));
            dist[i] = 0;
        }
    }
    int ans = 0;
    vi ans_ = vi();
    while (!q.empty()) {
        ii top = q.front();
        q.pop();
        int d = top.first;
        int u = top.second;
        for (size_t i = 0; i < AdjList[u].size(); i++) {
            ii v = AdjList[u][i];
            if (distEdge[v.second]) continue;
            distEdge[v.second] = 1;
            if (dist[v.first] == -1) {
                dist[v.first] = d+1;
                q.push(ii(d+1, v.first));
            }
            else {
                ans++;
                ans_.push_back(v.second);
            }
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < ans_.size(); i++) {
        printf("%d", ans_[i]+1);
        if (i == ans_.size()-1) {
            printf("\n");
        }
        else
            printf(" ");
    }

	return 0;
}