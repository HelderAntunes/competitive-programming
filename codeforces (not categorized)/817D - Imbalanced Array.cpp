#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
vi a;

ll find_minimus() {
    ll res = 0;
    vi L(n);
    vi R(n);

    stack<int> s = stack<int>();
    for (int i = 0; i < n; i++) {
        while(1) {
            if (s.empty()) {
                L[i] = -1;
                s.push(i);
                break;
            }
            int j = s.top();
            if (a[j] > a[i]) {
                s.pop();
            }
            else {
                L[i] = j;
                s.push(i);
                break;
            }
        }
    }

    s = stack<int>();
    for (int i = n-1; i >= 0; i--) {
        while(1) {
            if (s.empty()) {
                R[i] = -1;
                s.push(i);
                break;
            }
            int j = s.top();
            if (a[j] >= a[i]) {
                s.pop();
            }
            else {
                R[i] = j;
                s.push(i);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int left, right;
        if (L[i] == -1) left = i-0+1;
        else left = i - L[i];
        if (R[i] == -1) right = n-i;
        else right = R[i] - i;
        res += (ll)a[i] * (ll)left * (ll)right;
        //cout << left << " " << right << endl;
    }

    return res;
}

ll find_maximus() {
    ll res = 0;
    vi L(n);
    vi R(n);

    stack<int> s = stack<int>();
    for (int i = 0; i < n; i++) {
        while(1) {
            if (s.empty()) {
                L[i] = -1;
                s.push(i);
                break;
            }
            int j = s.top();
            if (a[j] < a[i]) {
                s.pop();
            }
            else {
                L[i] = j;
                s.push(i);
                break;
            }
        }
    }

    s = stack<int>();
    for (int i = n-1; i >= 0; i--) {
        while(1) {
            if (s.empty()) {
                R[i] = -1;
                s.push(i);
                break;
            }
            int j = s.top();
            if (a[j] <= a[i]) {
                s.pop();
            }
            else {
                R[i] = j;
                s.push(i);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int left, right;
        if (L[i] == -1) left = i-0+1;
        else left = i - L[i];
        if (R[i] == -1) right = n-i;
        else right = R[i] - i;
        res += (ll)a[i] * (ll)left * (ll)right;
        //cout << left << " " << right << endl;
    }

    return res;
}

int main() {
   // freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    scanf("%d", &n);
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ll maxi = find_maximus();
    ll mini = find_minimus();
   // cout << maxi << " " << mini << endl;
    cout << maxi - mini << endl;

    return 0;
}