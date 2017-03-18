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

int t, w, n;
int price[35];
int value[35];
int dp[35][1009];
bool taken[35][1009];
bool x[35];

int solve(int i, int remain){
	if(dp[i][remain] != -1)
		return dp[i][remain];
	if(remain < 0)
		return -10000;
	if(i == n)
		return 0;
	int sol1 = solve(i+1, remain);
	int sol2 = value[i] + solve(i+1, remain-price[i]);
	if(sol2 > sol1){
		taken[i][remain] = true;
	}
	else
		taken[i][remain] = false;
	return dp[i][remain] = max(sol1, sol2);
}

/*
 * helder antunes
 * 990 - Diving for Gold
 *
 */
int main()
{
	int p;
	bool notFirst = false;
	while(1){
		if(!(cin >> t >> w))
			break;
		if(notFirst)
			cout << endl;
		notFirst = true;
		cin >> n;
		memset(dp, -1, sizeof dp);
		memset(taken, false, sizeof taken);
		memset(x,false,sizeof x);
		for(int i = 0;i < n;i++){
			cin >> p >> value[i];
			p *= 3*w;
			price[i] = p;
		}


		int maximum = solve(0,t);
		cout << maximum << endl;
		int remain = t;
		int count = 0;
		for(int i =0 ;i < n;i++){
			if(taken[i][remain]){
				remain -= price[i];
				x[i] = true;
				count++;
			}
		}
		cout << count << endl;
		for(int i = 0;i < n;i++){
			if(x[i])
				cout << price[i]/(3*w) << " " << value[i] << endl;
		}

		getchar();
	}

	return 0;
}
