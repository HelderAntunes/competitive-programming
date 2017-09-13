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

vector<vi> ans;

int main() {
   // freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n, q;
    string s;

    scanf("%d", &n);
    cin >> s;
    ans = vector<vi>(26, vi(n+1, 0));

    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < n; i++) {
            int numReplaces = 0;
            for (int j = i; j < n; j++) {
                int ch = (int)s[j] - (int)'a';
                if (ch != c) numReplaces++;
                ans[c][numReplaces] = max(ans[c][numReplaces], j-i+1);
            }
        }

        for (int i = 1; i <= n; i++) ans[c][i] = max(ans[c][i], ans[c][i-1]);
    }

    getchar();
    scanf("%d", &q);
    int m;
    char c;
    for (int i = 0; i < q; i++) {
        scanf("%d %c", &m, &c);
        int ch = (int)c - (int)'a';
        printf("%d\n", ans[ch][m]);
    }

    return 0;
}