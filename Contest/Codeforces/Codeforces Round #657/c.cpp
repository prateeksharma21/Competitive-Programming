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
const int MOD = 1e9+7, INF = INT_MAX, N = 1e5 + 10;

#ifdef Prateek
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

void testcases();

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1;
   cin >> t;
   while(t--) testcases();
   return 0;
}

void testcases(){
   int n,m;
   cin >> n >> m;
   vector<pair<int, int>> A(m);
   vector<int> B(m+1);
   f(i,0,m){
      cin >> A[i].F >> A[i].S;
   }
   f(i,1,m+1){
      B[i] = A[i-1].F;
   }   
   sort(all(B));
   vector<int> pre(m+1);
   f(i,1,m+1){
      pre[i] = pre[i-1]+B[i];
   }
   int ans = 0;
   if(n <= m){
      int c = n,r = m;
      while(c--){
         ans += B[r];
         --r;
      }
   }
   debug(ans);
   f(i,0,m){
      auto k = upper_bound(all(B),A[i].S)-B.begin();
      int v =  pre[m]-pre[k-1];
      int done = m-k+1;
      int rem = n-done;
      if(rem < 0) continue;      
      if(A[i].F > A[i].S){
         v += A[i].S*rem;
      }else{
         v += A[i].S*(rem-1)+A[i].F;
      }
      ans = max(ans,v);
   }
   cout << ans << '\n';
   return;
}
