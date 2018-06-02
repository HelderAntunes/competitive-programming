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
#define MAX             105

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef long long int ll;

int n;
int dp[MAX][MAX][2];

int solve(int i, int k, int lastBit) {
	if (dp[i][k][lastBit] != -1) {
		return dp[i][k][lastBit];
	}
	if (i == n) {
		if (k == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	if (k < 0) {
		return 0;
	}

	if (lastBit == 0) {
		int option1 = solve(i+1, k, 1);
		int option2 = solve(i+1, k, 0);
		return dp[i][k][lastBit] = option1 + option2;
	}

	if (lastBit == 1) {
		int option1 = solve(i+1, k-1, 1);
		int option2 = solve(i+1, k, 0);
		return dp[i][k][lastBit] = option1 + option2;
	}

}

int main() {
 // freopen("in.txt","r", stdin);
 //	freopen("out.txt","w", stdout);
 	int p;
 	cin >> p;
 	while (p--) {
 		int Case, k;
 		cin >> Case >> n >> k;
 		for (int i = 0; i < MAX; ++i)
 		{
 			for (int j = 0; j < MAX; ++j)
 			{
 				dp[i][j][0] = -1;
 				dp[i][j][1] = -1;
 			}
 		}
 		int res = solve(1, k, 0) + solve(1, k, 1);
 		cout << Case << " " << res << endl;
 	}
 	

  return 0;
}
