#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
#include <fstream>
#include <map>
#include <functional>
#include <sstream>
#include <bitset>
#include <list>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define INF2 2e9
#define PI acos(-1)
#define VISITED 1
#define UNVISITED 0
#define PROCESSED 2

int t;
string s;
int dp[6105][6105];

int solve(int l, int r) {

    if (dp[l][r] != -1) return dp[l][r];

    if (l == r) return 0;
    if (l == r - 1 && s[l] == s[r]) return 0;

    if (s[l] == s[r]) return dp[l][r] = solve(l+1, r-1);

    return dp[l][r] = min(solve(l+1,r), solve(l,r-1)) + 1;
}

/**
 * Helder Antunes
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    cin >> t;

    while(t--) {
        cin >> s;
        memset(dp, -1, sizeof dp);
        cout << solve(0, s.size()-1) << endl;
    }

    return 0;
}
