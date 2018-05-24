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
#define MAX             100005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef long long int ll;

int c, n, a, b;
int visited[MAX], dist[MAX];
VI graph[MAX];

void dfs(int u, int d) {
  visited[u] = 1;
  dist[u] = d;
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (!visited[v]) {
      dfs(v, d+1);
    }
  }
}

int main() {
  freopen("in.txt","r", stdin);
 	freopen("out.txt","w", stdout);

  scanf("%d", &c);
  while (c--) {
      scanf("%d", &n);
      for (size_t i = 0; i < n; i++) {
        graph[i] = VI();
        visited[i] = 0;
        dist[i] = -1;
      }
      for (size_t i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
      }

      dfs(0, 0);
      int u2 = 0, distMax = 0;
      for (size_t i = 1; i < n; i++) {
        if (dist[i] > distMax) {
          distMax = dist[i];
          u2 = i;
        }
      }

      for (size_t i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = -1;
      }
      dfs(u2, 0);

      int res = 0;
      for (size_t i = 0; i < n; i++) {
        res = max(res, dist[i]);
      }
      if (res % 2 == 0) {
        res = res /2;
      }
      else {
        res = (res+1)/2;
      }
      printf("%d\n", res);
  }


  return 0;
}
