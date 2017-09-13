#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n;
    cin >> n;
    string s;
    int val;
    int res = 0;
    int wait = 1;
    stack<int> pilha;
    for (int i = 0; i < 2*n; i++) {
        cin >> s;
        if (s == "add") {
            cin >> val;
            pilha.push(val);
        } else {
            if (!pilha.empty()) {
                val = pilha.top();
                pilha.pop();
                if (wait != val) {
                    res++;
                    while(!pilha.empty())
                        pilha.pop();
                }
            }
            wait++;
        }
    }
    cout << res << endl;

    return 0;
}