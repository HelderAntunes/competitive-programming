#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define PI acos(-1)
#define VISITED 1
#define UNVISITED 0
#define PROCESSED 2

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n, m;
    vector<vi> mat;
    scanf("%d %d", &n, &m);
    mat.assign(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    vector<pair<char, int> > sol = vector<pair<char, int> >();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int minimoR = INT_MAX, minimoC = INT_MAX;
            for (int k = 0; k < n; k++)
                minimoC = min(minimoC, mat[k][j]);
            for (int k = 0; k < m; k++)
                minimoR = min(minimoR, mat[i][k]);

            if (m > n) {
                if (minimoR == 0) {
                    if (minimoC >= mat[i][j]) {
                        int sub = mat[i][j];
                        for (int k = 0; k < n; k++)
                            mat[k][j] -= sub;
                        for (int k = 0; k < sub; k++)
                            sol.push_back(make_pair('c', j));
                    }
                    else {
                        cout << -1 << endl;
                        return 0;
                    }
                }
                else {
                    for (int k = 0; k < m; k++) {
                        mat[i][k] -= minimoR;
                    }
                    for (int k = 0; k < minimoR; k++)
                            sol.push_back(make_pair('r', i));

                    if (mat[i][j] > 0) {
                        if (minimoC >= mat[i][j]) {
                            int sub = mat[i][j];
                            for (int k = 0; k < n; k++)
                                mat[k][j] -= sub;
                            for (int k = 0; k < sub; k++)
                                sol.push_back(make_pair('c', j));
                        }
                        else {
                            cout << -1 << endl;
                            return 0;
                        }
                    }
                }
            }
            else {
                if (minimoC == 0) {
                    if (minimoR >= mat[i][j]) {
                        int sub = mat[i][j];
                        for (int k = 0; k < m; k++)
                            mat[i][k] -= sub;
                        for (int k = 0; k < sub; k++)
                            sol.push_back(make_pair('r', i));
                    }
                    else {
                        cout << -1 << endl;
                        return 0;
                    }
                }
                else {
                    for (int k = 0; k < minimoC; k++)
                        sol.push_back(make_pair('c', j));
                    for (int k = 0; k < n; k++) {
                        mat[k][j] -= minimoC;
                    }
                    if (mat[i][j] > 0) {
                        if (minimoR >= mat[i][j]) {
                            int sub = mat[i][j];
                            for (int k = 0; k < m; k++)
                                mat[i][k] -= sub;
                            for (int k = 0; k < sub; k++)
                                sol.push_back(make_pair('r', i));
                        }
                        else {
                            cout << -1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i].first == 'r')
            cout << "row " << sol[i].second + 1 << endl;
        else
            cout << "col " << sol[i].second + 1 << endl;
    }

    return 0;
}