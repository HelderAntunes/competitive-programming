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

int values[] = {1,5,10,25,50};

long long int dp[30005] = {0};

long long int solve(){
	dp[0] = 1;
	for(int i = 0;i < 5;i++){
		int c = values[i];
		for(int j = c;j < 30001;j++){
			dp[j] += dp[j-c];
		}
	}
	return  0;
}
/*
 * helder antunes
 * 357 - Let Me Count The Ways
 */
int main()
{
    int n;
    solve();
    while(1){
        if(cin >> n){
            long long int sol = dp[n];
            if(sol == 1){
                cout << "There is only 1 way to produce " << n  << " cents change.\n";
            }
            else{
                cout << "There are " << sol << " ways to produce " << n << " cents change.\n";
            }
        }
        else
            break;

    }
    return 0;
}
