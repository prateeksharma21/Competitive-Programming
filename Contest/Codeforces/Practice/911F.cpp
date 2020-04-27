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

int n;
vector<int> G[N];
int nd[2];
int d[2];
int c;
int dist[2][N];
int deg[N];
int parent[N];

void dfs(int u,int p,int dr){
   if(dr>d[c]){
      nd[c] = u;
      d[c] = dr;
   }
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u,dr+1);
      }
   }
}

void dfs(int u,int p){
   dist[c][u] = dist[c][p]+1;
   parent[u] = p;
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u);
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
      deg[u]++;
      deg[v]++;
   }
   dfs(1,0,0);
   c++;
   dfs(nd[0],0,0);
   c = 0;
   dist[c][0] = -1;
   dfs(nd[0],0);
   c++;
   dist[c][0] = -1;
   dfs(nd[1],0);
   unordered_set<int> leaf;
   f(i,1,n+1){
      if(deg[i] == 1 and i!=nd[0] and i!=nd[1]) leaf.insert(i);
   }
   vector<array<int,3>> ans;
   int fin = 0;
   while(!leaf.empty()){
      auto k = *leaf.begin();
      leaf.erase(k);
      if(dist[0][k] >= dist[1][k]){
         ans.pb({nd[0],k,k});
      }else{
         ans.pb({nd[1],k,k});
      }
      fin += max(dist[0][k],dist[1][k]);
      auto par = parent[k];
      deg[par]--;
      if(deg[par]<=1) leaf.insert(par);
   }
   int node = nd[0];
   while(parent[node]){
      fin += dist[1][node];
      ans.pb({nd[1],node,node});
      node = parent[node];
   }
   cout << fin << '\n';
   for(auto &e : ans){
      cout << e[0] << ' ' << e[1] << ' ' << e[2] << '\n'; 
   }
   return 0;
} 