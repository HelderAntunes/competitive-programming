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

int n, m, k;
PII next(PII curr) {
  if (curr.second == m && curr.first%2 == 1) {
    return PII(curr.first+1, curr.second);
  }
  if (curr.second == 1 && curr.first%2 == 0) {
    return PII(curr.first+1, curr.second);
  }
  if (curr.first%2 == 1) {
    return PII(curr.first, curr.second+1);
  }
  if (curr.first%2 == 0) {
    return PII(curr.first, curr.second-1);
  }
}

int main() {
  freopen("in.txt","r", stdin);
  //freopen("out.txt","w", stdout);

  cin >> n >> m >> k;
  PII curr = PII(1,1);
  int len = (n*m)/k;
  int num = n*m/len;
  int lenr = (n*m)-(k-1)*len;
  for (size_t i = 0; i < k-1; i++) {
    int sz = len;
    cout << sz << " ";
    for (size_t j = 0; j < sz; j++) {
      cout << curr.first << " " << curr.second;
      if (j < sz-1) cout << " ";
      curr = next(curr);
    }
    cout << endl;
  }
  if (lenr > 0) {
    cout << lenr << " ";
    for (size_t j = 0; j < lenr; j++) {
      cout << curr.first << " " << curr.second;
      if (j < lenr-1) cout << " ";
      curr = next(curr);
    }
    cout << endl;
  }
  return 0;
}
