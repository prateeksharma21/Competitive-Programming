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
   int n, m;
   cin >> n >> m;
   vector<vector<int>> g(n + 1), rev_g(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      rev_g[v].push_back(u);
   }
   vector<int> dp(n + 1);
   vector<int> vis(n + 1);

   dp[1] = 1;   

   vector<int> viss(n + 1); 

   function<int(int)> dfs = [&](int u) -> int {
      if (!viss[u]) {
         vis[u] = 2;
         return dp[u] = 0;
      }
      if (vis[u] == 2) return dp[u];
      if (vis[u] == 1) {
         dp[u] = -1;
         vis[u] = 2;
         return dp[u];
      }
      vis[u] = 1;
      vector<int> val;
      for (int v : rev_g[u]) {
         if (v == u) {
            val.push_back(-1);
         } else {
            val.push_back(dfs(v));
         }
      }
      if (vis[u] == 2) return dp[u];
      int &ans = dp[u];
      for (int v : val) {
         if (v == -1) {
            ans = -1;
            vis[u] = 2;
            return ans;
         }
      }
      for (int v : val) {
         ans += v;
         if (ans > 2) break;
      }
      ans = min(ans, 2LL);
      vis[u] = 2; 
      return ans;
   };

   queue<int> q;
   q.push(1);
   viss[1] = 1;
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
         if (!viss[v]) {
            q.push(v);
            viss[v] = 1;
         }
      }
   }


   for (int i = 1; i <= n; ++i) {
      auto val = dfs(i);
      if (!viss[i]) {
         cout << 0 << ' ';
         continue;
      }
      cout << val << ' ';
   }
   cout << '\n';
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