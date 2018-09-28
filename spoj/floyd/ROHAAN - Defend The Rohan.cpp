#include <bits/stdc++.h>

using namespace std;
#define MK              make_pair
#define PB              push_back
#define ALL(v)          (v).begin() , (v).end()
#define Set(v,x)        memset(  v , x , sizeof(v))
#define contain(Set,i)  ( (Set) & two(i) )
#define __join(a,b)     a##b
#define foreach(c, i)   for(__typeof((c).begin())i=(c).begin(),__join(i,__end)=(c).end();i!=__join(i,__end);i++)

#define FOR(i,n)        for (int i = 0 ; i < (n) ; i++)
#define REP(i, b, e) 	  for(typeof(e) i=b; i!=e; ++i)
#define INF             100000000
#define EPS             1e-6
#define MAX             55
#define MOD             1000000007
#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef long long int ll;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef pair<pair<int,int>,int> PIII;

int g[MAX][MAX];

void floyd(int g[MAX][MAX], int n) {
  FOR(i, n) g[i][i] = 0;
  FOR(k, n) FOR(i, n)
    if (g[i][k] != INF) FOR (j, n)
      g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
}

int main() {
  // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  int t, Case = 1;
  cin >> t;
  while(t--) {
    int ans = 0;
    int n;
    cin >> n;

    FOR(i,n) FOR(j,n) g[i][j] = INF;


    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        int d;
        cin >> d;
        g[i][j] = d;
      }
    }

    floyd(g, n);
    int r;
    cin >> r;
    for (size_t i = 0; i < r; i++) {
      int s, d;
      cin >> s >> d;
      ans += g[s-1][d-1];
    }

    cout << "Case #" << Case << ": " << ans << endl;
    Case++;
  }

  return 0;
}
