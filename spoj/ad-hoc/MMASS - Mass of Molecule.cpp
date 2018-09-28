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

int main() {
  // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  string s;
  cin >> s;
  stack<int> S;
  for (size_t i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c >= '2' && c <= '9') {
      int v = S.top();
      S.pop();
      int mul = (int)c-(int)'2'+2;
      S.push(v*mul);
    } else if (c == '(') {
      S.push(-1);
    } else if (c == ')') {
      int v = 0;
      while(!S.empty() && S.top() != -1) {
        v += S.top();
        S.pop();
      }
      S.pop();
      S.push(v);
    } else {
      if (c == 'H') {
        S.push(1);
      } else if (c == 'O') {
        S.push(16);
      } else if (c =='C') {
        S.push(12);
      }
    }
  }

  int ans = 0;
  while(!S.empty()) {
    ans += S.top();
    S.pop();
  }
  cout << ans << endl;
  return 0;
}
