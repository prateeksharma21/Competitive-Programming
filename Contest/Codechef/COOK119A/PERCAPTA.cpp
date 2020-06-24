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
const int MOD = 1e9+7, N = 2e5 + 10;

int n,m;
vector<int> G[N];
int A[N];
int B[N];

void test(){
   cin >> n >> m;
   f(i,1,n+1){
      G[i].clear();
   }
   vector<pair<int, int>> edge;
   f(i,1,n+1){
      cin >> A[i];
   }
   f(i,1,n+1){
      cin >> B[i];
   }
   vector<int> C;
   f(i,1,n+1) C.pb(i);
   sort(all(C),[&](int a,int b){
      return A[a]*B[b] > A[b]*B[a];
   });
   // debug(C);

   int s = C[0];
   
   pair<int, int> mx = {A[s]/__gcd(A[s],B[s]),B[s]/__gcd(A[s],B[s])};
   
   vector<int> done(n+1);
   
   f(i,0,n){
      int c = C[i];
      pair<int, int> ff = {A[c]/__gcd(A[c],B[c]),B[c]/__gcd(A[c],B[c])};
      if(ff == mx){
         done[c] = 1;
      }
   }

   // debug(done);

   f(i,0,m){
      int u,v;
      cin >> u >> v;
      if(done[u] and done[v]){
         G[u].pb(v);
         G[v].pb(u);
         edge.pb({u,v});
      }
   }

   // debug(edge);

   int R = 0;
   vector<int> vis(n+1);
   vector<int> o;

   function<void(int)> dfs = [&](int u){
      R++;
      vis[u] = 1;
      o.pb(u);
      for(auto &v : G[u]){
         if(!vis[v]){
            dfs(v);
         }
      }
   };

   int ans = 0;
   vector<int> res;
   f(i,1,n+1){
      if(!vis[i] and done[i]){
         R = 0;
         o.clear();
         dfs(i);
         if(R > ans){
            ans = R;
            res = o;
         }
      }
   }

   cout << res.size() << '\n';
   for(auto &e : res){
      cout << e << ' ';
   }
   cout << '\n';

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