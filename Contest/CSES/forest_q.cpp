#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define f(i,x,n) for(ll i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define int ll

template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
 
const double PI = acos(-1);
const ll LINF = LLONG_MAX;
const int MOD = 1e9+7, INF = INT_MAX, N = 1e3 + 10;
 
int A[N][N];
int pre[N][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   for(int i=1;i<=n;i++){
      string s;
      cin >> s;
      s = "."+s;
      for(int j=1;j<=n;j++){
         pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
         if(s[j] == '*'){
            pre[i][j]++;
         }
      }
   }
   while(q--){
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1] << '\n';
   }
   return 0;
}
