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
   
   int kth(int u,int d){
      for(int j=LG-1;j>=0;j--){
         if((1ll<<j)<=d){
            u = parent[u][j];
            d -= (1ll<<j);
         }
      }
      return u;
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
   int n, q;
   cin >> n >> q;
   vector<vector<int>> g(n + 1);
   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   LCA lc(g);
   while (q--) {
      int sz;
      cin >> sz;
      vector<int> a(sz);
      for (int i = 0; i < sz; ++i) {
         cin >> a[i];
      }
      if (sz == 1) {
         cout << 1 << ' ' << a[0] << '\n';
         continue;
      }
      int lca = a[0];
      for (int i = 1; i < sz; ++i) {
         lca = lc.lca(lca, a[i]);
      }
      map<int, array<int, 2>> cnt;
      for (int v : a) {
         if (v == lca) continue;
         int d = lc.depth[v] - lc.depth[lca];
         int p = lc.kth(v, d - 1);
         if (cnt[p][0] < d) {
            cnt[p] = {d, v};
         }
      }
      vector<array<int, 2>> oth;
      for (auto e : cnt) {
         oth.push_back(e.second);
      }
      sort(all(oth), [&](array<int, 2> a, array<int, 2> b){
         return a[0] > b[0];
      });
      vector<int> res = {};
      if (oth.size() == 1) {
         int d = oth.front()[0];
         int v = oth.front()[1];
         if (d & 1) {
            res = {lc.kth(v, d / 2), lc.kth(v, d / 2 + 1)};
         } else {
            res = {lc.kth(v, d / 2)};
         }
      } else {
         int d = 0;
         for (int v : a) {
            d = max(d, lc.dist(oth[0][1], v));
         }
         int v = oth[0][1];
         if (d & 1) {
            res = {lc.kth(v, d / 2), lc.kth(v, d / 2 + 1)};
         } else {
            res = {lc.kth(v, d / 2)};
         }
      }
      sort(all(res));
      cout << res.size() << ' ';
      for (int i : res) {
         cout << i << ' ';
      }
      cout << '\n';
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