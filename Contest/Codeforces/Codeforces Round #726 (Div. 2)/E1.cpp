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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   string ans = "";
   while (!s.empty()) {
      string res = "";
      while (res.length() < k) {
         res += s;
      }
      while (res.length() > k) res.pop_back();
      if (ans.empty()) {
         ans = res;
      }
      if (res < ans) {
         ans = res;
      }
      s.pop_back();
   }
   cout << ans << '\n';
   return 0;
}