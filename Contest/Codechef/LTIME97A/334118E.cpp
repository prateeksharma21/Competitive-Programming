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
   int n, r1, r2;
   cin >> n >> r1 >> r2;
   vector<vector<int>> g(n + 1);
   for (int i = 1; i <= n; ++i) {
      if (i == r1) continue;
      int p;
      cin >> p;
      g[i].push_back(p);
      g[p].push_back(i);
   }

   vector<int> par(n + 1);

   function<void(int, int)> dfs = [&](int u, int p) {
      par[u] = p;
      for (int v : g[u]) {
         if (v == p) continue;
         dfs(v, u);
      }
   };

   dfs(r2, 0);

   for (int i = 1; i <= n; ++i) {
      if (i == r2) continue;
      cout << par[i] << ' ';
   }
   return 0;
}