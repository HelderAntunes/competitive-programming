#include <bits/stdc++.h>

using namespace std;
#define MK              make_pair
#define PB              push_back
#define ALL(v)          (v).begin() , (v).end()
#define Set(v,x)        memset(  v , x , sizeof(v))
#define two(n)          ( 1 << (n) )
#define contain(Set,i)  ( (Set) & two(i) )
#define __join(a,b)     a##b
#define foreach(c, i)   for(__typeof((c).begin())i=(c).begin(),__join(i,__end)=(c).end();i!=__join(i,__end);i++)

#define FOR(i,n)        for (int i = 0 ; i < (n) ; i++)
#define REP(i, b, e) 	  for(typeof(e) i=b; i!=e; ++i)
#define INF             1000000
#define EPS             1e-6
#define MAX             10000005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef long long int ll;

int main() {
  freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  ll xora = 0, xorb = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    xora ^= a[i];
  }
  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
    xorb ^= b[i];
  }

  if (xora != xorb) {
    cout << "NO" << endl;
    return 0;
  }

  vector<vector<ll> > res = vector<vector<ll> >(n, vector<ll>(m, 0));
  res[0][0] = a[0];
  for (size_t i = 1; i < m; i++) {
    res[0][0] ^= b[i];
    res[0][i] = b[i];
  }
  for (size_t i = 1; i < n; i++) {
    res[i][0] = a[i];
  }

  cout << "YES" << endl;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cout << res[i][j];
      if (j < m-1) cout << " ";
      else cout << endl;
    }
  }

  return 0;
}
