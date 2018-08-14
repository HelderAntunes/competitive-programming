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
typedef long long int ll;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int main() {
  freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);

  int n;
  cin >> n;
  VL a(n), sum(n);
  ll total = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  sum[0] = a[0];
  for (size_t i = 1; i < n; i++)
    sum[i] = a[i] + sum[i-1];
  if (total % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  VI is, js;
  for (size_t i = 0; i < n-1; i++) {
    if (sum[i] == total / 3) is.push_back(i);
    if (sum[i] == 2 * total / 3) js.push_back(i);
  }

  ll res = 0;
  for (size_t i = 0; i < is.size(); i++) {
    int ind = is[i];
    VI::iterator it1 = upper_bound(ALL(js), ind);
    if (it1 == js.end()) continue;
    res += js.end()-it1;
  }
  cout << res << endl;
  return 0;
}
