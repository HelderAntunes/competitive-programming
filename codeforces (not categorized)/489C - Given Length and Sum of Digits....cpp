#include <bits/stdc++.h>

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

int exp10(int e) {
  int res = 1;
  for (size_t i = 0; i < e; i++) {
    res *= 10;
  }
  return res;
}

int main() {
  freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);

  int m, s;
  cin >> m >> s;
  int minSum = m == 1? 0: 1;
  int maxSum = m * 9;
  //cout << minSum << " " << maxSum << endl;
  if (s > maxSum || s < minSum) {
    cout << "-1 -1" << endl;
    return 0;
  }

  VI minRes(m, 0);
  minRes[0] = 1;
  if (1 > s) {
    minRes[0] = 0;
  }
  int currSum = minRes[0];
  int ind = m-1;
  while (currSum < s && ind >= 0) {
    if (ind == 0) currSum--;
    int digit = 9;
    if (currSum + 9 > s) digit = s - currSum;
    minRes[ind] = digit;
    currSum += digit;
    ind--;
  }
  for (size_t i = 0; i < m; i++) {
    cout << minRes[i];
  }
  cout << " ";

  VI maxRes(m, 0);
  maxRes[0] = 9;
  ind = 1;
  if (9 > s) maxRes[0] = s;
  currSum = maxRes[0];
  while (currSum < s && ind < m) {
    int digit = 9;
    if (currSum + 9 > s) {
      digit = s - currSum;
    }
    maxRes[ind] = digit;
    currSum += digit;
    ind++;
  }
  for (size_t i = 0; i < m; i++) {
    cout << maxRes[i];
  }
  cout << endl;
  return 0;
}
