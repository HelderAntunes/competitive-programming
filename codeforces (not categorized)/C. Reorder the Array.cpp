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

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt","w", stdout);

  int n;
  cin >> n;
  VI a(n);
  for (int i = 0; i < n; ++i) {
  	cin >> a[i];
  }
  sort(a.begin(), a.end());

  int maxCount = 0;
  for (int i = 0; i < n;) {
  	int count = 0;
  	int j = i;
  	while (j < n && a[i] == a[j]) {
  		count++;
  		j++;
  	}

  	maxCount = max(maxCount, count);
  	i = j;
  }

  cout << n-maxCount << endl;

  return 0;
}
