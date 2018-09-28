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

string s;
int m;
VI path;

int solve(int diff, int last, int curr) {
  if (curr > m) return 1;
  if (curr == m) {
    path.PB(last);
    return 1;
  }
  // cout << diff << " * " << last << " * " << curr << endl;
  int f = 0;
  for (int i = 1; i <= 10; i++) {
    if(diff<0 && i!=last && s[i-1]=='1' && diff+i>0) {
      // cout << diff << " *1 " << i << endl;
      f = solve(diff+i, i, curr+1);
    } else if (diff>0 && i!=last && s[i-1]=='1' && diff-i<0) {
      // cout << diff << " *2 " << i << endl;
      f = solve(diff-i, i, curr+1);
    }
    if (f) {
      path.PB(last);
      return 1;
    }
  }

  return 0;
}

int main() {
  freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);

  cin >> s;
  cin >> m;

  for (size_t i = 1; i <= 10; i++) {
    if (s[i-1]=='1' && solve(i,i,1)) {
      cout << "YES" << endl;
      reverse(ALL(path));
      for (size_t i = 0; i < m; i++) {
        cout << path[i];
        if (i < m-1) cout << " ";
        else cout << endl;
      }
      return 0;
    }
  }
  if (m == 1) {
    for (size_t i = 1; i <= 10; i++) {
      if (s[i-1] == '1') {
        cout << "YES" << endl;
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
