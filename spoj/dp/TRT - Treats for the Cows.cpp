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
#define MAX             2001

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef long long int ll;

int n, dp[MAX][MAX];
VI v;

int solve(int i, int j) {
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (i == j) {
    return v[i] * n;
  }
  
  int total = j - i + 1;
  int option1 = v[i] * (n-total+1) + solve(i+1, j);
  int option2 = v[j] * (n-total+1) + solve(i, j-1);
  return dp[i][j] = max(option1, option2);
}

int main() {
  freopen("in.txt","r", stdin);
 	freopen("out.txt","w", stdout);

  FOR(i,MAX) FOR(j,MAX) dp[i][j] = -1;

  cin >> n;
  v.resize(n, 0);
  FOR(i,n) {
    cin >> v[i];
  }
  cout << solve(0, n-1) << endl;

  return 0;
}
