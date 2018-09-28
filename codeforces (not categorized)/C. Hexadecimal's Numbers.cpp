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

ll pow2(int n) {
  ll res = 1;
  for (int i = 0; i < n; i++) {
    res = res * 1LL * 2;
  }
  return res;
}

int numDigits(int n) {
  int res = 0;
  while(n != 0) {
    n /= 10;
    res++;
  }
  return res;
}

int getDigit(int n, int i) {
  while(i > 1) {
    n /= 10;
    i--;
  }
  return n % 10;
}

ll solve(int n) {
  int nd = numDigits(n);
  ll res = 0;
  for (int i = nd; i > 0; i--) {
    int digit = getDigit(n,i);
    // cout << digit << endl;
    if (digit > 1) {
      return i == nd ? pow2(i-1) + res:pow2(i)+res;
    }
    if (digit == 1 && i < nd) {
      res += pow2(i-1);
    }
  }
  return 1LL + res;
}

int main() {
  freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  int n;
  cin >> n;
  int nd = numDigits(n);
  ll res = 0;
  for (size_t i = 1; i < nd; i++) {
    res += pow2(i-1);
  }
  // cout << res << "dsdsdssd" << endl;
  res += solve(n); // 1, 10, 11, 100
  cout << res << endl;
  return 0;
}
