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
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   vector<vector<pii>> G(n);
   vector<vector<int>> dist(n,vector<int>(n));
   f(i,1,n){
      int u,v,w;
      cin >> u >> v >> w;
      G[u].pb({v,w});
      G[v].pb({u,w});
   }
   int nd;
   function<void(int, int, int)> dfs = [&](int u,int p,int d){
      dist[nd][u] = d % MOD;
      for(auto &v : G[u]){
         if(v.F!=p){
            dfs(v.F,u,d+v.S);
         }
      }
   };
   f(i,0,n){
      nd = i;
      dfs(i,-1,0);
   }
   while(q--){
      int ty;
      cin >> ty;
      if(ty == 0){
         int c;
         cin >> c;
         f(i,0,n){
            for(auto &v : G[i]){
               if(v.F == c or i == c){
                  v.S *= 2;
                  v.S %= MOD;
               }
            }
         }
         f(i,0,n){
            nd = i;
            dfs(i,-1,0);
         }
      }else{
         int x,y;
         cin >> x >> y;
         cout << dist[x][y] << '\n';
      }
   }
   return 0;
}