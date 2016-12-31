#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
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

int n;
vector<vi> adjList;
vi visited;
vi dist;
int furthestX, X;
vi pathOfMaxDiameter;

void firstDFS(int u, int length)
{
    visited[u] = 1;
    if (length > furthestX) {
        X = u;
        furthestX = length;
    }
    for (int i = 0; i < adjList[u].size(); i++) {
        if (!visited[adjList[u][i]]) {
            firstDFS(adjList[u][i], length + 1);
        }
    }
}

void secondDFS(int u, vi path)
{
    visited[u] = 1;
    path.push_back(u);
    if (path.size() > pathOfMaxDiameter.size()) {
        pathOfMaxDiameter = path;
    }

    for (int i = 0; i < adjList[u].size(); i++) {
        if (!visited[adjList[u][i]]) {
            secondDFS(adjList[u][i], path);
        }
    }
}

void dfsDist(int u, int length)
{
    visited[u] = 1;
    dist[u] = length;
    for (int i = 0; i < adjList[u].size(); i++) {
        if (!visited[adjList[u][i]]) {
            dfsDist(adjList[u][i], length + 1);
        }
    }
}

/**
 * Helder Antunes
 * 10459 The Tree Root
 * Solution explained:
 *
 * Find the diameter of tree, D, and the path, P, that allows that diameter.
 * Find the diameter of tree is obtained with two dfs/bfs.
 * The first dfs/bfs begins with any vertex S and obtain the node more distant X.
 * The second dfs/bfs begin on X and obtains the path more larger.
 * The size of path is the diameter.
 *
 * One best root is P[D/2]. If D % 2 == 0, there is another best root: P[D/2-1].
 *
 * For worst roots, let X and Y be the beginning and end of P, respectively.
 * Worst roots are the nodes that dist D of X and Y.
 *
*/
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    while(cin >> n) {
        adjList.assign(n, vi());
        for(int i = 0; i < n; i++) {
            int nAdjNodes;
            cin >> nAdjNodes;
            for(int j = 0; j < nAdjNodes; j++) {
                int v;
                cin >> v;
                v--;
                adjList[i].push_back(v);
            }
        }

        furthestX = -1;
        visited.assign(n, false);
        firstDFS(0, 0);
        pathOfMaxDiameter.clear();
        visited.assign(n, false);
        secondDFS(X, vi());

        int Y = pathOfMaxDiameter[pathOfMaxDiameter.size()-1];
        int diameter = pathOfMaxDiameter.size() - 1;

        visited.assign(n, 0);
        dist.assign(n, INF);
        dfsDist(X, 0);
        set<int> worstRoots;
        for (int i = 0; i < n; i++) {
            if (dist[i] == diameter) {
                worstRoots.insert(i);
            }
        }
        visited.assign(n, 0);
        dist.assign(n, INF);
        dfsDist(Y, 0);
        for (int i = 0; i < n; i++) {
            if (dist[i] == diameter) {
                worstRoots.insert(i);
            }
        }
        worstRoots.insert(X);
        worstRoots.insert(Y);
        vi v_worstRoots(worstRoots.begin(), worstRoots.end());

        vi bestRoots;
        bestRoots.push_back(pathOfMaxDiameter[pathOfMaxDiameter.size()/2]);
        if (pathOfMaxDiameter.size() % 2 == 0) {
            bestRoots.push_back(pathOfMaxDiameter[pathOfMaxDiameter.size()/2-1]);
        }

        sort(bestRoots.begin(), bestRoots.end());
        sort(v_worstRoots.begin(), v_worstRoots.end());

        cout << "Best Roots  : ";
        for (int i = 0; i < bestRoots.size(); i++) {
            cout << bestRoots[i] + 1;
            if(i == bestRoots.size()-1) cout << endl;
            else cout << " ";
        }

        cout << "Worst Roots : ";
        for (int i = 0; i < v_worstRoots.size(); i++) {
            cout << v_worstRoots[i] + 1;
            if(i == v_worstRoots.size()-1) cout << endl;
            else cout << " ";
        }
    }

    return 0;
}
