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

typedef long long int ll;

int a[105][105];

/*
 * helder antunes
 * UVA 11951 - Area
 *
 */
int main()
{
    int t;
    scanf("%d", &t);
    int test = 1;
    while(t--){
    	int n, m, ko;
    	scanf("%d %d %d", &n, &m, &ko);

    	for(int i = 0;i < n;i++){
    		for(int j = 0;j< m;j++){
    			scanf("%d", &a[i][j]);
    			if(i > 0) a[i][j] += a[i-1][j];
    			if(j > 0) a[i][j] += a[i][j-1];
    			if(i>0 && j>0) a[i][j] -= a[i-1][j-1];
    		}
    	}
    	long long int ans_area = 0;
    	long long int ans_cost = 0;
    	for(int i = 0;i < n;i++)for(int j = 0;j < m;j++)
    		for(int k = i;k < n;k++)for(int l= j;l < m;l++){
    			long long int sum = a[k][l];
    			if(i>0) sum -= (ll)a[i-1][l];
    			if(j>0) sum -= (ll)a[k][j-1];
    			if(i > 0 && j>0) sum += (ll)a[i-1][j-1];
    			if(sum <= (ll)ko){
    				long long int area = (ll)(k-i+1)*(ll)(l-j+1);
    				if((area > ans_area) || (area == ans_area && sum < ans_cost)){
    					ans_cost = sum;
    					ans_area = area;
    				}
    			}
    		}
    	printf("Case #%d: %lld %lld\n", test, ans_area, ans_cost);
        test++;
    }

    return 0;
}
