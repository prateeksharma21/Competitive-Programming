#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e3 + 10;

#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

vector<int> G[N];
int dist[N];
int parent[N];
int deg[N];

void dfs(int u,int p,int d){
   dist[u] = d;
   parent[u] = p;
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u,d+1);
      }
   }
}

void test(){
   int n,x;
   cin >> n >> x;
   f(i,1,n+1){
      G[i].clear();
      dist[i] = 0;
      parent[i] = 0;
      deg[i] = 0;
   }
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
      deg[u]++;
      deg[v]++;
   }
   set<pair<int, int>> LF;
   dfs(x,0,0);
   f(i,1,n+1){
      if(deg[i] == 1){
         if(i == x){
            cout << "Ayush\n";
            return;
         }
         LF.insert({-dist[i],i});
      }
   }
   int mv = 1;
   while(!LF.empty()){
      mv++;
      auto k = *LF.begin();
      LF.erase(k);
      int P = parent[k.second];
      deg[k.second]--;
      deg[P]--;
      if(deg[P] <= 1){
         if(P == x){
            break;
         }
         LF.insert({-dist[P],P});
      }
   }
   // debug(mv);
   if(mv & 1){
      cout << "Ayush\n";
   }else{
      cout << "Ashish\n";
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
