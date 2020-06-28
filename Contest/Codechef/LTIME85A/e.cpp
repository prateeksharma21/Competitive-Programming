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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 2e5 + 10; 

vector<int> G[N];
int vis[N];
int parent[N];
int sz[N];

int find(int x){
   if(parent[x] == x) return x;
   return parent[x] = find(parent[x]);
}

void dfs(int u,int p = 0){
   vis[u] = 1;
   if(p){
      parent[u] = p;
   }
   for(auto &v : G[u]){
      if(!vis[v]){
         dfs(v,u);
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   f(i,1,n+1){
      parent[i] = i;
   }
   map<pair<int, int>,bool> done;
   int chk = 0;
   int prv = 0;
   f(i,0,q){
      int u,v;
      cin >> u >> v;
      if(chk){
         cout << prv << '\n';
         continue;
      }
      if(done[{u,v}]){
         cout << prv << '\n';
         continue;
      }
      int l = u, r = v;
      done[{l,r}] = true;
      while(l < r){
         if(find(l) != find(r)){
            G[l].pb(r);
            G[r].pb(l);
         }
         l++;
         r--;
      }
      int c = 0;
      f(i,1,n+1) vis[i] = 0;
      f(i,1,n+1){
         if(!vis[i]){
            c++;
            dfs(i);
         }
      }
      if(c == 1) chk = 1;
      prv = c;
      cout << c << '\n';
   }
   return 0;
} 