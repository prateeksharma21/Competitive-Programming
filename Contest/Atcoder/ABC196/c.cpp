#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e6 + 10; 

int to_int(string s){
   reverse(all(s));
   int ans = 0,c = 1;
   for(auto &e : s){
      ans += (e-'0')*c;
      c *= 10;
   }
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   int ans = 0;
   for (int i = 1; i < N; ++i) {
      string K = to_string(i) + to_string(i);
      if (to_int(K) <= n) {
         ++ans;
      }
   }
   cout << ans << '\n';
   return 0;
}