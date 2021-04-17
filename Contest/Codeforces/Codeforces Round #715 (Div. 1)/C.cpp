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
const int MOD = 1e9+7, N = 2e5 + 10; 
const int LG = log2(N) + 1;

set<int> vis;
vector<int> nxt[N];
int p[N];
int cnt;
int lead[N];
set<int> G[N];
set<array<int, 2>> g[N];
int parent[N][LG];
int dp[N][LG];
int h[N];

vector<int> comp;

void dfs (int u) {
   comp.push_back(u);
   vector<int> to_remove;
   for (int v : vis) {
      if (!G[u].count(v)) {
         to_remove.push_back(v);
      }
   }
   for (int v : to_remove) {
      vis.erase(v);
   }
   for (int v: to_remove) {
      g[u].insert({v, 0});
      g[v].insert({u, 0});
      dfs (v);
   }
}

void dfs (int u, int p, int d) {
   h[u] = 1 + h[p];
   parent[u][0] = p;
   dp[u][0] = d;
   for (auto [v, w] : g[u]) {
      if (v == p) continue;
      dfs (v, u, w);
   }
}

int lca(int u, int v) {
   if (h[u] < h[v]) swap(u, v);
   int mn = 1e18;
   for (int i = LG - 1; i >= 0; --i) {
      if (h[u] - h[v] >= (1LL << i)) {
         mn = min(mn, dp[u][i]);
         u = parent[u][i];
      }
   }
   if (u == v) return mn;
   for (int i = LG - 1; i >= 0; --i) {
      if (parent[u][i] != parent[v][i]) {
         mn = min({mn, dp[u][i], dp[v][i]});
         u = parent[u][i];
         v = parent[v][i];
      }
   }
   mn = min({mn, dp[u][0], dp[v][0]});
   return mn;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   memset(parent, -1, sizeof parent);

   int n, m;
   cin >> n >> m;
   int xr = 0;
   vector<array<int, 3>> edge;
   for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      xr ^= w;
      G[u].insert(v);
      G[v].insert(u);
      edge.push_back({w, u, v});
   } 

   int rem = n * (n - 1) / 2 - m;
   
   for (int i = 0; i < n; ++i) {
      vis.insert(i);
   }

   for (int i = 0; i < n; ++i) {
      if (vis.count(i)) {
         vis.erase(i);
         comp.clear();
         dfs(i);    
         for (int v : comp) {
            lead[v] = cnt;
         }        
         int sz = comp.size();
         rem -= (sz - 1);
         cnt++;
      }
   }
   sort(all(edge));

   int mn = 1e18;

   vector<array<int, 3>> not_u;

   int ans = 0;


   vector<int> par(cnt), sz(cnt, 1);
   iota(all(par), 0LL);


   function<int(int)> find = [&](int u) {
      return u == par[u] ? u : par[u] = find(par[u]);
   };

   function<bool(int, int)> merge = [&](int u, int v) {
      u = find(u);
      v = find(v);
      if (u == v) return false;
      if (sz[v] > sz[u]) swap(u, v);
      sz[u] += sz[v];
      par[v] = u;
      return true;
   };

   for (auto [w, x, y] : edge) {
      if (merge(lead[x], lead[y])) {
         ans += w;
         g[x].insert({y, w});
         g[y].insert({x, w});
      } else {
         not_u.push_back({w, x, y});
      }
   }

   if (rem != 0) {
      cout << ans << '\n';
      return 0;
   }

   dfs(0, 0, 0);
   for (int j = 1; j < LG; ++j) {
      for (int i = 0; i < n; ++i) {
         if (parent[i][j - 1] != -1) {
            dp[i][j] = min(dp[i][j - 1], dp[parent[i][j - 1]][j - 1]);
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
         }
      }
   }

   ans += xr;
   for (auto [w, x, y] : not_u) {
      if (w >= xr) break;
      if (lca(x, y) == 0) {
         ans -= xr;
         ans += w;
         break;
      }
   }

   cout << ans << '\n';
   return 0;
}