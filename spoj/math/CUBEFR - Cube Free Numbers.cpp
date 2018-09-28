#include <bits/stdc++.h>

using namespace std;
#define MK              make_pair
#define PB              push_back
#define ALL(v)          (v).begin() , (v).end()
#define Set(v,x)        memset(  v , x , sizeof(v))
#define contain(Set,i)  ( (Set) & two(i) )
#define __join(a,b)     a##b
#define foreach(c, i)   for(__typeof((c).begin())i=(c).begin(),__join(i,__end)=(c).end();i!=__join(i,__end);i++)

#define FOR(i,n)        for (int i = 0 ; i < (n) ; i++)
#define REP(i, b, e) 	  for(typeof(e) i=b; i!=e; ++i)
#define INF             100000000
#define EPS             1e-6
#define MAX             1000005
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

bool isprime[MAX];
int primes[MAX] , pCount = 1;
int pos[MAX];
void doSieve()
{
   int i, j;
   memset(isprime , true , sizeof(isprime));
   isprime[1] = true;

   for (int i = 2; i <= 102; i++) {
     int cube = i*i*i;
     for (int j = 1; j * cube < MAX; j++) {
       isprime[j*cube] = false;
     }
   }

   primes[0] = 1;
   pos[1] = 0;
   for(i = 2 ; i < MAX ; i++)
       if(isprime[i]) {
          primes[pCount] = i;
          pos[i] = pCount;
          pCount++;
      }
}

int main() {
  // freopen("in.txt","r", stdin);
  // freopen("out.txt","w", stdout);
  doSieve();

  int t, Case = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (!isprime[n]) {
      cout << "Case " << Case << ": Not Cube Free" << endl;
    } else {
      cout << "Case " << Case << ": " <<  pos[n]+1 << endl;
    }
    Case++;
  }

  return 0;
}
