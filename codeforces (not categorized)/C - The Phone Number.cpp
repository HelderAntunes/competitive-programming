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
  int n;
  cin >> n;
  int sr = sqrt(n);
  VI res;
  for (size_t i = 0; i < n/sr; i++) {
    for (size_t j = n-sr*(i+1)+1; j <= n-sr*i; j++) {
      res.push_back(j);
    }
  }
  for (size_t i = 1; i <= n%sr; i++) {
    res.push_back(i);
  }
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i];
    if (i < res.size() - 1) cout << " ";
    else cout << endl;
  }
  return 0;
}
