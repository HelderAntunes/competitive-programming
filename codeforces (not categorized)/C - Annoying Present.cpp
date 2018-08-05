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
#define MAX             2505

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef long long int ll;

ll sum_first_integers(ll n) {
	return n * (n+1) / (ll)2;
}

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt","w", stdout);

  ll n, m, x, d, negSum, posSum;
  ll res = 0;
  cin >> n >> m;
  if (n%2 == 0) {
  	negSum = sum_first_integers(n/2) + sum_first_integers(n/2-1);
  	posSum = sum_first_integers(n-1);
  }
  else {
  	negSum = sum_first_integers(n/2)*2;
  	posSum = sum_first_integers(n-1);
  }

  for (int i = 0; i < m; ++i) {
  	cin >> x >> d;
  	res += x * n;
  	if (d > 0) {
  		res += posSum * d;
  	}
  	else {
  		res += negSum * d;
  	}
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  cout << (double)res / (double)n << endl;
  return 0;
}
