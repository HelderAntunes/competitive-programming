#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ll> ill;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define PI acos(-1)
#define VISITED 1
#define UNVISITED 0
#define PROCESSED 2

int main() {
	//freopen("in.txt","r", stdin);
	//freopen("out.txt","w", stdout);
  int n;
  scanf("%d\n", &n);
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++) {
    scanf("%lld\n", &a[i]);
  }

  set<lli> b;
  for (int i = 0; i < n; i++) {
    b.insert(lli(a[i], i));
  }
  set<ill> c;

  while (true) {
    if (b.size() == 1) {
      set<lli>::iterator it;
      lli first = *b.begin();
      c.insert(ill(first.second, first.first));
      break;
    }

    set<lli>::iterator it = b.begin();
    lli first = *it++;
    lli second = *it;

    if (first.first != second.first) {
      c.insert(ill(first.second, first.first));
      b.erase(b.begin());
    }
    else {
      b.erase(b.begin());
      b.erase(b.begin());
      second.first *= 2;
      b.insert(lli(second.first, second.second));
    }
  }

  printf("%d\n", (int)c.size());
  for (set<ill>::iterator it = c.begin(); it != c.end(); it++) {
    printf("%lld ", (*it).second);
  }
  printf("\n");

  return 0;
}
