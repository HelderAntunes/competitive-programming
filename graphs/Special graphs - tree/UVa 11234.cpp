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

vector<vi> AdjList;
int root;


/**
 * Helder Antunes
 * 11234 Expressions
 * Solution: transform post-order traversal (reverse polish notation)
 * to level-order traversal (essentially BFS).
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        string s;
        cin >> s;
        AdjList.assign(10000, vi(0));
        stack<int> stck;
        root = s.size() - 1;

        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i])) {
                stck.push(i);
            } else {
                int operand1 = stck.top();
                stck.pop();
                int operand2 = stck.top();
                stck.pop();

                AdjList[i].push_back(operand1);
                AdjList[i].push_back(operand2);
                AdjList[operand1].push_back(i);
                AdjList[operand2].push_back(i);

                stck.push(i);
            }
        }

        string ans;
        vi d(10000, INF);
        d[root] = 0;
        queue<int> q;
        q.push(root);
        ans += s[root];
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j = AdjList[u].size()-1; j >= 0; j--) {
                int v = AdjList[u][j];
                if (d[v] == INF) {
                    d[v] = d[u] + 1;
                    q.push(v);
                    ans += s[v];
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

    }

    return 0;
}
