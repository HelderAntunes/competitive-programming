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

int t, n, u, v;
vector<pair<ll,ll> > sortedArray;
vector<ll> oriArray, ans, situa;
vector<vector<ll> > AdjList;

/**
 * Helder Antunes
 */
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    scanf("%d", &t);
    while(t--) {
        cin >> n;

        oriArray.assign(n, 0);
        sortedArray.assign(n, ii());
        for (int i = 0; i < n; i++) {
            scanf("%lld", &oriArray[i]);
            sortedArray[i] = pair<ll,ll>(oriArray[i], i);
        }
        sort(sortedArray.begin(), sortedArray.end());
        situa.assign(n, 0);
        for (int i = 0; i < n; i++) {
            situa[sortedArray[i].second] = i;
        }

        AdjList.assign(n, vector<ll>());
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &u, &v);
            u--;v--;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }

        ans.assign(n, n-1);
        for (int i = n-1; i >= 0; i--) {

            u = sortedArray[i].second;

            if (i == ans[i]) ans[i]--;

            for (int j = 0; j < AdjList[u].size(); j++) {
                v = AdjList[u][j];

                if (i == ans[situa[v]]) ans[situa[v]]--;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            if (ans[i] <= 0) printf("0");
            else printf("%d", sortedArray[ans[situa[i]]].second+1);
        }
        cout << endl;

    }


    return 0;
}
