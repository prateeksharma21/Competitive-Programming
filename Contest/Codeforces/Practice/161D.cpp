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
const int MOD = 1e9+7, N = 5e4 + 10; 

int n,k;
int dp[N][502];
vector<int> G[N];

int dfs(int u,int p = -1){
   int ans = 0;
   dp[u][0] = 1;
   for(auto &v : G[u]){
      if(v!=p){
         ans += dfs(v,u);
         f(j,0,k) ans += dp[v][j]*dp[u][k-1-j];
         f(j,0,k) dp[u][j+1] += dp[v][j];
      }
   }
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k;
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   cout << dfs(1) << '\n';
   return 0;
} 