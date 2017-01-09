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

int m, n, k;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(vector<vi>& AdjMat, int rowStart, int colStart) {

    AdjMat[rowStart][colStart] = 0;
    queue<ii> q;
    q.push(ii(rowStart, colStart));
    while(!q.empty()) {

        int row = q.front().first, col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i], newCol = col + dc[i];
            if (newRow >= 1 && newRow <= n && newCol >= 1 && newCol <= m && AdjMat[newRow][newCol] == INF) {
                AdjMat[newRow][newCol] = AdjMat[row][col] + 1;
                q.push(ii(newRow, newCol));
            }
        }

    }

}

/**
 * Helder Antunes
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);


    cin >> n >> m;
    cin >> k;

    while(k--) {

        int rm, cm, r1, c1, r2, c2;
        cin >> rm >> cm >> r1 >> c1 >> r2 >> c2;

        vector<vi> AdjMat1 = vector<vi>(n+1, vi(m+1, INF));
        vector<vi> AdjMat2 = vector<vi>(n+1, vi(m+1, INF));
        vector<vi> AdjMat3 = vector<vi>(n+1, vi(m+1, INF));

        bfs(AdjMat1, rm, cm);
        bfs(AdjMat2, r1, c1);
        bfs(AdjMat3, r2, c2);

        string ans = "NO";

        for (int i = 1; i <= n; i++) {

            if (AdjMat1[i][1] < AdjMat2[i][1] && AdjMat1[i][1] < AdjMat3[i][1]) {
                ans = "YES";
                break;
            }
            if (AdjMat1[i][m] < AdjMat2[i][m] && AdjMat1[i][m] < AdjMat3[i][m]) {
                ans = "YES";
                break;
            }

            if (i > m) continue;

            if (AdjMat1[1][i] < AdjMat2[1][i] && AdjMat1[1][i] < AdjMat3[1][i]) {
                ans = "YES";
                break;
            }
            if (AdjMat1[m][i] < AdjMat2[m][i] && AdjMat1[m][i] < AdjMat3[m][i]) {
                ans = "YES";
                break;
            }

        }
        cout << ans << endl;
    }

    return 0;
}
