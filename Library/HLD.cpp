class HLD {
public:
   vector<vector<int>> g;
   vector <int> parent, depth, heavy, head, pos, sz;
   int cur_pos;

   HLD (vector<vector<int>> g) {
      this->g = g;
      int n = g.size();
      parent = vector<int>(n);
      depth = vector<int>(n);
      heavy = vector<int>(n);
      head = vector<int>(n);
      pos = vector<int>(n);
      sz = vector<int>(n);
      cur_pos = 0;
      dfs (1);
      decompose (1, 1);
   }

   void dfs (int u) {
      sz[u] = 1;
      int mx = 0;
      for (int v : g[u]) {
         if (v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs (v);
            sz[u] += sz[v];
            if (sz[v] > mx) {
               mx = sz[v];
               heavy[u] = v;
            }
         }
      }
   }

   void decompose (int u, int h) {
      head[u] = h;
      pos[u] = cur_pos++;
      if (heavy[u]) decompose (heavy[u], h);
      for (int v : g[u]) {
         if (v == parent[u] or v == heavy[u]) continue;
         decompose (v, v);
      }
   }

   int st_query (int x, int y) {
      // 
      return 0;
   }

   int query (int u, int v) {
      int res = 0;
      while (head[u] != head[v]) {
         if (depth[head[u]] > depth[head[v]]) {
            swap (u, v);
         }
         res = max(res, st_query(pos[head[v]], pos[v]));
      }
      if (depth[u] > depth[v]) swap(u, v);
      res = max(res, st_query(pos[u], pos[v]));
      return res;
   }   
};
