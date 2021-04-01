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

vector<int> G[N],D[N];
int p[N];
int h[N];
int sz[N];
int parent[N];
int bad;
pair<int, int> V[N];

void init(int n){
   f(i,0,n+10){
      G[i].clear();
      D[i].clear();
   }
}

void dfs(int u,int pr,int d){
   parent[u] = pr;
   D[d].pb(u);
   sz[u] = p[u];
   for(auto &v : G[u]){
      if(v!=pr){
         dfs(v,u,d+1);
         sz[u] += sz[v];
      }
   }
}

void dfs1(int u,int pr,int d){
   int x = V[u].F, y = V[u].S;
   for(auto &v : G[u]){
      if(v!=pr){
         x -= V[v].F;
         if(x < 0){bad = 1;}
         if(V[v].S > y){
            int rem = V[v].S-y;
            y = 0;
            if(rem <= x){
               x -= rem;
            }else{
               x = 0;
               bad = 1;
            }
         }else{
            y -= V[v].S;
         }
         dfs1(v,u,d+1);
      }
   }
   if(x+y != p[u]){
      bad = 1;
   }
}

void test(){
   int n,m;
   cin >> n >> m;
   init(n);
   bad = 0;
   f(i,1,n+1){
      cin >> p[i];
   }
   f(i,1,n+1){
      cin >> h[i];
   }
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   dfs(1,0,0);
   f(i,1,n+1){
      int sm = h[i]+sz[i];
      if(sm < 0 or sm & 1){
         debug(i);
         cout << "NO\n";
         return;
      }
      int x = sm/2;
      int y = sz[i]-x;
      if(y < 0 or x < 0){
         debug(i,x,y);
         cout << "NO\n";
         return;
      }
      V[i] = {x,y};
   }
   f(i,1,n+1){
      debug(V[i]);
   }
   if(V[1].F+V[1].S != m){
      cout << "NO\n";
      return;
   }
   dfs1(1,0,0);
   if(!bad){
      cout << "YES\n";
   }else{
      cout << "NO\n";
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
