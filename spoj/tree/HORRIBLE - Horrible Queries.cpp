#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <ctype.h>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <limits.h>
using namespace std;
#define MK              make_pair
#define PB              push_back
#define ALL(v)          (v).begin() , (v).end()
#define Set(v,x)        memset(  v , x , sizeof(v))
#define two(n)          ( 1 << (n) )
#define contain(Set,i)  ( (Set) & two(i) )
#define __join(a,b)     a##b
#define foreach(c, i)   for(__typeof((c).begin())i=(c).begin(),__join(i,__end)=(c).end();i!=__join(i,__end);i++)

#define FOR(i,n)        for (int i = 0 ; i < (n) ; i++)
#define REP(i, b, e) 	  for(typeof(e) i=b; i!=e; ++i)
#define INF             1000000
#define EPS             1e-6
#define MAX             1000005

#define MAXE            1000000
#define COST            first
#define V1              second.first
#define V2              second.second

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef long long int ll;

ll tree[MAX] = {0};  // To store segment tree
ll lazy[MAX] = {0};  // To store pending updates
ll arr[MAX] = {0};
 
void updateRangeUtil(ll si, ll ss, ll se, ll us,
                     ll ue, ll diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
 
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
 
        lazy[si] = 0;
    }
 
    if (ss>se || ss>ue || se<us)
        return ;
 
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
 
    ll mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
 
void updateRange(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
 
ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
 
    if (ss>se || ss>qe || se<qs)
        return 0;
 
    if (ss>=qs && se<=qe)
        return tree[si];
 
    ll mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
 
ll getSum(ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(ll arr[], ll ss, ll se, ll si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;
 
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
 
    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    ll mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
 
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}
 
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
void constructST(ll arr[], ll n)
{
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, 0);
}

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt","w", stdout);
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, c;
  	scanf("%d %d", &n, &c);
    memset(arr, 0, sizeof arr);
    memset(tree, 0, sizeof arr);
    memset(lazy, 0, sizeof arr);
    constructST(arr, n);

    for (int i = 0; i < c; ++i) {
      int tc, p, q, v;
      scanf("%d", &tc);
      if (tc == 0) {
        scanf("%d %d %d", &p, &q, &v);
        updateRange(n, p-1, q-1, v);
      } 
      else {
        scanf("%d %d", &p, &q);
        ll sol = getSum(n, p-1, q-1);
        cout << sol << endl;
      }   
    } 	
  }

  return 0;
}
