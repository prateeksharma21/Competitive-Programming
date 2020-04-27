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
int mxd,nd;

void dfs(int u,int p = -1,int d = 0){
   if(d>mxd){
      mxd = d;
      nd = u;
   }
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u,d+1);
      }
   }
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   int u,v;
   f(i,1,n){
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   dfs(1);
   dfs(nd);
   cout << mxd << '\n';
   return 0;
} 