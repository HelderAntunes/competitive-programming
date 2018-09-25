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

int main() {
  freopen("in.txt","r", stdin);
  //freopen("out.txt","w", stdout);

  string s;
  cin >> s;
  VI del(s.size(), 0);
  for (size_t i = 0; i < s.size();) {
    int count = 1;
    for (size_t j = i+1; j < s.size() && s[j]==s[i]; j++) {
      count++;
    }
    if (count < 3) {
      i += count;
      continue;
    }
    int ind = i;
    for (size_t j = 0; j < count-2; j++) {
      del[ind++] = 1;
    }
    i += count;
  }

  string s2;
  for (size_t i = 0; i < s.size(); i++) {
    if (del[i] == 0) {
      s2 += s[i];
    }
  }
  // cout << s2 << endl;
  del = VI(s2.size(), 0);
  for (size_t i = 0; (int)i < (int)(s2.size()-3);) {
    if (s2[i] == s2[i+1] && s2[i+2] == s2[i+3]) {
      del[i+2] = 1;
      i = i+3;
    } else {
      i++;
    }
  }
  string res;
  for (size_t i = 0; i < s2.size(); i++) {
    if (del[i] == 0) {
      res += s2[i];
    }
  }
  cout << res << endl;
  return 0;
}
