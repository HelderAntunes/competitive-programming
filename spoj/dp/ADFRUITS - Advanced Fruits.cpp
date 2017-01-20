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

int dp[105][105], p[105][105];
string s1, s2;

int lcs(int i1, int i2) {

    if (i1 == 0 && i2 == 0) return 0;

    if (dp[i1][i2] != -1) return dp[i1][i2];

    if (s1[i1-1] == s2[i2-1]) {
        p[i1][i2] = 0;
        return dp[i1][i2] = 1 + lcs(i1-1, i2-1);
    }

    if (i1 == 0) {
        p[i1][i2] = 2;
        return dp[i1][i2] = lcs(i1, i2-1);
    }
    if (i2 == 0) {
        p[i1][i2] = 1;
        return dp[i1][i2] = lcs(i1-1, i2);
    }

    int option1 = lcs(i1-1, i2);
    int option2 = lcs(i1, i2-1);

    if (option1 > option2) {
        p[i1][i2] = 1;
        return dp[i1][i2] = option1;
    } else {
        p[i1][i2] = 2;
        return dp[i1][i2] = option2;
    }
}


/**
 * Helder Antunes
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    while(cin >> s1 >> s2) {
        memset(dp, -1, sizeof dp);

        lcs(s1.size(), s2.size());

        stack<char> s;
        int i1 = s1.size(), i2 = s2.size();
        while(i1 != 0 || i2 != 0) {
            if (i1 == 0) s.push(s2[--i2]);
            else if (i2 == 0) s.push(s1[--i1]);
            else {
                int option = p[i1][i2];
                if (option == 0) {s.push(s1[--i1]);i2--;}
                else if (option == 1) s.push(s1[--i1]);
                else if (option == 2) s.push(s2[--i2]);
            }
        }

        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << endl;

    }

    return 0;
}
