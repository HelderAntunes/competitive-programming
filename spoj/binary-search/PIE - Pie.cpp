#include <bits/stdc++.h>

using namespace std;
#define MK              make_pair
#define PB              push_back
#define ALL(v)          (v).begin() , (v).end()
#define Set(v,x)        memset(  v , x , sizeof(v))
#define contain(Set,i)  ( (Set) & two(i) )
#define __join(a,b)     a##b
#define foreach(c, i)  co  for(__typeof((c).begin())i=(c).begin(),__join(i,__end)=(c).end();i!=__join(i,__end);i++)

#define FOR(i,n)        for (int i = 0 ; i < (n) ; i++)
#define REP(i, b, e) 	  for(typeof(e) i=b; i!=e; ++i)
#define INF             100000000
#define EPS             1e-6
#define MAX             55
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

double PI = acos(-1);

int main() {
  // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  int t;
  cin >> t;
  while(t--) {
    int n, f;
    cin >> n >> f;
    f++;
    vector<double> pies;
    for (size_t i = 0; i < n; i++) {
      double r;
      cin >> r;
      pies.PB(r*r*PI);
    }
    sort(ALL(pies));
    double minL = pies[0]/f;
    double maxL = pies[n-1];
    double ans = minL;
    while (maxL - minL > 0.00001) {
      double mid = (maxL + minL)/2;
      // cout << minL << " " << mid << " " << maxL << endl;
      int can = 0;
      for (size_t i = 0; i < n; i++) {
        int parts = (int)(pies[i]/mid);
        can += parts;
      }
      if (can >= f) {
        ans = mid;
        minL = mid;
      } else {
        maxL = mid;
      }
    }

    cout << fixed << setprecision(4) << ans << endl;
    //  cout << "----------------------------\n";
  }
  return 0;
}
