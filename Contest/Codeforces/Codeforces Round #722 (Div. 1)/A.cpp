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
   int n;
   cin >> n;
   vector<array<int, 2>> a(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i][0] >> a[i][1];
   }
   vector<vector<int>> g(n + 1);
   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   auto dp = vector(n + 1, vector(2, 0LL));

   function<void(int, int)> dfs = [&](int u, int p) {
      for (int v : g[u]) {
         if (v == p) continue;
         dfs(v, u);
         dp[u][0] += max({dp[v][0] + abs(a[u][0] - a[v][0]), dp[v][1] + abs(a[u][0] - a[v][1])});
         dp[u][1] += max({dp[v][0] + abs(a[u][1] - a[v][0]), dp[v][1] + abs(a[u][1] - a[v][1])});
      }
   };

   dfs(1, 0);
   cout << max(dp[1][0], dp[1][1]) << '\n';
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