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

void test(){
   int n, k;
   cin >> n >> k;
   vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }

   function<int(int, int)> dfs = [&](int idx, int rem) -> int {
      if (rem < 0) return -1e15;
      if (idx == 0) return rem == 0 ? 0 : -1e15;
      int &ans = dp[idx][rem];
      if (ans != -1) return ans;
      ans = dfs(idx - 1, rem) + (a[idx] == idx - rem);
      ans = max(ans, dfs(idx - 1, rem - 1));
      return ans;
   };

   for (int i = 0; i <= n; ++i) {
      if (dfs(n, i) >= k) {
         cout << i << '\n';
         return;
      }
   }
   cout << -1 << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}