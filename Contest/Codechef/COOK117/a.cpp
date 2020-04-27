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
   string s,t;
   cin >> s >> t;
   int st = 1e9,en = 0;
   f(i,0,s.length()){
      if(s[i]!=t[i]){
         st = min(st,i);
         en = max(st,i);
      }
   }
   if(st == 1e9){
      cout << "0\n";
      return;
   }
   s = s.substr(st,en-st+1);
   t = t.substr(st,en-st+1);
   int n = s.length();
   vector<int> A(n);
   f(i,0,n){
      A[i] = s[i]==t[i];
   }
   vector<int> O;
   int v = 0,c = 0;
   for(int i=0,j;i<n;i=j){
      j = i;
      while(j<n and A[i] == A[j]) j++;
      if(A[i]){
         O.pb(j-i);
      }else{
         v += j-i;
         c ++;
      }
   }
   int ans = v*c;
   sort(all(O));
   int cur = 0;
   f(i,0,O.size()){
      cur += O[i];
      if((c-i-1)*(v+cur)<=ans){
         ans = (c-i-1)*(v+cur);
      }
   }
   cout << ans << '\n';
   return;
}
