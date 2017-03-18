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

int a[301][301];

/*
 * helder antunes
 * UVA 10827 - Maximum sum on a torus
 *
 */
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int minimo = -75*75*101;
        int N;
        scanf("%d", &N);
        for(int i = 0;i < 2*N;i++)
        	for(int j = 0;j < 2*N;j++){
        		if(i < N && j < N){
        			scanf("%d", &a[i][j]);
        			a[i+N][j] = a[i][j+N] = a[i+N][j+N] = a[i][j];
        		}
        		if(i>0)	a[i][j] += a[i-1][j];
        		if(j>0)	a[i][j] += a[i][j-1];
        		if(i>0&&j>0)a[i][j] -= a[i-1][j-1];
        	}
        int maxSubRect = minimo;
        for(int i = 0;i < N;i++)for(int j = 0;j< N;j++)
        for(int k = i;k < i+N;k++)for(int l = j;l < j+N;l++){
            int subRect = a[k][l];
            if(i > 0) subRect -= a[i-1][l];
            if(j > 0) subRect -= a[k][j-1];
            if(i > 0 && j > 0) subRect += a[i-1][j-1];
            maxSubRect = max(maxSubRect, subRect);
        }
        printf("%d\n", maxSubRect);
    }

    return 0;
}
