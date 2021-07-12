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
const int MOD = 1e9+7, N = 1e5 + 10; 

int to_int(string s){
   int ans = 0;
   for(char c : s) {
      ans = ans*10 + (c - '0');
   }
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> n >> k;
   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
         ans += to_int(to_string(i) + "0" + to_string(j));
      }
   }
   cout << ans;
   return 0;
}