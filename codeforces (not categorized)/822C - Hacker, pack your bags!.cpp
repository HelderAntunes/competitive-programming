#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, x;
vi lefts, rights, costs, minimus;

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    scanf("%d %d", &n, &x);
    lefts.assign(n, 0);
    rights.assign(n, 0);
    costs.assign(n, 0);
    minimus.assign(200005, INT_MAX);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &lefts[i], &rights[i], &costs[i]);
    }

    vii leftOrder, rightOrder;
    for (int i = 0; i < n; i++) {
        leftOrder.push_back(ii(lefts[i], i));
        rightOrder.push_back(ii(rights[i], i));
    }
    sort(leftOrder.begin(), leftOrder.end());
    sort(rightOrder.begin(), rightOrder.end());

    int lastRight = 0;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int voucher = leftOrder[i].second;

        while(rightOrder[lastRight].first < lefts[voucher]) {
            int otherVoucher = rightOrder[lastRight].second;
            int dur = rights[otherVoucher] - lefts[otherVoucher] + 1;
            minimus[dur] = min(minimus[dur], costs[otherVoucher]);
            lastRight++;
        }

        int dur = rights[voucher] - lefts[voucher] + 1;
        int otherDur = x - dur;
        if (otherDur >= 1) {
            if (minimus[otherDur] != INT_MAX) {
                res = min(res, minimus[otherDur] + costs[voucher]);
            }
        }
    }

    res = res == INT_MAX ? -1:res;
    cout << res << endl;
    return 0;
}