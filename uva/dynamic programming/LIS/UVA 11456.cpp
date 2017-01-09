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

int a[2009];
int lis[2009];
int lds[2009];

struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const
	{return lhs>rhs;}
};

int LIS(int a[],int init, int n, int v){
	set<int> st; set<int>::iterator it; st.clear();
	for(int i=init;i<n;i++){
		if(a[i] <= v)
			continue;
		st.insert(a[i]); it = st.find(a[i]);
		it++; if(it != st.end()) st.erase(it);
	}
	return st.size() + 1;
}

int LDS(int a[],int init, int n, int v){
	set<int, classcomp> st; set<int>::iterator it; st.clear();
	for(int i=init;i<n;i++){
		if(a[i] >= v)
			continue;
		st.insert(a[i]); it = st.find(a[i]);
		it++; if(it != st.end()) st.erase(it);
	}
	return st.size() + 1;
}

/*
 * helder antunes
 * UVa 11456 - Trainsorting
 *
 */
int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < n;i++){
			scanf("%d", &a[i]);
		}

		for(int i = n-1;i >= 0;i--){
			lis[i] = 1;
			for(int j = i+1;j < n;j++){
				if(a[j]>a[i]){
					lis[i] = max(lis[i], lis[j]+1);
				}
			}
		}

		for(int i = n-1;i >= 0;i--){
			lds[i] = 1;
			for(int j = i+1;j < n;j++){
				if(a[j]<a[i]){
					lds[i] = max(lds[i], lds[j]+1);
				}
			}
		}

		int maximum = 0;
		for(int i = 0;i < n;i++){
			maximum = max(lds[i]+lis[i]-1, maximum);
		}
		printf("%d\n", maximum);
	}

	return 0;
}
