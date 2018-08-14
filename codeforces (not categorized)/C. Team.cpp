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

  int n, m;
  cin >> n >> m;
  if (!(m <= 2 * n + 2 && n <= m + 1)) {
    cout << -1 << endl;
    return 0;
  }

  int sobra = n;
  VI res;
  for (size_t i = 0; i < m/2; i++) {
    res.push_back(1);
    res.push_back(1);
    if (sobra > 0) {
      res.push_back(0);
      sobra--;
    }
  }
  if (m%2 == 1) res.push_back(1);
  VI res2;
  if (sobra > 0) {
    res2.push_back(0);
    sobra--;
  }
  for (size_t i = 0; i < res.size()-1; i++) {
    res2.push_back(res[i]);
    if (sobra > 0 && res[i] == 1 && res[i+1] == 1 ) {
      res2.push_back(0);
      sobra--;
    }
  }
  res2.push_back(res[res.size()-1]);
  if (sobra > 0) {
    res2.push_back(0);
  }
  for (size_t i = 0; i < res2.size(); i++) {
    cout << res2[i];
  }
  cout << endl;

  return 0;
}
