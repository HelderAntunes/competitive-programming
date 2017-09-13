#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        ll multi = 1LL * (ll) a * (ll) b;
        ll res = (ll)pow(multi, 1/3.);
        if (pow(res, 3) != multi){
           res++;
        }
        if (res * res * res == multi) {
            if (a%res == 0 && b%res == 0)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}