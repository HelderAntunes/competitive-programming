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
#define REP(i, b, e)    for(typeof(e) i=b; i!=e; ++i)
#define INF             1000000
#define EPS             1e-6
#define MAX             40005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef long long int ll;

int t, a, b, c;
int gcd(int a, int b)
{
    int c;
    while(b !=0 )
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt","w", stdout);
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &a, &b, &c);
    if (c > a && c > b) {
      cout << -1 << endl;
      continue;
    }
    if (c % gcd(a, b) != 0) {
      cout << -1 << endl;
      continue;
    }

    int al = 0, bl = 0, sol1 = 0;
    while(al != c && bl != c) {
      if (al == 0) {
        al = a;
        sol1++;
      }
      else if (bl == b) {
        bl = 0;
        sol1++;
      }
      else {
        int aux = min(al, b-bl);
        al -= aux;
        bl += aux;
        sol1++;
      }
    }

    al = 0, bl = 0; 
    int sol2 = 0;
    while(al != c && bl != c) {
      if (bl == 0) {
        bl = b;
        sol2++;
      }
      else if (al == a) {
        al = 0;
        sol2++;
      }
      else {
        int aux = min(bl, a-al);
        bl -= aux;
        al += aux;
        sol2++;
      }
    }
    cout << min(sol1, sol2) << endl;

  }

  return 0;
}
