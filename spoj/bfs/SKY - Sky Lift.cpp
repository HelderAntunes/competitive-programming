#include <bits/stdc++.h>

using namespace std;
#define MK              make_pair
#define PB              push_back
#define ALL(v)          (v).begin() , (v).end()
#define Set(v,x)        memset(  v , x , sizeof(v))
#define contain(Set,i)  ( (Set) & two(i) )
#define __join(a,b)     a##b
#define foreach(c, i)  co  for(__typeof((c).begin())i=(c).begin(),__join(i,__end)=(c).end();i!=__join(i,__end);i++)

#define FOR(i,n)        for (int i = 0 ; i < (n) ; i++)
#define REP(i, b, e) 	  for(typeof(e) i=b; i!=e; ++i)
#define INF             100000000
#define EPS             1e-6
#define MAX             1000
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

ll n, xa, ya, xb, yb, a, b, c;
vector<vector<ll> > mat;
vector<VI> visited;
int dirH[] = {0,0,-1,1};
int dirV[] = {1,-1,0,0};

int bfs(ll height, int i, int j) {
  visited = vector<VI>(n, VI(n, INF));
  queue<PII> q;
  visited[i][j] = 0;
  q.push(PII(i,j));
  while (!q.empty()) {
    PII cur = q.front();
    q.pop();
    for (size_t k = 0;k < 4; k++) {
      int ni = cur.first + dirV[k];
      int nj = cur.second + dirH[k];
      if (!(ni >= 0 && ni < n && nj >= 0 && nj < n)) {
        continue;
      }
      if (mat[ni][nj] < height) {
        continue;
      }
      if (visited[ni][nj] == INF) {
        if (ni == xb && nj == yb) {
          return 1;
        }
        visited[ni][nj] = visited[cur.first][cur.second] + 1;
        q.push(PII(ni, nj));
      }
    }
  }
  return 0;
}

int main() {
 // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);

  cin >> n;
  cin >> xa >> ya >> xb >> yb;
  cin >> a >> b >> c;

  mat = vector<vector<ll> >(n, vector<ll>(n));
  xa--;xb--;ya--;yb--;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      mat[i][j] =  (((i+1-1)*n+j+1-1)*a + b) % c;
      // cout << mat[i][j] << " ";
    }
    // cout << endl;
  }

  // cout << "------------------\n";
  ll heightFrom = mat[xa][ya];
  ll heightTo = mat[xb][yb];
  ll low = 0;
  ll high = heightFrom;
  ll ans = low;
  while(low < high) {
    ll mid = (low+high)/(ll)2;
    // cout << low << " " << mid << " " << high << endl;

    int found = bfs(mid, xa, ya);
    //cout << low << " " << mid << " " << high << endl;
    if (found) {
      ans = mid;
      low = mid;
      if (low == high-1) {
        found = bfs(high, xa, ya);
        if (found) {
          ans = high;
        } else {
          ans = low;
        }
        break;
      }
    } else {
      high = mid;
    }
  }
  ans = (heightFrom-ans) + (heightTo-ans);
  cout << ans << endl;

  return 0;
}
