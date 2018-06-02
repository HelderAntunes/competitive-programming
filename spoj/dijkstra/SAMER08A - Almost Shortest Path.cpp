#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <ctype.h>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cassert>
#include <ctime>
#include <limits.h>
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
#define MAX             2505

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef long long int ll;

int N, M, S, D, U, V, P;

struct edge { int to, cost; };

int dijkstra(vector< vector<edge> > &g, int source, int target, 
    vector<int>& dist, vector<VI>& prev) {
  dist[source] = 0;
  prev[source];
  set< pair<int, int> > active;
  active.insert( {0, source} );

  while (!active.empty()) {
    int cur = active.begin()->second;
    if (cur == target) return dist[cur];
    active.erase( active.begin() );
    for (edge ed : g[cur]) 
      if (dist[ed.to] > dist[cur] + ed.cost) {
        active.erase( { dist[ed.to], ed.to } );
        dist[ed.to] = dist[cur] + ed.cost;
        prev[ed.to].clear();
        prev[ed.to].push_back(cur);
        active.insert( { dist[ed.to], ed.to } );
      }
      else if (dist[ed.to] == dist[cur] + ed.cost) {
      	prev[ed.to].push_back(cur);
      }
  }
  return INF;
}

void deleteEdges(vector<vector<edge> > &g, vector<VI>& prev, int v, int s) {
	if (v == s) {
		return;
	}

	VI prevs = prev[v];
	for (int i = 0; i < prevs.size(); ++i) {
		int u = prevs[i];
		for (int j = 0; j < g[u].size(); ++j) {
			if (g[u][j].to == v) {
				g[u][j].cost = INF;
			}
		}

		deleteEdges(g, prev, u, s);
	}
}

int main() {
  freopen("in.txt","r", stdin);
 	freopen("out.txt","w", stdout);

 	while (true) {
 		cin >> N >> M;
 		if (N == 0 && M == 0) {
 			break;
 		}
 		cin >> S >> D;

 		vector< vector<edge> > g(N); 
 		vector<int> dist(g.size(), INF);
		vector<VI> prev(g.size());
		for (int i = 0; i < M; ++i) {
			cin >> U >> V >> P;
			g[U].push_back({V, P});
		}
		
		dijkstra(g, S, D, dist, prev);
		deleteEdges(g, prev, D, S);
		
		dist = VI(g.size(), INF);
		prev = vector<VI>(g.size());
		int res = dijkstra(g, S, D, dist, prev);
		res = res == INF ? -1 : res;
		cout << res << endl;
 	}

  return 0;
}
