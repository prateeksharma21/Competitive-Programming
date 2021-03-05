#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

int val[N];
int c[N];

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
            val[v] += val[u];
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
      int lc = lca(u, v);
      return val[u] + val[v] - 2 * val[lc] + (c[lc] == 0);
   }
};

void test(){
   int n, k;
   cin >> n >> k;
   vector<vector<int>> g(n + 1);
   vector<int> t[4];
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      t[x].push_back(i);
      val[i] = 0;
      c[i] = x;
      if (x == 0) val[i] = 1;
   }
   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   LCA lc(g);
   if (k == 2) {
      int ans = 0;
      for (int a : t[1]) {
         for (int b : t[2]) {
            ans += bool(lc.dist(a, b));
         }
      }
      cout << ans << '\n';
   }
   if (k == 3) {
      int ans = 0;
      for (int a : t[1]) {
         for (int b : t[2]) {
            for (int c : t[3]) {
               ans += bool(lc.dist(a,b)) & bool(lc.dist(a,c)) & bool(lc.dist(b,c));
            }
         }
      }
      cout << ans << '\n';
   } 
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}