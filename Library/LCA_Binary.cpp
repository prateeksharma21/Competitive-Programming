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