struct LCA{
   vector<vector<int>> G,parent;
   vector<int> tin,tout,depth;
   int timer;
   int n;
   int LG;

   LCA(vector<vector<int>> G,int R = 1){
      this->G = G;
      this->n = G.size();
      this->LG = log2(n)+1;
      this->timer = 0;
      tin.assign(n,0);
      tout.assign(n,0);
      depth.assign(n,0);
      tin[0] = ++timer;
      parent = vector<vector<int>>(n,vector<int>(LG));
      dfs(R);
      tout[0] = ++timer;
      compute();
   }

   void dfs(int u,int p = 0,int d = 0){
      parent[u][0] = p;
      tin[u] = ++timer;
      depth[u] = d;
      for(auto &v : G[u]){
         if(v!=p){
            dfs(v,u,d+1);
         }
      }
      tout[u] = ++timer;
   }

   void compute(){
      for(int j=1;j<LG;j++){
         for(int i=1;i<n;i++){
            if(parent[i][j-1]){
               parent[i][j] = parent[parent[i][j-1]][j-1];
            }
         }
      }
   }

   bool is_anc(int u,int v){
      return tin[u]<=tin[v] and tout[v]<=tout[u];
   }

   int lca(int u,int v){
      if(is_anc(u,v)) return u;
      if(is_anc(v,u)) return v;
      for(int i=LG-1;i>=0;i--){
         if(!is_anc(parent[u][i],v)){
            u = parent[u][i];
         }
      }
      u = parent[u][0];
      return u;
   }

   int dist(int u,int v){
      return depth[u]+depth[v]-2*depth[lca(u,v)];
   }
};