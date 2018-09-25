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
#define MAX             100000
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

int main() {
  freopen("in.txt","r", stdin);
  //freopen("out.txt","w", stdout);

  int n, m;
  cin >> n >> m;
  vector<VI> count(m, VI(26, 0));
  for (size_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (size_t j = 0; j < m; j++) {
      int digit = (int)(s[j]-'A');
      count[j][digit] = 1;
    }
  }

  ll ans = 1;
  for (size_t i = 0; i < m; i++) {
    int sum = 0;
    for (size_t j = 0; j < 26; j++) sum += count[i][j];
    ans = ans * 1LL * sum % MOD;
  }
  cout << ans << endl;

  return 0;
}
