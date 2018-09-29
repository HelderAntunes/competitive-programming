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
#define MAX             1000
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

ll r, k, T;
ll coefX[] = {1,0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765};
ll coefY[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765};

int main() {
  // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  while(true) {
    cin >> r;
    if (r == 0) break;
    cin >> k >> T;
    ll cx = 0;
    ll cy = 0;
    for (size_t i = 0; i < r; i++) {
      cx += coefX[i];
      cy += coefY[i];
    }
    // cout << cx << " " << cy << endl;
    ll solX, solY;
    for (ll i = 1; i <= T/cx+5; i++) {
      ll val = T - cx * i;
      if ((val%cy) != 0) {
        continue;
      } else {
        solX = i;
        solY = val/cy;
        break;
      }
    }
    ll R = coefX[r-1]*solX + coefY[r-1]*solY;
    R *= k;
    cout << solX << " " << solY << " " << R << endl;
  }

  return 0;
}
