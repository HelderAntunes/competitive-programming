#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <ctype.h>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cassert>
#include <ctime>
#include <limits.h>
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
#define INF             1000000000
#define EPS             1e-6
#define MAX             1000005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef long long int ll;

ll dp[MAX];

ll solve(ll n) {
  if (n <= 1000000) {
    if (dp[n] != -1) {
      return dp[n];
    }
  }
  if (n == 0)
    return 0;
  ll option1 = n;
  ll option2 = solve(n/2) + solve(n/3) + solve(n/4);
  if (n <= 1000000)
    return dp[n] = max(option1, option2);
  else
    return max(option1, option2);
}

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt","w", stdout);

  memset(dp, -1, sizeof dp);
  int n;
  while (cin >> n) {
    ll ans = solve((ll)n);
    cout << ans << endl;
  }
  return 0;
}
