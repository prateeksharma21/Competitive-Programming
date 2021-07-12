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
   vector<vector<int>> g(n + 1);
   set<int> ng[n + 1];
   vector<array<int, 2>> edges;
   for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      edges.push_back({a, b});
      g[a].push_back(b);
      g[b].push_back(a);
   }

   function<bool(int, int)> dfs = [&](int u, int p) {
      int sz = (int)g[u].size() - bool(p);
      for (int v : g[u]) {
         if (v == p) continue;
         bool rem = dfs(v, u);
         if (rem) {
            --sz;
         } else {
            ng[u].insert(v);
            ng[v].insert(u);
         }
      }
      debug(u, sz);
      if (sz >= 2) {
         int to_rem = sz - 2;
         while (to_rem != 0) {
            int v = *ng[u].begin();
            ng[u].erase(v);
            ng[v].erase(u);
            --to_rem;
         }
         return true;
      }
      return false;
   };

   dfs(1, 0);

   for (int i = 1; i <= n; ++i) {
      debug(ng[i]);
   }

   vector<int> comp;
   vector<int> vis(n + 1);
   
   function<void(int, int)> dfs_forest = [&](int u, int p) {
      comp.push_back(u);
      vis[u] = 1;
      for (int v : ng[u]) {
         if (v == p) continue;
         dfs_forest(v, u);
      }
   };


   vector<array<int, 2>> added;
   for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
         comp.clear();
         dfs_forest(i, 0);
         vector<int> k;
         debug(comp);
         for (int v : comp) {
            if (ng[v].size() <= 1) {
               k.push_back(v);
            }
         }
         debug(k);
         if (k.size() > 1)
            added.push_back({k[0], k[1]});
         else
            added.push_back({k[0], k[0]});
      }
   }
   vector<array<int, 2>> rem, add;
   for (auto [a, b] : edges) {
      if (!ng[a].count(b)) {
         rem.push_back({a, b});
      }
   }
   for (int i = 1; i < added.size(); ++i) {
      add.push_back({added[i - 1][1], added[i][0]});
   }
   assert(add.size() == rem.size());
   int sz = add.size();
   cout << sz << '\n';
   for (int i = 0; i < sz; ++i) {
      cout << rem[i][0] << ' ' << rem[i][1] << ' ' << add[i][0] << ' ' << add[i][1] << '\n';
   }
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