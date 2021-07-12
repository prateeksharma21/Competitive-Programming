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
const int INF = 1e15;

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
   int kth(int u,int d){
      for(int j=LG-1;j>=0;j--){
         if((1ll<<j)<=d){
            u = parent[u][j];
            d -= (1ll<<j);
         }
      }
      return u;
   }
   int dist (int u, int v) {
      return depth[u] + depth[v] - 2 * depth[lca(u, v)];
   }
};

void solve(int n, int k, vector<vector<int>> g) {
vector<int> sz(n + 1), par(n + 1);;

   function<void(int, int)> dfs = [&](int u, int p) {
      if (p) {
         g[u].erase(find(all(g[u]), p));
      }
      par[u] = p;
      sz[u] = 1;
      for (int v : g[u]) {
         dfs(v, u);
         sz[u] += sz[v];
      }
   };

   dfs(1, 0);

   LCA lc(g);

   vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

   function<int(int, int)> calc = [&](int u, int rem) {
      if (rem < 0) return INF;
      if (rem == 0) return 0LL;
      int &ans = dp[u][rem];
      if (ans != -1) return ans;
      ans = INF;
      for (int i = 1; i <= n; ++i) {
         int val = rem - sz[u];
         if (val > 0) {
            int res = 1 + calc(i, rem - sz[u]);
            if (i == 1) {
               ans = min(ans, 1 + res);
            } else {
               int lca = lc.lca(i, u);
               int x = i;
               if (lca == i or lca == u) {
                  ans = min(ans, 1 + res);
                  continue;
               } 
               while (par[x] != lca) {
                  x = par[x];
               }
               int y = u;
               while (par[y] != lca) {
                  y = par[y];
               }
               int posX = find(all(g[lca]), x) - g[lca].begin();
               int posY = find(all(g[lca]), y) - g[lca].begin();
               if (posX <= posY) {
                  ++res;
               }
               ans = min(ans, res);
            }
         } else if (val == 0) {
            ans = 1;
         }  
      }
      for (int v : g[u]) {
         ans = min(ans, calc(v, rem));
      }
      return ans;
   };

   int res = INF;

   for (int i = 1; i <= n; ++i) {
      res = min(res, calc(i, k));
   }
   assert(res != INF);

   cout << res << '\n';
}

void test(int n, int k, vector<vector<int>> g){
   vector<int> sz(n + 1), par(n + 1);;

   vector<int> tin(n + 1);
   int timer = 0;

   function<void(int, int)> dfs = [&](int u, int p) {
      if (p) {
         g[u].erase(find(all(g[u]), p));
      }
      tin[u] = timer++;
      par[u] = p;
      sz[u] = 1;
      for (int v : g[u]) {
         dfs(v, u);
         sz[u] += sz[v];
      }
   };

   dfs(1, 0);

   LCA lc(g);

   vector<int> v(n);
   iota(all(v), 1LL);
   sort(all(v), [&](int a, int b){
      return tin[a] < tin[b];
   });

   map<int, int> pos;
   for (int i = 0; i < v.size(); ++i) {
      pos[v[i]] = i;
   }

   vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

   function<int(int, int)> calc = [&](int u, int rem) {
      if (rem < 0) return INF;
      int &ans = dp[u][rem];
      if (ans != -1) return ans;
      if (rem - sz[u] == 0) return ans = 1;
      ans = 2 + calc(1, rem - sz[u]);
      if (u != 1) {
         int ps = pos[u];
         int sub_sz = sz[u];
         if (ps + sub_sz < v.size()) {
            ans = min(ans, 1 + calc(v[ps + sub_sz], rem - sz[u]));
            ans = min(ans, calc(v[ps + sub_sz], rem));
         } 
         if (ps - 1 >= 0) {
            ans = min(ans, 2 + calc(v[ps - 1], rem - sz[u]));
         }
      }
      for (int v : g[u]) {
         ans = min(ans, calc(v, rem));
      }
      return ans;
   };

   int res = calc(1, k);

   assert(res != INF);

   cout << res << '\n';
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      int n, k;
      cin >> n >> k;
      vector<int> deg(n + 1);
      vector<vector<int>> g(n + 1);
      for (int i = 2; i <= n; ++i) {
         int p;
         cin >> p;
         g[p].push_back(i);
         g[i].push_back(p);
         deg[p]++;
         deg[i]++;
      }
      test(n, k, g);
      int mx = *max_element(all(deg));
      // if (mx <= 2) {
      //    test(n, k, g);
      // } else {
      //    solve(n, k, g);
      // }
   }
   return 0;
}