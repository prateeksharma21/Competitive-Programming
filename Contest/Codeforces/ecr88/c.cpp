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

#ifdef HOME
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
   int h,c,t;
   cin >> h >> c >> t;
   int xx = 1;
   long double k = (h+c);
   k /= 2;if(h == t){
      cout << 1 << '\n';
      return;
   }if(h+c == 2*t){
      cout << 2 << '\n';
      return;
   }auto cost = [&](int v){
      long double ans = 0;
      if(v & 1){
         ans += h;
      }
      ans += ((h+c)*(v/2)); ans /= v;
      return abs(ans-t);
   };
   int R = (h-c)/(2*(t-k));
   vector<pair<double,int>> A;
   for(int i = max(1ll,R-100);i<=R+100;i++) A.pb({cost(i),i});
   A.pb({abs(k-t),2});
   sort(all(A));
   cout << A[0].S<< '\n';
   return;
}
