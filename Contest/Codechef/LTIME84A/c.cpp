#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 2e5 + 10;

int A[N];
int C[N][101];


#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif


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
      f(j,1,101){
         C[u][j] = C[p][j];
      }
      C[u][A[u]]++;
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

void test(){
   int n,q;
   cin >> n >> q;
   vector<vector<int>> G(n+1);
   f(i,1,n+1){
      cin >> A[i];
      f(j,1,101){
         C[i][j] = 0;
      }
   }
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }

   LCA lc(G);

   while(q--){
      int u,v;
      cin >> u >> v;
      vector<int> R;
      int lca = lc.lca(u,v);
      vector<int> cnt(100);
      f(i,1,101){
         cnt[i] = C[u][i]+C[v][i]-2*C[lca][i];
      }
      cnt[A[lca]]++;
      int c = 0;
      f(i,1,101){
         if(cnt[i]){
            R.pb(i);
            if(cnt[i]>1){
               c = 1;
               break;
            }
         }
      }
      if(c){
         cout << "0\n";
      }else{
         int ans = 1e18;
         // debug(R);
         f(i,1,R.size()){
            ans = min(ans,R[i]-R[i-1]);
         }
         cout << ans << '\n';
      }
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