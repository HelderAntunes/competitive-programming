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

struct alGraph{
  int n, nedge[MAX], edge[MAX][MAX], cost[MAX][MAX], prev[MAX];
  alGraph(int s) { n = s; Set(nedge, 0); Set (cost, 0); }
  void addEdge(int src, int dst, int c = 0) {
    edge[src][nedge[src]++] = dst;
    edge[dst][nedge[dst]++] = src;
    cost[src][dst] += c;
    cost[dst][src] += c; // remove if not bidi
  }
};

int dinic(alGraph &g, int s, int t ) {
  for ( int flow = 0, bot, i, u, v, qf, qb, q[MAX]; true ; ) {
    Set(g.prev, -1);
    qf = qb = 0, g.prev[q[qb++] = s] = -2;
    while( qb > qf && g.prev[t] == -1 )
      for( u = q[qf++], i = 0; i < g.nedge[u]; i++ )
        if( g.prev[v = g.edge[u][i]] == -1 && g.cost[u][v] )
          g.prev[q[qb++] = v] = u;
    if( g.prev[t] == -1 ) return flow;

    FOR(z,g.n) if( g.cost[z][t] && g.prev[z] != -1 ) {
      bot = g.cost[z][t];
      for( v = z, u = g.prev[v]; u >= 0; v = u, u = g.prev[v] )
        bot = min( bot , g.cost[u][v] );
      if( !bot ) continue;

      g.cost[z][t] -= bot; g.cost[t][z] += bot;
      for( v = z, u = g.prev[v]; u >= 0; v = u, u = g.prev[v] )
        g.cost[u][v] -= bot, g.cost[v][u] += bot;
      flow += bot;
    }
  }
}

int letterToInt(char a) {
  if (a >= 'a' && a <= 'z') {
    return (int)a-(int)'a';
  } else if (a >= 'A' && a <= 'Z') {
    return (int)a-(int)'A'+26;
  }
}

vector<vector<PII> > edges;
int main() {
  // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);

  int n;
  cin >> n;
  edges = vector<vector<PII> >(52, vector<PII>());
  for (size_t i = 0; i < n; i++) {
    char a, b;
    int c, a_ind, b_ind;
    cin >> a >> b >> c;
    a_ind = letterToInt(a);
    b_ind = letterToInt(b);
    bool found = false;
    for (size_t i = 0; i < edges[a_ind].size(); i++) {
      if (edges[a_ind][i].first == b_ind) {
        edges[a_ind][i].second += c;
        found = true;
        break;
      }
    }
    if (!found) {
      edges[a_ind].PB(PII(b_ind, c));
    }
  }

  alGraph g(52);

  for (size_t i = 0; i < 52; i++) {
    for (size_t j = 0; j < edges[i].size(); j++) {
      g.addEdge(i, edges[i][j].first, edges[i][j].second);
    }
  }

  cout << dinic(g, 26, 51) << endl;
  return 0;
}
