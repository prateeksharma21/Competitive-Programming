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

int n;
int sz[N];
vector<pair<int, int>> C;
vector<int> G[N];

void clear(){
   C.clear();
   for(int i = 0; i <= n; ++i){
      G[i].clear();
   }
}

void dfs(int u,int p = 0){
   sz[u] = 1;
   for(int v : G[u]){
      if(v != p){
         dfs(v,u);
         sz[u] += sz[v];
      }
   }
}

void dfs1(int u,int p = 0){
   int mx = 0;
   for(int v : G[u]){
      mx = max(mx,sz[v]);
   }
   C.push_back({mx,u});
   for(int v : G[u]){
      if(v != p){
         int pu = sz[u];
         int pv = sz[v];
         sz[u] = sz[u]-sz[v];
         sz[v] = n;
         dfs1(v,u);
         sz[u] = pu;
         sz[v] = pv;
      }
   }
}

void test(){
   cin >> n;
   clear();
   vector<pair<int, int>> edge;
   for(int i = 1; i < n; ++i){
      int u,v;
      cin >> u >> v;
      edge.push_back({u,v});
      G[u].push_back(v);
      G[v].push_back(u);
   }
   dfs(1);
   dfs1(1);
   sort(all(C));
   if(C[0].first != C[1].first){
      cout << edge[0].first << ' ' << edge[0].second << '\n';
      cout << edge[0].first << ' ' << edge[0].second << '\n';
      return;
   }
   int mx = C[0].first;
   int nd = -1;
   debug(C[0].second,mx);
   dfs(C[0].second);
   for(int v : G[C[0].second]){
      if(v != C[1].second){
         nd = v;
      }
   }
   cout << C[0].second << ' ' << nd << '\n';
   cout << C[1].second << ' ' << nd << '\n';
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
