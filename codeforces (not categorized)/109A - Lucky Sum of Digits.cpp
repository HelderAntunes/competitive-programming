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
#define INF             100000000
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

  ll n;
  cin >> n;
  int sol4 = -1, sol7 = -1, count = INF;
  for (size_t i = 0;i*7<=n; i++) {
    int sobra = n-i*7;
    if (sobra%4==0) {
      int j = sobra/4;
      if (i+j < count){
        sol4 = j;
        sol7 = i;
        count = i+j;
      } else if (i+j==count && j > sol4) {
        sol4 = j;
        sol7 = i;
        count = i+j;
      }
    }
  }
  if (count == INF) {
    cout << -1 << endl;
  } else {
    for (size_t i = 0; i < sol4; i++) {
      cout << 4;
    }
    for (size_t i = 0; i < sol7; i++) {
      cout << 7;
    }
    cout << endl;
  }

  return 0;
}
