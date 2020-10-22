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

int n,m;
vector<int> p;
vector<int> G[N];
vector<int> V;
int sz[N];

void dfs(int u,int p = 0){
   sz[u] = 1;
   for(auto v : G[u]){
      if(v != p){
         dfs(v,u);
         sz[u] += sz[v];
      }
   }
}

void dfs1(int u,int p = 0){
   for(auto &v : G[u]){
      if(v != p){
         int ex = sz[u]-sz[v];
         V.push_back((ex*sz[v]));
         int pu = sz[u], pv = sz[v];
         sz[u] -= sz[v];
         sz[v] += ex;
         dfs1(v,u);
         sz[u] = pu;
         sz[v] = pv;
      }
   }
}

void test(){
   cin >> n;
   f(i,1,n+1){
      G[i].clear();
   }
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }
   cin >> m;
   p = vector<int>(m);
   for(int i = 0; i < m; ++i){
      cin >> p[i];
   }
   while(m < n-1){
      ++m;
      p.push_back(1);
   }
   sort(p.begin(),p.end());
   while(p.size() > n-1){
      auto k = p.back();
      p.pop_back();
      p.back() *= k;
      p.back() %= MOD;
   }
   dfs(1);
   dfs1(1);
   debug(V);
   assert(V.size() == n-1);
   assert(p.size() == n-1);
   sort(all(V));
   int ans = 0;
   for(int i = 0; i < n-1; ++i){
      V[i] %= MOD;
      // assert(V[i]*p[i] != 0);
      ans += V[i]*p[i];
      ans %= MOD;
   }
   cout << ans << '\n';
   V.clear();
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
