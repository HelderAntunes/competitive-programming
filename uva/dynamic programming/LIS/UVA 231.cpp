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

struct menor{
	bool operator() (const int& lhs, const int& rhs) const
	  {return lhs>rhs;}
};

int LDS(vector<int>& a){
	set<int, menor> st; set<int, menor>::iterator it; st.clear();
	for(size_t i=0;i<a.size();i++){
		st.insert(a[i]); it = st.find(a[i]);
		it++; if(it != st.end()) st.erase(it);
	}
	return st.size();
}

/*
 * helder antunes
 * 231 - Testing the CATCHER
 *
 */
int main()
{
	int n;
	int testCase = 1;

	while(1){
		scanf("%d", &n);
		if(n == -1)
			break;
		vector<int> a;
		a.push_back(n);
		while(1){
			scanf("%d", &n);
			if(n == -1)
				break;
			a.push_back(n);
		}
		if(testCase > 1)
			printf("\n");
		printf("Test #%d:\n", testCase);
		printf("  maximum possible interceptions: %d\n", LDS(a));
		testCase++;
	}

	return 0;
}
