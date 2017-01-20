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

ii start;
int M, R, C;
vector<vector<char> > AdjMat;
vii shops;
vector<vi> dist;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};

/**
 * Helder Antunes
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    cin >> M;
    while(M--) {

        cin >> R >> C;
        dist.assign(R, vi(C, INF));
        AdjMat.assign(R, vector<char>(C));
        shops.clear();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                cin >> AdjMat[i][j];

                if (AdjMat[i][j] == 'C') {
                    dist[i][j] = 0;
                    start = ii(i, j);
                }
                else if (AdjMat[i][j] == 'S') {
                    shops.push_back(ii(i, j));
                }

            }
        }

        queue<ii> q;
        q.push(start);
        while(!q.empty()) {
            ii u = q.front();
            q.pop();
            int cR = u.first, cC = u.second;

            for (int i = 0; i < 4; i++) {

                int nR = cR + dr[i];
                int nC = cC + dc[i];

                if (nR >= 0 && nR < R && nC >= 0 && nC < C && AdjMat[nR][nC] != '#' && dist[nR][nC] == INF) {
                    dist[nR][nC] = dist[cR][cC] + 1;
                    q.push(ii(nR, nC));
                }

            }
        }

        int maxDist = -1, indMaxShop;
        for (int i = 0; i < shops.size(); i++) {
            if (dist[shops[i].first][shops[i].second] > maxDist) {
                maxDist = dist[shops[i].first][shops[i].second];
                indMaxShop = i;
            }
        }

        int ans = 60 + maxDist;
        for (int i = 0; i < shops.size(); i++) {

            if (i == indMaxShop) continue;

            int cDist = dist[shops[i].first][shops[i].second];
            ans += 60 + 2 * cDist;
        }
        cout << ans << endl;

    }

    return 0;
}
