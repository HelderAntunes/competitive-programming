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

bool isPrime(int n) {
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

vi dist;
int a, b;

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

        cin >> a >> b;

        if (a == b) {
            cout << 0 << endl;
            continue;
        }

        dist.assign(10000, INF);
        dist[a] = 0;

        queue<int> q;
        q.push(a);
        while(!q.empty()) {

            int state = q.front();
            q.pop();

            int u = state % 10;
            int d = (state / 10) % 10;
            int c = (state / 100) % 10;
            int m = (state / 1000) % 10;

            for (int i = 0; i <= 9; i++) {

                if (i != u) {
                    int no1 = m*1000+c*100+d*10+i;
                    if (dist[no1] == INF && isPrime(no1)) {
                        dist[no1] = dist[state] + 1;
                        q.push(no1);
                        if (no1 == b) break;
                    }
                }

                if (i != d) {
                    int no2 = m*1000+c*100+i*10+u;
                    if (dist[no2] == INF && isPrime(no2)) {
                        dist[no2] = dist[state] + 1;
                        q.push(no2);
                        if (no2 == b) break;
                    }
                }

                if (i != c) {
                    int no3 = m*1000+i*100+d*10+u;
                    if (dist[no3] == INF && isPrime(no3)) {
                        dist[no3] = dist[state] + 1;
                        q.push(no3);
                        if (no3 == b) break;
                    }
                }

                if (i > 0 && i != m) {
                    int no4 = i*1000+c*100+d*10+u;
                    if (dist[no4] == INF && isPrime(no4)) {
                        dist[no4] = dist[state] + 1;
                        q.push(no4);
                        if (no4 == b) break;
                    }
                }
            }

        }

        if (dist[b] == INF)
            cout << "Impossible" << endl;
        else
            cout << dist[b] << endl;
    }
    return 0;
}
