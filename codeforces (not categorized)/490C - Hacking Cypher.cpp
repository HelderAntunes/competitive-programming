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

  string s;
  cin >> s;
  ll a, b;
  cin >> a >> b;
  VL diva;
  VL divb;
  ll ra = ((ll)s[0]-'0') % a;
  diva.push_back(ra);
  for (int i = 1; i < s.size(); i++) {
    ll digit = ((ll)s[i]-'0') % a;
    ra = ((ra * 10 % a) + digit) % a;
    diva.push_back(ra);
  }

  ll rb = ((ll)s[s.size()-1]-'0') % b;
  divb.push_back(rb);
  ll mul = 10;
  for (int i = s.size()-2; i >= 0; i--) {
    ll digit = ((ll)s[i]-'0') % b;
    rb = (rb + mul * digit % b)%b;
    mul = mul * 10 % b;
    divb.push_back(rb);
  }
  reverse(ALL(divb));

  bool yes = false;
  for (size_t i = 0; i < s.size()-1; i++) {
    //  cout << diva[i] << " " << divb[i+1] << endl;
    if (diva[i] == 0 && divb[i+1] == 0 && s[i+1] != '0') {
      cout << "YES" << endl;
      for (size_t j = 0; j <= i; j++) {
        cout << s[j];
      }
      cout << endl;
      for (size_t j = i+1; j < s.size(); j++) {
        cout << s[j];
      }
      cout << endl;
      yes = true;
      break;
    }
  }
  if(!yes) {
      cout << "NO\n";
  }
  return 0;
}
