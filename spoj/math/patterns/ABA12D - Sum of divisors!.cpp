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

bool isprime(int x)
{
	bool check;
	int i;
	check=true;
	for(i=2;i<=ceil(sqrt((double)x));i++)
		if(x%i==0)
		{
			check=false;
			break;
		}
	return check;
}

int sumofdivisors(int x)
{
	int ans=0,i;
	for(i=1;i<=x;i++)
		if(x%i==0)
			ans=ans+i;
	return ans;
}

int a[100] = {2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 
						4096, 5041, 7921, 10201, 15625, 17161, 27889, 
						28561, 29929, 65536, 83521, 85849, 146689, 262144, 
						279841, 458329, 491401, 531441, 552049, 579121, 597529, 
						683929, 703921, 707281, 734449, 829921};

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt","w", stdout);
  int t;cin >> t;
  while(t--) {
  	int a_, b;
  	cin >> a_ >> b;
  	int d = 0;
  	for (int i = 0; i < 37; ++i)
  	{
  		if (a[i] >= a_ && a[i] <= b)
  			d++;
  	}
  	cout << d << endl;
  }

  return 0;
}
