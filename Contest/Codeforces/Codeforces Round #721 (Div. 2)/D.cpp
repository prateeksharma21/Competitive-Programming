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

class LCA {
public:
   vector<vector<int>> g, parent;
   vector<int> depth;
   int n;
   int LG;
   LCA (vector<vector<int>> g, int root = 1) {
      this->g = g;
      this->n = g.size();
      this->LG = log2(n) + 1;
      this->depth = vector<int> (n);
      this->parent = vector<vector<int>> (n, vector<int>(LG));
      dfs (root);
      compute();
   }
   void dfs (int u, int p = 0) {
      parent[u][0] = p;
      for (auto v : g[u]) {
         if (v != p) {
            depth[v] = depth[u] + 1;
            dfs (v, u);
         }
      }
   }
   void compute () {
      for (int j = 1; j < LG; ++j) {
         for (int i = 1; i < n; ++i) {
            if (parent[i][j - 1]) {
               parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
         }
      }
   }
   int lca (int u, int v) {
      if (depth[v] > depth[u]) swap(u, v);
      for (int j = LG - 1; j >= 0; --j) {
         if (depth[u] - depth[v] >= (1 << j)) {
            u = parent[u][j];
         }
      }
      if (u == v) return u;
      for (int j = LG - 1; j >= 0; --j) {
         if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
         }
      }
      return parent[u][0];
   }
   int dist (int u, int v) {
      return depth[u] + depth[v] - 2 * depth[lca(u, v)];
   }
};

void test(){
   int n;
   cin >> n;
   vector<vector<int>> g(n + 1);

   vector<int> sz(n + 1), vis(n + 1), val(n + 1), deg(n + 1);
   
   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      ++u, ++v;
      deg[u]++;
      deg[v]++;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   LCA lc(g);

   function<void(int, int)> dfs = [&](int u, int p) {
      sz[u] = 1;
      for (int v : g[u]) {
         if (v == p) continue;
         dfs(v, u);
         sz[u] += sz[v];
      }
   };

   dfs(1, 0);

   int ans = 0;
   for (int v : g[1]) {
      ans += (sz[v] * (sz[v] - 1) / 2); 
   }

   vector<int> res = {ans};
   vector<int> o;
   int cur = 2;
   vis[cur] = 1;

   while (lc.parent[cur][0] != 1) {
      cur = lc.parent[cur][0];
      vis[cur] = 1;
   }

   vis[1] = 1;
   sz[1] -= sz[cur];
   int c = 0;

   for (int v : g[1]) {
      if (v == cur) {
         c = 1;
         o.push_back(sz[v] - sz[2]);
      } else {
         o.push_back(sz[v]);
      }
   }
   
   int sum = 1;
   for (int i : o) sum += i;
   ans = 0;
   for (int i : o) {
      sum -= i;
      ans += i * sum;
   }
   res.push_back(ans);

   g[1].erase(find(all(g[1]), cur));

   int x = 1, y = 2;

   for (int i = 3; i <= n and res.size() < n + 1; ++i) {
      if (vis[i]) {
         res.push_back(0);
         continue;
      }
      {
         int lca = lc.lca(i, y);
         if (lca == y) {
            int cur = i;
            vis[cur] = 1;
            while (!vis[lc.parent[cur][0]]) {
               cur = lc.parent[cur][0];
               vis[cur] = 1;
            }
            int L = lc.parent[cur][0];
            if (L != y) {
               int curr = 0;
               for (int i : res) curr += i;
               res.push_back(n * (n - 1) / 2 - curr);
               while (res.size() < n + 1) {
                  res.push_back(0);
               }
               break;
            }
            ans = (sz[y] - sz[i]) * sz[x];
            res.push_back(ans);
            y = i;
            continue;
         }
      }
      {
         int lca = lc.lca(i, x);
         if (lca == x) {
            int cur = i;
            vis[cur] = 1;
            while (!vis[lc.parent[cur][0]]) {
               cur = lc.parent[cur][0];
               vis[cur] = 1;
            }
            int L = lc.parent[cur][0];
            if (L != x) {
               int curr = 0;
               for (int i : res) curr += i;
               res.push_back(n * (n - 1) / 2 - curr);
               while (res.size() < n + 1) {
                  res.push_back(0);
               }
               break;
            }
            ans = (sz[x] - sz[i]) * sz[y];
            res.push_back(ans);
            x = i;
            continue;
         }
      }
      int curr = 0;
      for (int i : res) curr += i;
      res.push_back(n * (n - 1) / 2 - curr);
      while (res.size() < n + 1) {
         res.push_back(0);
      }
      break;
   }

   int mx = *max_element(all(deg));
   if (mx < 3 and res.size() < n + 1) res.push_back(1);
   while (res.size() < n + 1) res.push_back(0);
   sum = 0;
   for (int i = 0; i < n + 1; ++i) sum += res[i];
   // assert(sum == n * (n - 1) / 2);
   for (int i = 0; i < n + 1; ++i) {
      cout << res[i] << ' ';
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