#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int conv[41];
int info[41];
int S, m;
int dp[41][301][301];

int solve(int i, int x, int y){
	double value = sqrt(x*x+y*y);
	if(value == S)
		return 0;
	if(value > S)
		return 10000;
	if(i == m){
		return 10000;
	}
	if(dp[i][x][y] != -1)
		return dp[i][x][y];
	return dp[i][x][y] = min(1+solve(i, x+conv[i], y+info[i]), solve(i+1,x,y));
}
/*
 * helder antunes
 * 10306 - e-Coins
 */
int main()
{
	int t;
	cin >> t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin >> m >> S;
		for(int i = 0;i < m;i++){
			cin >> conv[i] >> info[i];
		}
		int coinsUsed = solve(0,0,0);
		if(coinsUsed >= 10000){
			cout << "not possible\n";
		}
		else
			cout << coinsUsed << endl;

	}
    return 0;
}
