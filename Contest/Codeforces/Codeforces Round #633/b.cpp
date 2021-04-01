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

vector<int> G[N];
vector<int> deg(N);
vector<int> dist(N);

void dfs(int u,int p = 0){
   dist[u] = dist[p]+1;
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u);
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
      deg[u]++;
      deg[v]++;
   }
   int lf = 0;
   set<int> leaf;
   f(i,1,n+1){
      if(deg[i] == 1){
         lf = i;
         leaf.insert(i);
      }
   }
   dist[0] = -1;
   dfs(lf);
   int c = 0;
   int nd = 0, mxd = 0;
   f(i,1,n+1){
      if(deg[i] == 1){
         if(dist[i] & 1){
            c = 1;
         }
      }
   }
   if(c){
      cout << "3 ";
   }else{
      cout << "1 ";
   }
   int ans = n-1;
   while(!leaf.empty()){
      auto l = *leaf.begin();
      auto k = G[l][0];
      int cnt = 0;
      for(auto &e : G[k]){
         if(deg[e] == 1){
            leaf.erase(e);
            cnt++;
         }
      }
      ans -= cnt-1;
   }
   cout << ans << '\n';
   return 0;
} 