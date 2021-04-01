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
const int MOD = 1e9+7, N = 5e5 + 10;

int n,m;
vector<int> order;
vector<int> G[N];
int dist[N];
int parent[N];
int vis[N];

void dfs(int u,int p = 0){
   order.push_back(u);
   parent[u] = p;
   dist[u] = dist[p]+1;
   vis[u] = 1;
   for(int v : G[u]){
      if(!vis[v]){
         dfs(v,u);
      }
   }
}

void test(){
   cin >> n >> m;
   order.clear();
   f(i,1,n+1){
      G[i].clear();
      vis[i] = 0;
   }
   f(i,0,m){
      int u,v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }
   int nd = -1;
   f(i,1,n+1){
      if(G[i].size() == 1){
         nd = i;
         break;
      }
   }
   if(nd != -1){
      dfs(nd);
      for(int i = 1; i <= n; ++i){
         if(dist[i] >= (n+1)/2){
            cout << "PATH\n";
            cout << dist[i] << '\n';
            int cur = i;
            while(cur){
               cout << cur << ' ';
               cur = parent[cur];
            }
            cout << '\n';
            return;
         }
      }
   }
   cout << "PAIRING\n";
   cout << n/2 << '\n';
   int ff = 0, ss = 3;
   assert(order.size() == n);
   while(ss < order.size()){
      cout << order[ff] << ' ' << order[ss] << '\n';
      ++ff;
      ++ss;
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
