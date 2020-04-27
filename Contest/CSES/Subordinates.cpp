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

int sz[N];
vector<int> G[N];

void dfs(int u,int p = -1){
   sz[u] = 1;
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u);
         sz[u] += sz[v];
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   f(i,2,n+1){
      int x;
      cin >> x;
      G[x].pb(i);
   }
   dfs(1);
   f(i,1,n+1){
      cout << sz[i]-1 << ' ';
   }
   return 0;
} 