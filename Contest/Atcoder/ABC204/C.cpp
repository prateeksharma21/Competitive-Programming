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
   int n, m;
   cin >> n >> m;

   int c = 0;
   vector<vector<int>> g(n + 1);
   vector<int> vis(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
   }

   function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      ++c;
      for (int v : g[u]) {
         if (!vis[v]) {
            dfs(v);
         }
      }
   };

   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      vis = vector<int>(n + 1);
      dfs(i);
      ans += c;
      c = 0;
   }
   cout << ans;

   return 0;
}