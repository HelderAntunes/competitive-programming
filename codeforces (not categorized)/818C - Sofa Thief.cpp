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

int d, n, m;
vii sofas_x;
vii sofas_y;

int maximo(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int minimo(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int main() {
//	freopen("in.txt","r", stdin);
//	freopen("out.txt","w", stdout);

    scanf("%d\n%d %d\n", &d, &n, &m);
    for (int i = 0; i < d; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
        sofas_x.push_back(ii(x1, x2));
        sofas_y.push_back(ii(y1, y2));
    }
    int l, r, t, b;
    scanf("%d %d %d %d\n", &l, &r, &t, &b);

    vi a;
    vi leftH(d, -1);
    vi rightH(d, -1);
    vi topH(d, -1);
    vi bottomH(d, -1);

    a.assign(n+2, 0);

    for (int i = 0; i < d; i++) {
        int xmin = minimo(sofas_x[i].first, sofas_x[i].second);
        a[xmin]++;
    } 
    for (int i = 1; i < n+1; i++)
        a[i] += a[i-1];
    for (int i = 0; i < d; i++) {
        int xmax = maximo(sofas_x[i].first, sofas_x[i].second);
        int xmin = minimo(sofas_x[i].first, sofas_x[i].second);
        leftH[i] = a[xmax-1];
        if (xmax == xmin + 1) leftH[i]--;
    }

    a.assign(n+2, 0);

    for (int i = 0; i < d; i++) {
        int xmax = maximo(sofas_x[i].first, sofas_x[i].second);
        a[xmax]++;
    }
    for (int i = n-1; i >= 0; i--)
        a[i] += a[i+1];
    for (int i = 0; i < d; i++) {
        int xmax = maximo(sofas_x[i].first, sofas_x[i].second);
        int xmin = minimo(sofas_x[i].first, sofas_x[i].second);
        rightH[i] = a[xmin+1];
        if (xmax == xmin + 1) rightH[i]--;
    }

    a.assign(m+2, 0);

    for (int i = 0; i < d; i++) {
        int ymin = minimo(sofas_y[i].first, sofas_y[i].second);
        a[ymin]++;
    }
    for (int i = 1; i < m+1; i++) 
        a[i] += a[i-1];
    for (int i = 0; i < d; i++) {
        int ymax = maximo(sofas_y[i].first, sofas_y[i].second);
        int ymin = minimo(sofas_y[i].first, sofas_y[i].second);
        topH[i] = a[ymax-1];
        if (ymax == ymin + 1) topH[i]--;
    }

    a.assign(m+2, 0);

    for (int i = 0; i < d; i++) {
        int ymax = maximo(sofas_y[i].first, sofas_y[i].second);
        a[ymax]++;
    }
    for (int i = m-1; i >= 0; i--) 
        a[i] += a[i+1];
    for (int i = 0; i < d; i++) {
        int ymax = maximo(sofas_y[i].first, sofas_y[i].second);
        int ymin = minimo(sofas_y[i].first, sofas_y[i].second);
        bottomH[i] = a[ymin+1];
        if (ymax == ymin + 1) bottomH[i]--;
    }

    for (int i = 0; i < d; i++) {
      //  cout << leftH[i] << " " << rightH[i] << " " << topH[i] << " " << bottomH[i] << endl;
        if (leftH[i] == l &&
            rightH[i] == r &&
            topH[i] == t &&
            bottomH[i] == b) {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
	return 0;
}