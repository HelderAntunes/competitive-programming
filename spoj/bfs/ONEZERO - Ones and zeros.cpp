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

vector<int> parent;
vector<int> value;


/**
 * Helder Antunes
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        queue<int> q;
        parent.assign(20000, -1);
        value.assign(20000, -1);

        int currState = 1, newState;
        value[currState] = 1;
        q.push(currState);

        while(!q.empty()) {

            currState = q.front();
            q.pop();

            newState = (currState * 10) % n;
            if (value[newState] == -1) {
                parent[newState] = currState;
                value[newState] = 0;
                q.push(newState);
                if (newState == 0) break;
            }

            newState = (currState * 10 + 1) % n;
            if (value[newState] == -1) {
                parent[newState] = currState;
                value[newState] = 1;
                q.push(newState);
                if (newState == 0) break;
            }

        }

        currState = newState;
        stack<int> s;
        while(parent[currState] != -1) {
            s.push(value[currState]);
            currState = parent[currState];
        }
        s.push(value[currState]);

        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << endl;

    }

    return 0;
}
