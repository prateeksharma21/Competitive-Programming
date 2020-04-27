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
const int MOD = 1e9+7, N = 2e5 + 10; 

vector<int> G[N];
vector<int> dist(N);
vector<int> have(N);

void dfs1(int u,int p = 0){
   int mx = 0;
   for(auto &v : G[u]){
      if(v!=p){
         dfs1(v,u);
         mx = max(mx,dist[v]+1);
      }
   }
   for(auto &v : G[u]){
      if(v!=p){
         if(mx == dist[v]+1){
            have[u] = v;
            break;
         }
      }
   }
}

void dfs2(int u,int p = 0){
   if(have[p] == u){

   }else{
      
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,u,v;
   cin >> n;
   f(i,1,n){
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   dfs1(1);
   dfs2(1);
   return 0;
} 