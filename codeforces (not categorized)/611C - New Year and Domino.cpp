#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int h, w, q;
vector<vector<char> > grid;
vector<vi> ver, hor;

int solve_ver(int r, int c) {
    if (r < 1 || r > h || c < 1 || c > w) return 0;
    if (ver[r][c] != -1) return ver[r][c];

    int atual = 0;
    if (r+1 <= h && grid[r][c] == '.' && grid[r+1][c] == '.') atual++;
    return ver[r][c] = solve_ver(r+1, c) + solve_ver(r, c+1) - solve_ver(r+1, c+1) + atual;
}

int solve_hor(int r, int c) {
    if (r < 1 || r > h || c < 1 || c > w) return 0;
    if (hor[r][c] != -1) return hor[r][c];

    int atual = 0;
    if (c+1 <= w && grid[r][c] == '.' && grid[r][c+1] == '.') atual++;
    return hor[r][c] = solve_hor(r+1, c) + solve_hor(r, c+1) - solve_hor(r+1, c+1) + atual;
}

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    scanf("%d %d\n", &h, &w);
    grid.assign(h+1, vector<char>(w+1));
    hor.assign(h+1, vi(w+1, -1));
    ver.assign(h+1, vi(w+1, -1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            scanf("%c", &grid[i][j]);
        scanf("\n");
    }

    solve_ver(1, 1);
    solve_hor(1, 1);

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        int ans = ver[r1][c1] + hor[r1][c1];
        if (r2 == h && c2 < w) ans -= hor[r1][c2] + ver[r1][c2+1];
        else if (c2 == w && r2 < h) ans -= ver[r2][c1] + hor[r2+1][c1];
        else if (r2 < h && c2 < w) ans -= hor[r1][c2] + ver[r1][c2+1] + ver[r2][c1] + hor[r2+1][c1] - ver[r2][c2+1] - hor[r2+1][c2];

        cout << ans << endl;
    }

    return 0;
}