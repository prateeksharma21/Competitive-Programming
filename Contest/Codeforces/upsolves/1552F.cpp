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
const int MOD = 998244353, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> x(n), y(n), s(n);
   for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> s[i];
   }
   vector<int> dp(n), pre(n + 1);
   for (int i = 0; i < n; ++i) {
      int k = lower_bound(all(x), y[i]) - x.begin();
      dp[i] = (pre[i] - pre[k] + x[i] - y[i]) % MOD;
      if (dp[i] < 0) dp[i] += MOD;
      pre[i + 1] = (pre[i] + dp[i]) % MOD;
   }
   int ans = x[n - 1] + 1;
   ans %= MOD;
   for (int i = 0; i < n; ++i) {
      if (s[i]) {
         ans += dp[i];
         ans %= MOD;
      }
   }
   cout << ans << '\n';
   return 0;
}