struct LCA{
   vector<vector<int>> G;
   vector<int> depth,o,first_o,t;
   int n,sz;

   LCA(vector<vector<int>> G,int R = 1){
      this->G = G;
      n = G.size();
      depth.assign(n,0);
      first_o.assign(n,0);
      dfs(R);
      sz = o.size();
      t.assign(4*sz,0);
      build(1,0,sz-1);
   }   

   void dfs(int u,int p = -1,int d = 0){
      depth[u] = d;
      first_o[u] = o.size();
      o.push_back(u);
      for(auto &v : G[u]){
         if(v!=p){
            dfs(v,u,d+1);
            o.push_back(u);
         }
      }
   }

   void build(int v,int tl,int tr){
      if(tl == tr){
         t[v] = o[tl];
         return;
      }
      int tm = (tl+tr)/2;
      build(2*v,tl,tm);
      build(2*v+1,tm+1,tr);
      t[v] = t[2*v+1];
      if(depth[t[2*v]]<depth[t[2*v+1]]) t[v] = t[2*v];
   }

   int query(int v,int tl,int tr,int l,int r){
      if(l > r) return -1;
      if(l == tl and r == tr) return t[v];
      int tm = (tl+tr)/2;
      int ff = query(2*v,tl,tm,l,min(tm,r));
      int ss = query(2*v+1,tm+1,tr,max(tm+1,l),r);
      if(ff == -1) return ss;
      if(ss == -1) return ff;
      if(depth[ff]<depth[ss]) return ff;
      return ss;
   }

   int lca(int u,int v){
      int ff = first_o[u],ss = first_o[v];
      if(ff>ss) swap(ff,ss);
      return query(1,0,sz-1,ff,ss);
   }

   int dist(int u,int v){
      return depth[u]+depth[v]-2*depth[lca(u,v)];
   }
};

