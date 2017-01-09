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



/*
 * helder antunes
 * UVA 11790 - Murcia's Skyline
 *
 */
int main()
{
	int t, n;
	int testCase = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> height(n);
		vector<int> weight(n);
		vector<int> lis(n);
		vector<int> lds(n);
		for(int i = 0;i < n;i++){
			scanf("%d", &height[i]);
		}
		for(int i = 0;i < n;i++){
			scanf("%d", &weight[i]);
		}

		//increasing
		for(int i = 0;i < n;i++){
			int sum = weight[i];
			for(int j = 0;j < i;j++){
				if(height[j] < height[i]){
					sum = max(sum, lis[j]+weight[i]);
				}
			}
			lis[i] = sum;
		}
		int maxInc = -1;
		for(int i = 0;i < n;i++){
			maxInc = max(maxInc, lis[i]);
		}

		//decreasing
		for(int i = 0;i < n;i++){
			int sum = weight[i];
			for(int j = 0;j < i;j++){
				if(height[j] > height[i]){
					sum = max(sum, lds[j]+weight[i]);
				}
			}
			lds[i] = sum;
		}
		int maxDec = -1;
		for(int i = 0;i < n;i++){
			maxDec = max(maxDec, lds[i]);
		}

		if(maxInc >= maxDec){
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", testCase, maxInc, maxDec);
		}
		else{
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", testCase, maxDec, maxInc);
		}
		testCase++;
	}

	return 0;
}
