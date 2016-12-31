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

/*
 * Helder Antunes
 * UVA 507: Jill rides again
 * Use Kadane's algorithm
 */
int main() {
    int t;
    int s;
    int rout = 1;

    scanf("%d", &t);
    while(t--){

        scanf("%d", &s);
        vector<int> a(s-1);
        for(int i = 0;i < s-1;i++){
            scanf("%d", &a[i]);
        }
        int ans = 0, sum = 0;
        int i_ans = 0, j_ans = 0;
        int i_sum = 0, j_sum = 0;

        for(int i = 0;i < s-1;i++){
            j_sum = i;
            sum += a[i];
            if(sum > ans){
                ans = sum;
                j_ans = i;
                i_ans = i_sum;
            }
            else if(sum == ans){
                if(j_sum-i_sum > j_ans-i_ans){
                    i_ans = i_sum;
                    j_ans = j_sum;
                }
                else if(j_sum-i_sum == j_ans-i_ans){
                    if(i_sum < i_ans){
                        i_ans = i_sum;
                        j_ans = j_sum;
                    }
                }
            }
            if(sum < 0){
                sum = 0;
                i_sum = i+1;
                j_sum = i+1;
            }
        }
        if(ans > 0){
            printf("The nicest part of route %d is between stops %d and %d\n", rout, i_ans+1, j_ans+2);
        }
        else{
            printf("Route %d has no nice parts\n", rout);
        }
        rout++;
    }
    return 0;
}
