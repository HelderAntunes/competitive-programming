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

int n, m;
int mat[MAX][MAX];
int dp[MAX][MAX];

int solve(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (j < 0 || j >= m) {
		return INF;
	}
	if (i == n) {
		return 0;
	}

	int option1 = mat[i][j] + solve(i+1, j-1);
	int option2 = mat[i][j] + solve(i+1, j);
	int option3 = mat[i][j] + solve(i+1, j+1);

	return dp[i][j] = min(min(option1, option2), option3);
}

int main() {
 // freopen("in.txt","r", stdin);
 //	freopen("out.txt","w", stdout);

 	for (int i = 0; i < MAX; i++) {
 		for (int j = 0; j < MAX; ++j)
 		{
 		 	dp[i][j] = -1;
 		}
 	}
 		
 	cin >> n >> m;
 	int val;
 	for (int i = 0; i < n; ++i)
 	{
 		for (int j = 0; j < m; ++j)
 		{
 			cin >> mat[i][j];
 		}
 	}

 	int res = INF;
 	for (int i = 0; i < m; ++i)
 	{
 		res = min(res, solve(0, i));
 	}

 	cout << res << endl;


  return 0;
}
