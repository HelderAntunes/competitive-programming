#include <bits/stdc++.h>

using namespace std;
#define MK              make_pair
#define PB              push_back
#define ALL(v)          (v).begin() , (v).end()
#define Set(v,x)        memset(  v , x , sizeof(v))
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
  // freopen("out.txt","w", stdout);
  int n;
  cin >> n;
  VI a(n);
  VI visit(n, 0);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(ALL(a));
  int res = 0;
  bool done = false;
  for (size_t i = 0; i < n && !done; i++) {
    if (visit[i] == 1) continue;

    int count = 1;
    visit[i] = 1;
    for (size_t j = i+1; j < n; j++) {
      if (visit[j] == 1) continue;

      if (a[j] >= count) {
        visit[j] = 1;
        count++;
      }
    }

    res++;

    for (size_t j = 0; j < n; j++) {
      if (visit[j] == 0) {
        break;
      } else if (j == n-1) {
          done = true;
      }
    }
  }

  cout << res << endl;

  return 0;
}
