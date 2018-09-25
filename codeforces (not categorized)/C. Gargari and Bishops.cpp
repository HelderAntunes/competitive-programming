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
#define MAX             100000
#define MOD             1000000007
#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef long long int ll;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef pair<pair<int,int>,int> PIII;

int main() {
  freopen("in.txt","r", stdin);
  //freopen("out.txt","w", stdout);

  int n;
  scanf("%d", &n);
  vector<VL> a(n, VL(n));
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      scanf("%lld", &a[i][j]);
    }
  }

  VL sumD1 = VL(2*n-1, 0);
  VL sumD2 = VL(2*n-1, 0);
  for (size_t i = 0; i < 2*n-1; i++) {
    int y = i < n? 0:i-n+1;
    int x = i < n? i:n-1;
    while (x>=0 && y>=0 && x<n && y <n) {
      sumD1[i] += a[y][x];
      x--;
      y++;
    }
    //cout << sumD1[i] << " ";
  }
  //cout << endl;
  for (size_t i = 0; i < 2*n-1; i++) {
    int y = i < n? n-i-1:0;
    int x = i < n? 0:i-n+1;
    while (x>=0 && y>=0 && x<n && y <n) {
      sumD2[i] += a[y][x];
      x++;
      y++;
    }
    //cout << sumD2[i] << " ";
  }
  //cout << endl;

  vector<VL> sumT(n, VL(n));
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      int d1 = i+j;
      int d2 = j + (n-i-1);
      sumT[i][j] = sumD1[d1] + sumD2[d2] - a[i][j];
      //cout << sumT[i][j] << " ";
    }
    //cout << endl;
  }

  ll maxB = -1, maxW = -1;
  pair<ll,ll> solB, solW;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if ((i+j)%2 == 0) { // w
        if (sumT[i][j] >= maxW) {
          maxW = sumT[i][j];
          solW = pair<ll, ll>(i+1,j+1);
        }
      } else { // b
        if (sumT[i][j] >= maxB) {
          maxB = sumT[i][j];
          solB = pair<ll, ll>(i+1,j+1);
        }
      }
    }
  }

  cout << maxB + maxW << endl;
  cout << solB.first << " " << solB.second << " " << solW.first << " " << solW.second << endl;

  return 0;
}
