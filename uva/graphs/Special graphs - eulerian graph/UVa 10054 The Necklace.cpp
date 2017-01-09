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

vi a;
vector<vii> AdjList;
list<ii> cyc;

void EulerTour(list<ii>::iterator i, int u) {
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (v.second) {
            AdjList[u][j].second = 0;
            for (int k = 0; k < (int)AdjList[v.first].size(); k++) {
                ii uu = AdjList[v.first][k];
                if (uu.first == u && uu.second) {
                    AdjList[v.first][k].second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i, ii(u,v.first)), v.first);
        }
    }
}

/**
 * Helder Antunes
 * 10054 The Necklace
 * Solution: Just print the euler tour/circuit
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    int t, Case = 1;
    scanf("%d", &t);
    while(t--) {

        int n, e1, e2;
        scanf("%d", &n);
        a.assign(51, 0);
        AdjList.assign(51, vii());
        cyc.clear();
        int A;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &e1, &e2);
            a[e1]++;
            a[e2]++;
            AdjList[e1].push_back(ii(e2,1));
            AdjList[e2].push_back(ii(e1,1));
            A = e1;
        }

        bool lost = false;
        for (int i = 0; i < 51; i++) {
            if (a[i] % 2 != 0) {
                lost = true;
                break;
            }
        }

        printf("Case #%d\n", Case++);

        if (lost) {
            printf("some beads may be lost\n");
        }
        else {
            EulerTour(cyc.begin(), A);
            cyc.reverse();
            for (list<ii>::iterator it = cyc.begin(); it != cyc.end(); it++)
                printf("%d %d\n", it->first, it->second);
        }

        if (t > 0)
            printf("\n");

    }


    return 0;
}
