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
#include <iomanip>
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
#define MAX             10000005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef long long int ll;

int main() {
  freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  int n;
  cin >> n;
  vector<vector<ll> > a = vector<vector<ll> >(2, vector<ll>(n+1, 0));
  for (int i = 0; i < 2; ++i)
  {
  	for (int j = 0; j < n; ++j)
  	{
  		cin >> a[i][j];
  	}
  }

  vector<vector<ll> >sum123(2, vector<ll>(n+1, 0)), sum321(2, vector<ll>(n+1, 0)), sum111(2, vector<ll>(n+1, 0));
  for (int i = 0; i < 2; ++i)
  {
  	for (int j = n-1; j >= 0; --j)
  	{
  		sum123[i][j] = sum123[i][j+1] + (j+1)*1LL*a[i][j];
  		sum111[i][j] = sum111[i][j+1] + a[i][j];
  		sum321[i][j] = sum321[i][j+1] + (n-j)*1LL*a[i][j];
  	}
  }

  ll sol = 0, sum = 0;
  for (int i = 0, j = 0; i < n; ++i, j ^= 1)
  {
  	ll sum2 = sum;
  	sum2 += sum123[j][i] + i * 1LL * sum111[j][i];
  	sum2 += sum321[j^1][i] + (i + n) * 1LL * sum111[j^1][i];
  	sol = max(sol, sum2);

  	sum += a[j][i] * 1LL * (i + i + 1);
  	sum += a[j^1][i] * 1LL * (i + i + 2);
  }

  for (int i = 0; i < n; ++i)
  {
  	sol -= a[0][i] + a[1][i];
  }

  cout << sol << endl;

  return 0;
}
