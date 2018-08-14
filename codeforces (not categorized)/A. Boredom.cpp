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

int n;
VL a, c, dp;

ll solve(int i) {
  if (i >= MAX) {
    return c[i]*i;
  }
  if (dp[i] != -1) {
    return dp[i];
  }
  ll option1 = i*1LL*c[i] + solve(i+2);
  ll option2 = solve(i+1);
  return dp[i] = max(option1, option2);
}
int main() {
  freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);

  int n;
  cin >> n;
  a = VL(n);
  c = VL(MAX + 5, 0);
  dp = VL(MAX + 5, -1);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }
  cout << solve(0) << endl;

  return 0;
}
