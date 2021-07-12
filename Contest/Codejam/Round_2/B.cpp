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

int dp[N];

int dfs (int x) {
   if (!x) return 0;
   if (x == 1) return -MOD; 
   int &ans = dp[x];
   if (ans != -1) return ans;
   ans = 0;
   for (int i = 2; i <= x; ++i) {
      if (x % i == 0) {
         ans = max(ans, dfs(x / i - 1) + 1);
      }
   }
   return ans;
}

void Solve() {
   int n;
   cin >> n;
   int ans = 0;
   for (int i = 3; i <= n; ++i) {
      if (n % i == 0) {
         ans = max(ans, dfs(n / i - 1) + 1);
      }
   }
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}