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

  int Cases;
  scanf("%d", &Cases);
  while(Cases--) {
    int n;
    scanf("%d", &n);

    vector<PII> edges;
    for (size_t i = 0; i < n-1; i++) {
      int a, b;
      scanf("%d %d\n", &a, &b);
      edges.PB(PII(a-1,b-1));
    }

    int q;
    scanf("%d\n", &q);
    vector<PII> queries;
    set<int> edgesRemoved;
    for (size_t i = 0; i < q; i++) {
      char type;
      scanf("%c\n", &type);
      if (type == 'Q') {
        queries.PB(PII(1,0));
      } else {
        int edge;
        scanf("%d\n", &edge);
        queries.PB(PII(2,edge-1));
        edgesRemoved.insert(edge-1);
      }
    }

    uf s(n);
    reverse(ALL(queries));
    vector<ll> responses;
    ll ans = (ll)n*1LL*(ll)(n-1)/2;
    for (size_t i = 0; i < n-1; i++) {
      if (edgesRemoved.find(i) == edgesRemoved.end()) {
        int a = edges[i].first, b = edges[i].second;
        int lengthA = s.find_length(s.find_set(a));
        int lengthB = s.find_length(s.find_set(b));
        s.union_set(a, b);
        int lengthUnion = s.find_length(s.find_set(a));
        ans += (ll)((ll)lengthA*(ll)(lengthA-1)/2 + (ll)lengthB*(ll)(lengthB-1)/2);
        ans -= (ll)((ll)lengthUnion*(ll)(lengthUnion-1)/2);
      }
    }
    for (size_t i = 0; i < q; i++) {
      if (queries[i].first == 1) { // Q
        responses.PB(ans);
      } else { // R
        int edge = queries[i].second;
        int a = edges[edge].first;
        int b = edges[edge].second;
        int lengthA = s.find_length(s.find_set(a));
        int lengthB = s.find_length(s.find_set(b));
        s.union_set(a, b);
        int lengthUnion = s.find_length(s.find_set(a));
        ans += (ll)((ll)lengthA*(ll)(lengthA-1)/2 + (ll)lengthB*(ll)(lengthB-1)/2);
        ans -= (ll)((ll)lengthUnion*(ll)(lengthUnion-1)/2);
        responses.PB(-1);
      }
    }
    reverse(ALL(responses));
    for (size_t i = 0; i < responses.size(); i++) {
      if (responses[i] == -1) continue;
      printf("%lld\n", responses[i]);
    }
    printf("\n");
  }

  return 0;
}
