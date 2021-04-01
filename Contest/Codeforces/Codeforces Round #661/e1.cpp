#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;

vector<int> leaf;
vector<array<int,3>> G[N];
int parent[N];
int val[N];
int V[N];
int cst[N];
int dist[N];
int n,S;

int dfs(int u,int p,int d){
   int c = 0;
   int r = 0;
   dist[u] = dist[p]+d;
   for(auto &v : G[u]){
      if(v[0]!=p){
         c++;
         V[v[0]] = v[1];
         cst[v[0]] = v[2];
         r += dfs(v[0],u,v[1]);
      }
   }
   r += (c == 0);
   if(c == 0){
      leaf.push_back(u);
   }
   return val[u] = r;
}

void clear(){
   leaf.clear();
   for(int i = 1; i <= n; ++i){
      dist[i] = 0;
      val[i] = 0;
      V[i] = 0;
      parent[i] = 0;
      G[i].clear();
   }
}

void solve(){
   cin >> n >> S;
   clear();
   for(int i = 1; i < n; ++i){
      int u,v,w,c;
      cin >> u >> v >> w >> c;
      G[u].push_back({v,w,c});
      G[v].push_back({u,w,c});
   }
   dfs(1,0,0);
   int sm = 0;
   set<array<int,3>> se;
   for(auto e : leaf){
      sm += dist[e];
   }
   for(int i = 2; i <= n; ++i){
      se.insert({((V[i]-V[i]/2)/cst[i])*val[i],V[i]/2,i});
   }
   int ans = 0;
   while(sm > S){
      auto k = *se.rbegin();
      se.erase(k);
      cout << k[0] << '\n';
      sm -= k[0]*cst[k[2]];
      k[0] = ((k[1]-k[1]/2)/cst[k[2]])*val[k[2]];
      k[1] /= 2;
      se.insert(k);
      ans+=cst[k[2]];
   }
   cout << ans << '\n';
   cout << '\n';
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--) solve();
   return 0;
}