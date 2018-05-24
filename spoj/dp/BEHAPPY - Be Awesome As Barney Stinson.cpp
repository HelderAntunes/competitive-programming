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
#define MAX             1000005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef long long int ll;

int m, n;
VI a, b;
ll dp[25][105];

ll solve(int i, int presents) {
	if (dp[i][presents] != -1)
		return dp[i][presents];
	if (i == m-1) {
		if (presents < a[i])
			return 0;
		if (presents > b[i])
			return 0;
		return 1;
	}
	ll res = 0;
	for (int j = a[i]; j <= b[i] && j <= presents; ++j) {
		
		ll r = solve(i+1, presents - j);
		res += r;
	}
	return dp[i][presents] = res;
}

int main() {
  freopen("in.txt","r", stdin);
 	freopen("out.txt","w", stdout);
 	
 	while (true) {
 		scanf("%d %d", &m, &n);
 		if (m == 0 && n == 0) break;

 		FOR(i,25) FOR(j,105) dp[i][j] = -1;

 		a = VI(m);
 		b = VI(m);
 		for (int i = 0; i < m; ++i) {
 			scanf("%d", &a[i]);
 			scanf("%d", &b[i]);
 		}
 		
 		ll res = solve(0, n);
 		printf("%lld\n", res);
 	}

  return 0;
}
