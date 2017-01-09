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

int item[205];
int n, q;
int d, m;
int dp[205][25][15];

int f(int i, ll sum, int taken){
	sum = (sum%d+d)%d;
	if(i == n){
		if(sum == 0 && taken == 0)return 1;
		return 0;
	}
	if(dp[i][sum][taken] != -1)
		return dp[i][sum][taken];
	else{
		dp[i][sum][taken] = f(i+1,sum,taken);
		if(taken > 0)
			dp[i][sum][taken] += f(i+1, sum+item[i],taken-1);
		return dp[i][sum][taken];
	}
}
/*
 * helder antunes
 * 10616 - Divisible Group Sums
 *
 */
int main()
{
	int set = 1;
	while(1){

		scanf("%d %d", &n, &q);
		if(n == 0 && q == 0) break;

		for(int i = 0;i < n;i++){
			scanf("%d", &item[i]);
		}

		printf("SET %d:\n", set);

		for(int i = 0;i < q;i++){
			scanf("%d %d", &d, &m);
			for(int i = 0;i < 205;i++)
				for(int j = 0;j < 25;j++)
					for(int k = 0;k < 15;k++)
						dp[i][j][k] = -1;
			printf("QUERY %d: %d\n", i+1, f(0,0,m));
		}

		set++;
	}




	return 0;
}
