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

ll dp[105][105][2];
int n, k, d;
ll solve(int i, int sum, int hasD) {
  if (sum > n) {
    return 0;
  }
  if (dp[i][sum][hasD] != -1) {
    return dp[i][sum][hasD];
  }
  if (sum == n && hasD == 1) {
    return 1;
  }
  if (sum == n && hasD == 0) {
    return 0;
  }

  ll res = 0;
  for (size_t j = 1; j <= k; j++) {
    int hasD_ = 0;
    if (j >= d) hasD_ = 1;
    res = (res + solve(i+1, sum+j, hasD|hasD_)) % MOD;
  }
  return dp[i][sum][hasD] = res;
}

int main() {
  freopen("in.txt","r", stdin);
  //freopen("out.txt","w", stdout);
  for (size_t i = 0; i < 105; i++) {
    for (size_t j = 0; j < 105; j++) {
      dp[i][j][0] = -1;
      dp[i][j][1] = -1;
    }
  }
  cin >> n >> k >> d;
  cout << solve(0, 0, 0) << endl;
  return 0;
}
