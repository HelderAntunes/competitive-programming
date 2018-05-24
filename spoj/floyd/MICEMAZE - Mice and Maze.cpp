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
#define MAX             500

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

int N, E, T, M, a, b, c;

void floyd(int g[MAX][MAX], int n) {
  FOR(i, n) g[i][i] = 0;
  FOR(k, n) FOR(i, n)
    if (g[i][k] != INF) FOR (j, n)
      g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
}

int main() {
  freopen("in.txt","r", stdin);
 	freopen("out.txt","w", stdout);

  scanf("%d %d %d %d", &N, &E, &T, &M);
  int g[MAX][MAX];
  FOR(i,N+1) FOR(j,N+1) g[i][j] = INF;
  FOR(i,M) {
    scanf("%d %d %d", &a, &b, &c);
    g[a][b] = c;
  }
  floyd(g, N+1);
  int answer = 0;
  for (size_t i = 1; i < N+1; i++) {
    if (g[i][E] <= T) {
      answer++;
    }
  }
  printf("%d\n", answer);
  return 0;
}
