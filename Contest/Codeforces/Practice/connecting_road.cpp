#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e6 + 10; 
const int LG = log2(N)+1;

int n,q;
vector<pii> G[N];
int dist[N];
int tin[N];
int tout[N];
int parent[N][LG];
int timer;

void dfs(int u,int p = 0,int d = 0){
   parent[u][0] = p;
   d %= MOD;
   dist[u] = d;
   tin[u] = ++timer;
   for(auto &v : G[u]){
      if(v.F!=p){
         dfs(v.F,u,d+v.S);
      }
   }
   tout[u] = ++timer;
}

void precompute(){
   f(i,1,LG){
      for(int j=1;j<=n;j++){
         if(parent[j][i-1]){
            parent[j][i] = parent[parent[j][i-1]][i-1];
         }
      }
   }
}

bool is_ancestor(int u,int v){
   return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u,int v){
   if (is_ancestor(u, v))
      return u;
   if (is_ancestor(v, u))
      return v;
   for(int i=LG-1;i>=0;i--){
      if(!is_ancestor(parent[u][i],v)){
         u = parent[u][i];
      }
   }
   return parent[u][0];
}

struct FenwickTree{
   int n;
   vector<ll> fenw;

   FenwickTree(int n){
      this->n = n;
      fenw.assign(n,0);
   }

   FenwickTree(vector<ll> a) : FenwickTree((int)a.size()){
      f(i,0,(int)a.size()){
         update(i,a[i]);
      }
   }

   ll query(int r){
      ll res = 0;
      while(r>=0){
         res += fenw[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }

   void update(int ind,ll val){
      while(ind<n){
         fenw[ind] += val;
         fenw[ind] %= MOD;
         ind = ind | (ind+1);
      }
   }

   void range_add(int l, int r, int val) {
      update(l, val);
      update(r + 1, -val);
   }
};

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> q;
   f(i,1,n){
      int u,v,w;
      cin >> u >> v >> w;
      u++,v++;
      G[u].pb({v,w});
      G[v].pb({u,w});
   }
   dfs(1);
   precompute();
   FenwickTree fen(2*n+1);
   f(i,1,n+1){
      fen.range_add(tin[i],tin[i],dist[i]);
      fen.range_add(tout[i],tout[i],dist[i]);
   }
   while(q--){
      int ty,x,y,c;
      cin >> ty;
      if(ty == 0){
         cin >> c;
         c++;
         int vv = 0;
         if(parent[c][0]){
            int p = parent[c][0];
            vv = fen.query(tin[c])-fen.query(tin[p]);
            fen.range_add(tin[c],tout[c],vv);
         }
         for(auto &v : G[c]){
            if(v.F!=parent[c][0]){
               int val = fen.query(tin[v.F])-fen.query(tin[c]);
               fen.range_add(tin[v.F],tout[v.F],val);
            }
         }
      }else{
         cin >> x >> y;
         x++,y++;
         int lc = LCA(x,y);
         int ans = fen.query(tin[x])+fen.query(tin[y])-2*fen.query(tin[lc]);
         ans %= MOD;
         while(ans<0) ans+=MOD;
         cout << ans << '\n';
      }
   }
   return 0;
} 