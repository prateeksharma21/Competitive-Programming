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

void test(){
   int n,a,b,da,db;
   cin >> n >> a >> b >> da >> db;
   vector<vector<int>> G(n+1);
   vector<int> D(n+1,-1);
   for(int i = 1; i < n; ++i){
      int u,v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }
   function<void(int,int)> dfs = [&](int u,int p){
      D[u] = D[p]+1;
      for(int v : G[u]){
         if(v != p){
            dfs(v,u);
         }
      }
   };
   dfs(a,0);
   if(D[b] <= da){
      cout << "Alice\n";
      return;
   }
   int nd = max_element(all(D))-D.begin();
   dfs(nd,0);
   int mx = *max_element(all(D));
   if(2*da >= mx){
      cout << "Alice\n";
      return;
   }
   if(db > 2*da){
      cout << "Bob\n";
   }else{
      cout << "Alice\n";
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
