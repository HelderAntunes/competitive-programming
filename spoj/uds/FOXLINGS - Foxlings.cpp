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
#define MAX             200005
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

struct uf{
  int p[MAX], rank[MAX], number[MAX];
  int size, sets;

  uf(int s){
    size = sets = s;
    for (int i = 0; i < size; i++)
      { p[i]=i; rank[i]=0; number[i]=1; }
  }

  void link(int x, int y) {
    if(x == y) return;
    if (rank[x] <= rank[y]) {
        p[x] = y;
        --sets;
        number[y] += number[x];
        if (rank[x] == rank[y])
          rank[y]++;
    } else link(y, x);
  }

  int find_set(int x) {
    if (x != p[x]) p[x] = find_set(p[x]);
    return p[x];
  }

  int find_length(int x) {
    return number[ find_set(p[x]) ];
  }

  void union_set(int x, int y) {
    link(find_set(x), find_set(y));
  }
};

int main() {
  // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);

  int n, m;
  cin >> n >> m;
  uf s(m*2+5);
  ll ans = n;
  map<int,int> mymap;
  int id = 0;
  for (size_t i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    if (mymap.find(a) == mymap.end()) mymap.insert(PII(a, id++));
    if (mymap.find(b) == mymap.end()) mymap.insert(PII(b, id++));
    int a_id = mymap[a];
    int b_id = mymap[b];
    if (s.find_set(a_id) != s.find_set(b_id)) {
      s.union_set(a_id, b_id);
      ans = ans - 1;
    }
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
