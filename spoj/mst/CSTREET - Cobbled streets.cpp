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
#define INF             1000000000
#define EPS             1e-6
#define MAX             300005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

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

struct elGraph{  // Edge List
  int ne, n;
  pair < int, PII > edge[MAX];
  elGraph (int s) { n = s; ne = 0; }
  elGraph () { n = 0; ne = 0; }
  void addEdge(int src, int dst, int c) { edge[ne++]= MK(c, PII(src, dst)); }
};

int kruskal(elGraph & g, int mst[]){
  for(int i=0; i < g.ne; i++) mst[i] = false;
  uf s(g.n);
  int i , minimum = 0;

  sort(g.edge, g.edge + g.ne);
  for( i=0; i < g.ne; i++)
    if(s.find_set(g.edge[i].V1) != s.find_set(g.edge[i].V2)) {
      s.union_set(g.edge[i].V1, g.edge[i].V2);
      mst[i] = true;
      minimum += g.edge[i].COST;
    }
  return minimum;
}

elGraph g;

void initGraph(elGraph* g, int n) {
  g->n = n; g->ne = 0;
}

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt","w", stdout);

  int t, p, n, m, a, b, c;
  scanf("%d", &t);
  while (t--) {
    scanf("%d\n%d\n%d", &p, &n, &m);
    initGraph(&g, n+1);
    FOR(i,m) {
      scanf("%d %d %d", &a, &b, &c);
      g.addEdge(a, b, c*p);
    }
    int mst[MAX];
    int ans = kruskal(g, mst);
    printf("%d\n", ans);
  }
  return 0;
}
