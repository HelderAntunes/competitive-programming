#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ll> ill;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9
#define PI acos(-1)

int n;
int sizeStr = -1;
string strings[111111]; 
vector<ii> pares;

int main() {
//	freopen("in.txt","r", stdin);
//	freopen("out.txt","w", stdout);


    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        cin >> strings[i];
        int k; scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v; scanf("%d", &v);
            pares.push_back(ii(v, i));
            int ssize = strings[i].size();
            sizeStr = max(sizeStr, v + ssize - 1);
        }
    }

    sort(pares.begin(), pares.end());
    int desconhecido = 1;
    for (int i = 0; i < pares.size() && desconhecido <= sizeStr; i++) {
        int ini = pares[i].first;
        int fin = strings[pares[i].second].size() + ini - 1;

        if (ini > desconhecido) {
            for (int j = desconhecido; j < ini; j++)
                cout << 'a';
            for (int j = ini; j <= fin; j++) {
                cout << strings[pares[i].second][j-ini];
            }
            desconhecido = fin+1;
        }
        else {
            if (fin < desconhecido) {
                continue;
            }
            else {
                if (ini <= desconhecido && fin >= desconhecido) {
                    for (int j = desconhecido; j <= fin; j++) {
                        cout << strings[pares[i].second][j-ini];
                    }
                    desconhecido = fin + 1;
                }
            }
        }
    }

    cout << endl;

	return 0;
}
