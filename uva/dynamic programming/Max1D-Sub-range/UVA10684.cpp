#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int a[10009];

/*
 * helder antunes
 * UVA 10684: The jackpot
 *
 */
int main()
{
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0;i < n;i++){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        int cur = 0;
        for(int i = 0;i < n;i++){
            cur += a[i];
            if(cur > ans){
                ans = cur;
            }
            if(cur < 0){
                cur = 0;
            }
        }
        if(ans > 0){
            printf("The maximum winning streak is %d.\n", ans);
        }
        else{
            printf("Losing streak.\n");
        }
    }
    return 0;
}
