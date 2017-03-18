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

typedef long long int ll;

int price[105];
int dp[105][50005];
int total = 0;
int n;
int solve(int i, int remain){
	if(dp[i][remain] != -1)
		return dp[i][remain];
	if(i == n || remain == 0){
		return 0;
	}
	if(price[i] > remain){
		return solve(i+1,remain);
	}
	int sol1 = solve(i+1,remain);
	int sol2 = price[i]+solve(i+1,remain-price[i]);
	return dp[i][remain] = max(sol1, sol2);
}

/*
 * helder antunes
 * 562 - Dividing coins
 *
 */
int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		memset(dp,-1,sizeof dp);
		total = 0;
		for(int i = 0;i < n;i++){
			cin >> price[i];
			total += price[i];
		}
		cout << total-2*solve(0,total/2) << "\n";
	}
	return 0;
}
